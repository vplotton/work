/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 17:32:51 by vplotton          #+#    #+#             */
/*   Updated: 2014/03/25 20:31:34 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

/*
**	INCLUDES
*/
# include <libft.h>
# include <math.h>
# include <mlx.h>
# include <fcntl.h>

/*
**	DEFINES
*/
# define COMPOUND	"( scene )|( cam )|( obj )|( lgt )"
# define V_SCN		"name:|winsz:"
# define V_CAM		"name:|coord:|radius:|d_vec:"
# define V_OBJ		"name:|coord:|radius:|color:|coeff:|d_vec:|height:|type:"
# define V_LGT		"name:|coord:|radius:|color:"
# define T_SCN		"scn"
# define T_CAM		"cam"
# define T_OBJ		"obj"
# define T_LGT		"lgt"
# define SCN		0
# define CAM		1
# define OBJ		2
# define LGT		3
# define NAME_CHARS	"qwertyuiopasdfghjklzxcvbnm_1234567890 "
# define FORM		"sphere|cylinder|plane|cone"
# define SPHERE		0
# define CYLINDER	1
# define PLANE		2
# define CONE		3
# define DATA(X, Y)	(*data)->X->Y
# define TRUE		1
# define FALSE		0
# define PITCH_X	0.5
# define PITCH_Y	0.35
# define FOCAL		-1.0
# define ERR		0.000001
/*
**		Math defines
*/
# define ABS_D(X)	(X < 0.0001 ? -X : X)
# define PI			3.141592654
# define V(X)		vec.X
# define PT(X)		(X == FALSE ? ray->inter : info.cam->data->coord)
# define ICAM(X, Y)	(Y == FALSE ? ray->inter.X : info.cam->data->coord.X)
# define O(X)		info.obj->data->coord.X
# define A			(V(x) * V(x) + V(y) * V(y) + V(z) * V(z))
# define B(X)		(V(X) * (ICAM(X, ray->mode) - O(X)))
# define B2			(B(x) + B(y) + B(z)) * (B(x) + B(y) + B(z))
# define C(X)		(ICAM(X, ray->mode) - O(X)) * (ICAM(X, ray->mode) - O(X))
# define R2			info.obj->data->radius * info.obj->data->radius
# define I2(X,Y,Z)	((inter[X].Y - ICAM(Y, Z)) * (inter[X].Y - ICAM(Y, Z)))
# define L2(X,Y)	((*intersect).X - ICAM(X, Y) * (*intersect).X - ICAM(X, Y))
# define ALPHA		(((PI / 2.0) - alpha) / (PI / 2.0))
# define VEC(X)		info.obj->data->d_vec.X
#define V_INI(X, Y)	(alpha[Y] * vec.X + ICAM(X, ray->mode))
# define INTR(X, Y)	(V_INI(X, Y) * info.obj->data->radius + O(X))

/*
**	TYPEDEF
*/
typedef char		t_bool;

typedef struct		s_posd
{
	double			x;
	double			y;
	double			z;
}					t_posd;

typedef struct		s_scn
{
	t_posd			winsz;
}					t_scn;

typedef struct		s_cam
{
	t_posd			coord;
	t_posd			d_vec;
}					t_cam;

typedef struct		s_lgt
{
	double			radius;
	t_posd			color;
	t_posd			coord;
}					t_lgt;

typedef struct		s_obj
{
	int				type;
	double			radius;
	double			height;
	t_posd			coeff;
	t_posd			color;
	t_posd			coord;
	t_posd			d_vec;
}					t_obj;

typedef struct		s_cams
{
	t_cam			*data;
	struct s_cams	*next;
	struct s_cams	*first;
}					t_cams;

typedef struct		s_objs
{
	t_obj			*data;
	struct s_objs	*next;
	struct s_objs	*first;
}					t_objs;

typedef struct      s_lgts
{
	t_lgt			*data;
	struct s_lgts	*next;
	struct s_lgts	*first;
}					t_lgts;

