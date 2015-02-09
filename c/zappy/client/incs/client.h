/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 21:17:18 by vplotton          #+#    #+#             */
/*   Updated: 2014/06/26 20:07:01 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <libft.h>
# include <stdio.h>
# include <time.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <fcntl.h>
# include <sys/mman.h>
# include <sys/stat.h>
# include <sys/time.h>

# define AC			3
# define D_UP		-1
# define D_LEFT		-1
# define D_DOWN		1
# define D_RIGHT	1
# define END		2
# define TRUE		1
# define FALSE		0
# define V(X)		player->ivec.X
# define P(X)		player->pos.X
# define HEIGHT		player->size.y
# define WIDTH		player->size.x

typedef char		t_bool;

typedef struct s_param	t_param;

typedef struct			s_arg
{
	char				name[4];
	t_param				*(*fct)(t_param *e, char **av, int *i);
}						t_arg;

struct					s_param
{
	int					mapx;
	int					mapy;
	char				*team;
	int					port;
	char				*hostname;
	int					flag;
	t_arg				args[AC];
	int					sock;
	int					cs;
	struct sockaddr_in	csin;
	int					r;
	char				buf[1024];
	struct sockaddr_in	sin;
	int					nb_client;
	struct protoent		*proto;
};

typedef struct			s_ipos
{
	int					x;
	int					y;
}						t_ipos;

typedef struct			s_rsrc
{
	int					val;
	char				name[10];
}						t_rsrc;

typedef struct			s_map
{
	int					nb_pl;
	int					rsrc[7];
}						t_map;

typedef struct			s_cmd
{
	int					id;
	int					rsrc;
	char				*add;
}						t_cmd;

typedef struct			s_cmds
{
	t_bool				need_c;
	int					nb_cmd;
	t_cmd				order[10];
}						t_cmds;

typedef struct			s_player
{
	int					id;
	int					lvl;
	int					type;
	int					nb_pl;
	t_ipos				pos;
	t_ipos				size;
	t_ipos				ivec;
	int					rsrc[7];
	char				*msg;
	t_map				**map;
	t_bool				(*ft_recv[12])();
}						t_player;

typedef struct			s_env
{
	int					s_sock;
	int					fd_max;
	char				*hostname;
	fd_set				fd_r;
	fd_set				fd_w;
	struct timeval		t;
	t_param				*e;
}						t_env;

enum					e_rsrc
{
	FOOD
	, SIBUR
	, PHIRAS
	, LINEMATE
	, MENDIANE
	, THYSTAME
	, DERAUMERE
	, PLAYER
};

enum					e_action
{
	ADV
	, LEFT
	, RIGHT
	, SEE
	, FORK
	, INCNT
	, EXPLS
	, INVTRY
	, CNCT_NBR
	, GET
	, DROP
	, BRDCST
};

enum					e_brdcst
{
	MST_POS
	, POS
	, INFO_PL
};

enum					e_pl_type
{
	MASTER
	, FOLLOWER
	, ENHANCED
};

/*
**	INIT CLIENT
*/
t_bool					init_env(t_env **env, t_param *e, int s_sock);
t_bool					init_player(t_player *player, int x, int y);
t_param					*ft_parse_args(char **av);
void					ft_puterror(char *msg);
t_param					*get_hostname(t_param *e, char **av, int *i);
t_param					*get_team(t_param *e, char **av, int *i);
t_param					*get_port(t_param *e, char **av, int *i);
t_param					*get_info(char **av, int *i, t_param *param);
int						create_client(char *addr, t_param *e);

/*
**	SEND FUNCTIONS
*/
t_bool					ft_send(int s_sock, t_cmd *cmd);

/*
**	RECV FUNCTIONS
*/
t_bool					ft_recv(t_env *env, t_player *player, t_cmd cmd);
t_bool					ft_recv_see(t_player *player, char *r_msg);
t_bool					ft_recv_fork(t_env *env, t_player *player, char *r_msg);
t_bool					ft_recv_expls(t_player *player, char *r_msg);
t_bool					ft_recv_incnt(t_player *player, char *r_msg);
t_bool					ft_recv_invtry(t_player *player, char *r_msg);
t_bool					ft_recv_brdcst(t_player *player, char *r_msg);
t_bool					ft_recv_cnctnbr(t_player *player, char *r_msg);
t_bool					ft_recv_gd(t_player *pl, char *msg, int rsrc, int cmd);

/*
**	FORK
*/
t_bool					ft_fork(t_env *env);

/*
**	MOVE
*/
t_bool					translate(t_player *player, int side);
t_bool					rotate(t_player *player, int side);

/*
**	HANDLE BROADCAST
*/
t_bool					msg_info_pl(t_player *player, t_cmd *cmd);
char					*msg_header(t_player *player, int msg_type);
char					**get_broadcast(int *pos, char **msg);

/*
**	HANDLE CMD
*/
void					add_cmd(t_cmds **cmds, t_cmd new, int mod);
void					reorder_cmd(t_cmds **cmds);
void					modify_cmd(int id, int rsrc, char *add, t_cmds **cmds);

/*
**	HANDLE MAP
*/
void					update_map(char **see, t_player *player);

/*
**	LIVE
*/
t_bool					goto_rsrc(t_player *player, t_cmds **cmds, int rsrc);
t_bool					live(t_env *env, t_player *player);

/*
**	PROCESS
*/
t_bool					process_player(t_player *player, t_cmds **cmds);
t_bool					process_ia(t_env *env, t_player *player, t_cmds **cmds);
t_bool					process_master(t_env *env, t_player *pl, t_cmds **cmds);

/*
**	MASTER
*/
t_bool					brdcst_master_pos(t_player *player, t_cmds **cmds);
t_bool					seek_master(t_player *player, t_cmds **cmds);

/*
**	DETECT
*/
int						detect_rtv_sq(int rtv, int rsrc, t_player *player);
int						check_lvl_rsrc(t_player *player);
t_ipos					detect_sq(int rsrc, t_player *player);

/*
**	TOOLS
*/
void					ft_join(char **msg, char *add, int nb, t_bool opt);
int						get_rand(int mod);

#endif
