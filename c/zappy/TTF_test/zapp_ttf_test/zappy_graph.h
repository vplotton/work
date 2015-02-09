/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia_zappy.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 14:43:55 by vplotton          #+#    #+#             */
/*   Updated: 2014/06/08 20:43:36 by jbernabe         ###   ########.fr       */
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
//# include <SDL.h>
# include <stdio.h>
# include <unistd.h>
# include "SDL-1.2.15/include/SDL.h"
//# include <SDL_ttf.h>

# define ALL		8
# define UP			-1
# define LEFT		-1
# define DOWN		1
# define RIGHT		1
# define TRUE		1
# define FALSE		0
# define WIDTH		12
# define HEIGHT		12
# define D_WIDTH	50 * WIDTH
# define D_HEIGHT	50 * HEIGHT
# define PLAYERS	7
# define RICHNESS	2
# define RANDOMNESS	4
# define MAX_RSRC	(WIDTH * HEIGHT * 2)
# define MAX_PLAYER	(WIDTH * HEIGHT / 2)
# define P(X)		player->pos.X
# define V(X)		player->ivec.X
# define PI			3.141592654
# define HGROUND    50
# define WGROUND    50

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

typedef char	t_bool;

typedef struct	s_ipos
{
	int			x;
	int			y;
}				t_ipos;

typedef struct	s_dpos
{
	double		x;
	double		y;
}				t_dpos;

typedef struct	s_map
{
	int			nb_pl;
	int			rsrc[7];
	t_bool		ids[MAX_PLAYER];
}				t_map;

typedef struct	s_player
{
	t_bool		jesus;
	t_bool		blind;
	t_bool		used;
	char		*team;
	int         team_id;
	int			fd;
	int			id;
	int			lvl;
	t_ipos		pos;
	t_ipos		ivec;
	t_dpos		dvec;
	int			rsrc[7];
}				t_player;

typedef struct   s_display
{
    SDL_Surface *windows;
    SDL_Surface *ground;
    SDL_Rect    *g_pos;
}               t_display;

typedef    struct     s_sprite
{
    SDL_Surface *image;
	SDL_Rect    src;
	SDL_Rect    dst;
	int         time;
	int         crt_anim;
	int         total_anim;
	int         vector;
	int         crt_time;
	int         total_time;
	int         width;
    int         height;

}               t_sprite;

typedef struct   s_team
{
   char         *name;
   int          nb_ply;
   int          empty_slot;
   int          *trsc;
   int          *lvl;
}               t_team;

typedef struct  s_interface
{
    t_team      *team;
}               t_interface;

typedef struct	s_env
{
	int			nb;
	int			t_nb;
	int			t[255];
	t_map		**map;
	t_player	*pl;
    t_display   *display;
    t_interface *itf;
}				t_env;

typedef struct	s_rsrc
{
	int			val;
	char		name[10];
}				t_rsrc;

enum	e_enum
{
	FOOD
	, SIBUR
	, PHIRAS
	, LINEMATE
	, MENDIANE
	, THYSTAME
	, DERAUMERE
};
/*
**      DISPLAY
*/
int     ft_init_video(t_env *env);
int     ft_load_ground(t_env *env);
int     ft_display_ground(t_env *env);
void    ft_anim_player(t_env *env, t_sprite sprite);
void    ft_interface(t_env  *env);

/*
**	NEURAL NETWORK
*/
t_bool	process_ia(t_env *env, t_player *player);

/*
**	MOVE FUNCTIONS
*/
void			rotate(t_bool side, t_player *player);
void			translate(t_bool side, t_player *player, t_env **env);

/*
**	INIT FUNCTIONS
*/
t_bool			set_rsrc(int rsrc);
t_bool			init(t_env **env);
t_bool			init_map(t_env **env);
t_bool			init_player(t_player *player, t_env **env);

/*
**	DETECT FUNCTIONS
*/
int				detect(int rsrc, t_env *env, t_player *player);
double			detect_sq(int rsrc, t_env *env, t_player *player);
double			detect_max_sq(int rsrc, int *max, t_env *env, t_player *player);

/*
**	ACTION FUNCTIONS
*/
t_bool			send_broadcast(t_player *player, t_env *env, char *msg);
t_bool			drop_rsrc(int rsrc, t_player *player, t_env **env);
t_bool			get_rsrc(int rsrc, t_player *player, t_env *env);
t_bool			live(t_env **env, t_player *player, double out[N_OUTPUT]);
t_bool			see(t_player *player, t_env *env);
t_bool			inventory(t_player *player);

/*
**	MATH FUNCTIONS
*/
double			dot_prod(t_ipos vec1, t_dpos vec2);
double			get_dst(t_ipos p1, t_ipos p2);
t_dpos			get_vec(t_ipos p1, t_ipos p2);

/*
**	__DEBUG FUNCTIONS
*/
void			check_pl_vision(int pl, t_player *player, t_env *env);
void			check_pl_pos(t_player *player);
void			check_rsrc_map(t_env *env);

#endif
