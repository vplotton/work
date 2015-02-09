/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zappy_graph.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/27 02:29:46 by jbernabe          #+#    #+#             */
/*   Updated: 2014/06/27 03:11:46 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZAPPY_GRAPH_H
# define ZAPPY_GRAPH_H

# include <errno.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "SDL-1.2.15/include/SDL.h"
# include <dirent.h>
# include <fcntl.h>
# include <sys/mman.h>
# include <sys/stat.h>
# include <sys/time.h>

# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>

# define UP			-1
# define LEFT		-1
# define DOWN		1
# define RIGHT		1
# define TRUE		1
# define FALSE		0
# define WIDTH		5
# define HEIGHT		5
# define D_WIDTH	env->m_width * 50 + 400
# define D_HEIGHT	env->m_height * 50 + 200
# define PLAYERS	7
# define RICHNESS	2
# define RANDOMNESS	4
# define MAX_RSRC	(WIDTH * HEIGHT * 2)
# define MAX_PLAYER	200
# define P(X)		player->pos.X
# define V(X)		player->ivec.X
# define PI			3.141592654
# define HGROUND    50
# define WGROUND    50
# define NBCMD      17

/*
**	IA DEFINES
*/

# define N_TEST		10
# define N_UNITS	4
# define N_HIDDEN	2
# define N_OUTPUT	3
# define MAX_TURN	100

/*
**	TROLL DEFINES
*/

typedef char			t_bool;
typedef struct s_parse	t_parse;
typedef struct s_anim	t_anim;

typedef	struct			s_point
{
	int					x;
	int					y;
	int					z;
}						t_point;

typedef struct			s_ipos
{
	int					x;
	int					y;
}						t_ipos;

typedef struct			s_dpos
{
	double				x;
	double				y;
}						t_dpos;

typedef struct			s_map
{
	int					nb_pl;
	int					rsrc[7];
	t_bool				ids[MAX_PLAYER];
}						t_map;

typedef struct			s_player
{
	t_bool				used;
	char				*team;
	int					team_id;
	int					id;
	int					lvl;
	t_ipos				pos;
	t_ipos				display_pos;
	t_ipos				ivec;
	t_dpos				dvec;
	int					rsrc[7];
	int					anim[7];
	t_bool				cur_anim;
	int					img_frame;
	unsigned int		str_anim;
	t_bool				dead;
}						t_player;

typedef struct			s_display
{
	SDL_Surface			*windows;
	SDL_Surface			*ground;
	SDL_Rect			*g_pos;
	SDL_Rect			*dec_pos;
	SDL_Surface			*px;
	SDL_Surface			*d_rsc;
	SDL_Rect			camera;
	SDL_Surface			*level;
	SDL_Rect			cam_pos;
	int					mv_cam;
	int					cam_max;
	SDL_Surface			*backg;
	SDL_Surface			*charact;
	SDL_Surface			*anim_event;
	int					cam_min_x;
	int					cam_max_x;
	int					cam_min_y;
	int					cam_max_y;
	SDL_Surface			**rsc;
	SDL_Surface			*pl_img;
	t_bool				anim;
}						t_display;

typedef struct			s_sprite
{
	SDL_Surface			*image;
	SDL_Rect			src;
	SDL_Rect			dst;
	int					time;
	int					crt_anim;
	int					total_anim;
	int					vector;
	int					crt_time;
	int					total_time;
	int					width;
	int					height;
}						t_sprite;

typedef struct			s_team
{
	char				*name;
	int					nb_ply;
	int					empty_slot;
	int					trsc[7];
	int					lvl[8];
	int					id;
}						t_team;

typedef struct			s_interface
{
	t_team				*team;
	SDL_Surface			*d_itf;
	SDL_Surface			**num;
	SDL_Surface			*line;
}						t_interface;

typedef struct			s_env
{
	int					nb;
	int					max_pl;
	int					t_nb;
	int					t[255];
	t_map				**map;
	t_player			*pl;
	t_display			*display;
	t_interface			*itf;
	int					m_width;
	int					m_height;
	t_parse				*parse;
	t_anim				*anim;
	char				*hostname;
	int					s_sock;
	int					sock;
	int					cs;
	struct sockaddr_in	csin;
	struct sockaddr_in	sin;
	struct protoent		*proto;
	int					port;
}						t_env;

struct					s_parse
{
	char				**cmd;
	void				(*f[24])(char *buffer, t_env *env);
};

struct					s_anim
{
	int					cmd;
	char				**msg_name;
	void				(*ft[6])(int id, t_env *env, int j);
};

typedef struct			s_rsrc
{
	int					val;
	char				name[10];
}						t_rsrc;

enum					e_enum
{
	FOOD,
	SIBUR,
	PHIRAS,
	LINEMATE,
	MENDIANE,
	THYSTAME,
	DERAUMERE
};

/*
**	DISPLAY
*/

