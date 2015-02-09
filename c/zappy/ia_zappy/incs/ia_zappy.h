/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia_zappy.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 14:43:55 by vplotton          #+#    #+#             */
/*   Updated: 2014/06/09 21:18:55 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IA_ZAPPY_H
# define IA_ZAPPY_H

# include "ia_mlp.h"

# ifdef __gnu_linux__
#  include "libft.h"
# else
#  include <libft.h>
# endif

# include <errno.h>
# include <stdlib.h>
# include <math.h>
# include <time.h>

# include <stdio.h>

# define ALL		8
# define UP			-1
# define LEFT		-1
# define DOWN		1
# define RIGHT		1
# define TRUE		1
# define FALSE		0
# define WIDTH		24
# define HEIGHT		24
# define PLAYERS	7
# define RICHNESS	8
# define RANDOMNESS	4
# define MAX_RSRC	(WIDTH * HEIGHT * 2)
# define MAX_PLAYER	(WIDTH * HEIGHT / 2)
# define V(X)		player->ivec.X
# define P(X)		player->pos.X
# define PI			3.141592654

/*
**	DEFINE MLP
*/
# define MAX_TURN	100
# define N_TEST		100
# define N_NET		500
# define N_IN		9
# define N_OUT		3
# define N_HID		2

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
	char		team;
	int			fd;
	int			id;
	int			lvl;
	t_ipos		pos;
	t_ipos		ivec;
	t_dpos		dvec;
	int			rsrc[7];
}				t_player;

typedef struct	s_env
{
	int			nb;
	int			t_nb;
	int			t[255];
	t_map		**map;
	t_player	*pl;
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
**	NEURAL NETWORK
*/
t_bool			process_ia(t_env *env, t_player *player);

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
t_bool			reset_map(t_env **env);
t_bool			init_player(t_player *player, t_env **env);

/*
**	DETECT FUNCTIONS
*/
int				detect(int rsrc, t_env *env, t_player *player);
double			detect_sq(int rsrc, t_env *env, t_player *player);
double			detect_rtv_sq(int rtv, int rsrc, t_env *env, t_player *player);
double			detect_max_sq(int rsrc, int *max, t_env *env, t_player *player);

/*
**	ACTION FUNCTIONS
*/
t_bool			send_broadcast(t_player *player, t_env *env, char *msg);
t_bool			drop_rsrc(int rsrc, t_player *player, t_env **env);
t_bool			get_rsrc(int rsrc, t_player *player, t_env **env);
t_bool			live(t_env **env, t_player *player, t_layer layer, t_bool opt);
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