typedef struct		s_ray
{
	int				mode;
	double			dst;
	double			alpha;
	double			specular;
	t_posd			inter;
	t_posd			d_ray;
	t_posd			color;
	t_posd			normal;
	t_obj			*obj;
}					t_ray;

typedef struct		s_data
{
	int				type;
	char			*name;
	struct s_scn	*scn;
	struct s_cam	*cam;
	struct s_obj	*obj;
	struct s_lgt	*lgt;
	struct s_data	*first;
	struct s_data	*next;
}					t_data;

typedef struct		s_info
{
	void			*mlx_ptr;
	void			*mlx_win;
	void			*img;
	char			*d_img;
	char			*name;
	t_cams			*cam;
	t_objs			*obj;
	t_lgts			*lgt;
	t_posd			vec;
	t_posd			pitch;
	t_posd			winsz;
}					t_info;

/*
 **	FUNCTIONS
 **
 **		Check funtions
 */
double	ft_is_int(char *s);
double	ft_is_double(char *s);
t_bool	ft_check_scene(t_data *data);
t_bool	ft_first_check(int fd, int type, t_data **data);
t_bool	ft_check_posd(char *input, char *compound, t_data **data);
t_bool	ft_check_size(char *input, char *compound, t_data **data);
t_bool	ft_check_type(char *input, char *compound, t_data **data);
t_bool	ft_check_name(char *input, char *compound, t_data **data);

/*
 **		Parse functions
 */
t_bool	ft_prs_scn(int fd, int type, t_data **data);
t_bool	ft_prs_cam(int fd, int type, t_data **data);
t_bool	ft_prs_obj(int fd, int type, t_data **data);
t_bool	ft_prs_lgt(int fd, int type, t_data **data);

/*
 **		Compute functions
 */
void	ft_compute(t_info info);
void	ft_raytrace(t_ray *ray, t_posd vec, t_info info);

/*
 **		Draw functions
 */
char	*ft_get_img(t_info info);
void	ft_draw_point(t_posd color, t_info *info);

/*
 **		Get functions
 */
t_bool	ft_get_scene(t_data **data, char *scene);
void	ft_get_info(t_info *info, t_data **data);

/*
 **		Handle objects
 */
void	ft_texture(t_ray *ray, char txt_type, t_posd color1, t_posd color2);
double	ft_inter_cone(t_posd *inter, t_posd vec, t_ray *ray, t_info info);
double	ft_inter_plane(t_posd *inter, t_posd vec, t_ray *ray, t_info info);
double	ft_inter_sphere(t_posd *inter, t_posd vec, t_ray *ray, t_info info);
double	ft_inter_cylinder(t_posd *inter, t_posd vec, t_ray *ray, t_info info);

/*
 **		Math functions
 */
void	ft_norm(t_posd *vec);
double	ft_dot_prod(t_posd vec1, t_posd vec2);
double	ft_get_dst(t_posd coord1, t_posd coord2);
double	ft_get_vec(t_posd inter, t_posd lum, t_posd *vec);
t_posd	ft_cross_prod(t_posd vec1, t_posd vec2);

/*
**		Rotate functions
*/
void	ft_rotate_x(t_posd *vec, double angle);
void	ft_rotate_y(t_posd *vec, double angle);
void	ft_rotate_z(t_posd *vec, double angle);

/*
 **		Print functions
 */
t_bool	ft_print_prserror(int code, char *compound);
t_bool	ft_print_ferror(char *s, int code);

/*
 **		Read functions
 */
char	*ft_read_line(int fd);

/*
 **		Data functions
 */
void	ft_delete_data(t_data **data);
void	ft_add_data(t_data **data, int type);
void	ft_get_data(t_data **data, char *compound, char *input, t_posd posd);
t_bool	ft_check_order(t_data *data);

#endif /* RAYTRACER_H */