t_bool					ft_recv_loop(t_env *env, int size);
t_bool					ft_recv(t_env *env, int size);
t_bool					ft_send(int s_sock, char *msg, t_env *env);
void					ft_draw_grid(t_env *env);
void					ft_draw_pixel(int x, int y, t_env *env);
int						ft_init_video(t_env *env);
void					ft_draw_pixel(int x, int y, t_env *env);
void					ft_anim_player(t_env *env, t_sprite sprite);
void					ft_interface(t_env *env);
void					free_surface(SDL_Surface **img, int img_len);
t_point					convert(int x, int y, int z);
void					scan_map(t_env *env, t_bool pl, t_bool rsc);
SDL_Surface				**ft_init_flower(SDL_Surface **flower);
void					ft_t_nb(t_env *env);

/*
**	ground and env
*/

int						ft_load_ground(t_env *env);
int						ft_display_ground(t_env *env);
void					t_draw(t_env *env);
void					check_player(t_env *env, int x, int y,
						SDL_Surface *img);
void					check_rsc(t_env *env, int x, int y);
SDL_Surface				**ft_init_flower(SDL_Surface **flower);
int						ft_display_background(t_env *env);
void					ft_init_ressource_img(t_env **env);
SDL_Rect				ft_pos_player(t_env *env, int x, int y);
SDL_Surface				**init_texture(SDL_Surface **decor);
void					put_decor(SDL_Surface **decor, t_env *env);

/*
**	camera
*/

void					ft_move_cam_down(t_env *env);
void					ft_move_cam_up(t_env *env);
void					ft_make_level(t_env *env);
void					refresh_ground(t_env *env);
void					ft_move_cam_r(t_env *env);
void					ft_move_cam_l(t_env *env);

/*
**	cmd
*/

void					ft_recv_map(t_env *env);
void					ft_init_cmd(t_env *env);
void					ft_welcome(char *buffer, t_env *env);
void					ft_get_map(char *buffer, t_env *env);
void					ft_get_cmd(char *buffer, t_env *env);
void					ft_map_rscr(char *buffer, t_env *env);
void					ft_get_team_name(char *buffer, t_env *env);
void					ft_new_player(char *buffer, t_env *env);
void					ft_change_player_pos(char *buffer, t_env *env);
void					ft_change_player_level(char *buffer, t_env *env);
void					ft_change_inventory(char *buffer, t_env *env);
void					ft_expulse(char *buffer, t_env *env);
void					ft_broadcast(char *buffer, t_env *env);
void					ft_incant(char *buffer, t_env *env);
void					ft_incant_end(char *buffer, t_env *env);
void					ft_egg(char *buffer, t_env *env);
void					ft_drop_rscr(char *buffer, t_env *env);
void					ft_get_rscr(char *buffer, t_env *env);
void					ft_player_die(char *buffer, t_env *env);
void					ft_egg_is_ok(char *buffer, t_env *env);
void					ft_egg_is_dead(char *buffer, t_env *env);
void					ft_egg_go(char *buffer, t_env *env);
void					ft_connect_for_egg(char *buffer, t_env *env);
void					ft_egg_is_starving(char *buffer, t_env *env);
int						randoms(int imin, int imax);
void					ft_get_tna(t_env *env);

/*
**	animation
*/

void					ft_check_anim(t_env *env);
void					ft_msg_anim(int id, t_env *env, int j);
void					ft_move_player(t_env *env, int id);
void					ft_load_ft_anim(t_env *env);
void					ft_load_anim_name(t_env *env);

/*
**	Interface
*/

void					ft_load_numbers(t_env **env);
void					ft_pause(t_env *env);
void					ft_init_itf(t_env *env);
void					ft_check_anim(t_env *env);
void					ft_msg_anim(int id, t_env *env, int j);
int						ft_fade_out(SDL_Surface *lvl_up, t_player *player);
void					ft_move_player(t_env *env, int id);
void					ft_load_ft_anim(t_env *env);
void					ft_load_anim_name(t_env *env);

/*
**	MOVE FUNCTIONS
*/

void					rotate(t_bool side, t_player *player);
void					translate(t_bool side, t_player *player, t_env **env);

/*
**	INIT FUNCTIONS
*/

int						create_client(char *addr, t_env *env);
t_bool					set_rsrc(int rsrc);
t_bool					init(t_env **env);
t_bool					init_map(t_env **env);
t_bool					init_player(t_env **env);

/*
**	DETECT FUNCTIONS
*/

int						detect(int rsrc, t_env *env, t_player *player);
double					detect_sq(int rsrc, t_env *env, t_player *player);
double					detect_max_sq(int rsrc, int *max, t_env *env,
						t_player *player);

/*
**	ACTION FUNCTIONS
*/

t_bool					send_broadcast(t_player *player, t_env *env, char *msg);
t_bool					drop_rsrc(int rsrc, t_player *player, t_env **env);
t_bool					get_rsrc(int rsrc, t_player *player, t_env *env);
t_bool					live(t_env **env, t_player *player,
						double out[N_OUTPUT]);
t_bool					see(t_player *player, t_env *env);
t_bool					inventory(t_player *player);

/*
**	MATH FUNCTIONS
*/

double					dot_prod(t_ipos vec1, t_dpos vec2);
double					get_dst(t_ipos p1, t_ipos p2);
t_dpos					get_vec(t_ipos p1, t_ipos p2);

/*
**	__DEBUG FUNCTIONS
*/

void					check_pl_vision(int pl, t_player *player, t_env *env);
void					check_pl_pos(t_player *player);
void					check_rsrc_map(t_env *env);
#endif
