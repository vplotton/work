/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 03:13:02 by vplotton          #+#    #+#             */
/*   Updated: 2014/06/26 00:14:07 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"client.h"

static void	init_pl_ft(t_player *player)
{
	player->ft_recv[0] = translate;
	player->ft_recv[1] = rotate;
	player->ft_recv[2] = rotate;
	player->ft_recv[3] = ft_recv_see;
	player->ft_recv[4] = ft_recv_fork;
	player->ft_recv[5] = ft_recv_incnt;
	player->ft_recv[6] = ft_recv_expls;
	player->ft_recv[7] = ft_recv_invtry;
	player->ft_recv[8] = ft_recv_cnctnbr;
	player->ft_recv[9] = ft_recv_gd;
	player->ft_recv[10] = ft_recv_gd;
	player->ft_recv[11] = ft_recv_brdcst;
}

t_bool		init_player(t_player *player, int x, int y)
{
	int			i;
	static int	id;

	i = -1;
	if (x == 0 || y == 0)
		return (FALSE);
	player->id = id;
	player->lvl = 1;
	player->pos.x = 0;
	player->pos.y = 0;
	player->ivec.x = 1;
	player->ivec.y = 0;
	player->size.x = x;
	player->size.y = y;
	player->map = (t_map **)ft_memalloc(y * sizeof(t_map*));
	while (++i < y)
		player->map[i] = (t_map *)ft_memalloc(x * sizeof(t_map));
	player->type = (id == 0 ? MASTER : FOLLOWER);
	i = 0;
	player->rsrc[FOOD] = 10;
	while (++i < 7)
		player->rsrc[i] = 0;
	init_pl_ft(player);
	id++;
	return (TRUE);
}

t_bool		init_env(t_env **env, t_param *e, int s_sock)
{
	struct rlimit	rlp;

	if ((*env = ft_memalloc(sizeof(t_env))) == NULL)
		return (FALSE);
	getrlimit(RLIMIT_NOFILE, &rlp);
	(*env)->fd_max = rlp.rlim_cur;
	(*env)->s_sock = s_sock;
	(*env)->t.tv_sec = 0;
	(*env)->t.tv_usec = 100;
	(*env)->hostname = e->hostname;
	(*env)->e = e;
	return (TRUE);
}
