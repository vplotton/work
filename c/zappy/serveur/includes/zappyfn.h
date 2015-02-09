/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zappyfn.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 04:47:43 by obengelo          #+#    #+#             */
/*   Updated: 2014/06/26 20:44:38 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZAPPYFN_H
# define ZAPPYFN_H

# include <errno.h>
# include <libft.h>
# include <stdlib.h>
# include <time.h>
# include <math.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <netinet/ip.h>
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
# define RICHNESS	2
# define RANDOMNESS	4
# define MAX_RSRC	(WIDTH * HEIGHT * 2)
# define MAX_PLAYER	(WIDTH * HEIGHT / 2)
# define P(X)		(*player)->pos.X
# define PL(X)		env->pl[fd]->pos.X
# define V(X)		(*player)->ivec.X
# define AC			6
# define NBCMD		10
# define PI			3.141592654
# define X			((*env)->world->mapx
# define RANX		rand() % env->world->mapx
# define SOKTFL		env->stream_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&on,
# define BINDFL		env->stream_socket, (struct sockaddr *)&(env->addr),
# define IFEXP		env->pl[i]->pos.x == env->pl[fd]->pos.x &&
# define DETCX		pos.x < 0 ? pos.x + env->world->mapx
# define DETCY		pos.y < 0 ? pos.y + env->world->mapy
# define SELCFL		&(env->working_in), &(env->working_out), NULL
# define TIMEMICRO	(end.tv_sec * 1000000 + end.tv_usec)
# define NB_PTR		13
# define COMAND_D	"avance|droite|gauche|voir|inventaire|prend "
# define COMAND_E	"|pose |expulse|broadcast |incantation|fork|connect_nbr"

typedef char				t_bool;

typedef struct				s_ipos
{
	int						x;
	int						y;
}							t_ipos;

typedef struct				s_dpos
{
	double					x;
	double					y;
}							t_dpos;

typedef struct				s_map
{
	int						nb_pl;
	int						rsrc[7];
	t_bool					ids[MAX_PLAYER];
}							t_map;

typedef struct				s_player
{
	char					*team;
	int						lvl;
	int						live;
	t_ipos					pos;
	t_ipos					ivec;
	t_dpos					dvec;
	int						fd;
	int						rsrc[7];
	int						queu_request;
}							t_player;

typedef struct s_arg		t_arg;
typedef struct s_arguments	t_arguments;

struct						s_arg
{
	char					name[2];
	t_arguments				*(*fct)(t_arguments *e, char **av, int *i);
};

struct						s_arguments
{
	int						port;
	int						mapx;
	int						mapy;
	char					**teams;
	int						player_max;
	int						t_time;
	double					t_time_m;
	int						flag;
	t_arg					args[AC];
};

typedef struct s_to_send	t_to_send;

struct						s_to_send
{
	char					*message;
	int						fd;
	double					time_to_send;
	t_to_send				*next;
};

typedef struct s_to_do		t_to_do;

struct						s_to_do
{
	int						action;
	int						player;
	double					time_to_do;
	int						x;
	int						y;
	t_to_do					*next;
};

typedef struct s_eggs		t_eggs;

struct						s_eggs
{
	int						egg_nb;
	int						team;
	double					time;
	int						x;
	int						y;
	int						fdpl;
	t_eggs					*next;
};

typedef struct s_env		t_env;
typedef struct				s_parse
{
	char					**cmd;
	void					(*f[24])(char *buffer, t_env *env, int fd);
}							t_parse;

typedef struct s_graphic	t_graphic;

struct						s_graphic
{
	int						fd;
	t_graphic				*next;
};

typedef struct s_new_user	t_new_user;

struct						s_new_user
{
	int						fd;
	t_new_user				*next;
};

typedef struct sockaddr_in	t_addr_in;
typedef struct fd_set		t_fd_st;
typedef struct timeval		t_timeval;

struct						s_env
{
	int						stream_socket;
	t_addr_in				addr;
	t_fd_st					master;
	t_fd_st					working_in;
	t_fd_st					working_out;
	int						fd_max;
	int						*max_conections;
	int						*conections;
	t_map					**map;
	t_player				**pl;
	t_arguments				*world;
	t_timeval				timeout;
	double					what_time_is_it;
	t_to_send				*message_queu;
	void					(*handelers[NB_PTR])(t_env *, char *, int);
	void					(*to_do[NB_PTR])(t_env *, t_to_do *);
	t_graphic				*graphic;
	char					*msg;
	t_parse					*parse;
	t_eggs					*egg;
	t_to_do					*todo;
	t_new_user				*new_users;
};

typedef struct				s_rsrc
{
	int						val;
	char					name[10];
}							t_rsrc;

enum						e_enum
{
	FOOD
	, SIBUR
	, PHIRAS
	, LINEMATE
	, MENDIANE
	, THYSTAME
	, DERAUMERE
};

#endif
