/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 02:40:24 by vplotton          #+#    #+#             */
/*   Updated: 2014/06/26 20:54:14 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

extern char	g_rsrc[7][12];

static void		update_map_sq(t_ipos pos, char *ssq, t_player *player)
{
	int		i;
	int		j;
	char	**sq;

	j = 0;
	if ((sq = ft_strsplit(ssq, ' ')) == NULL)
		return ;
	while (sq[j])
	{
		i = -1;
		while (++i < 7)
		{
			if (ft_strcmp(g_rsrc[i], sq[j]) == 0)
				player->map[pos.y][pos.x].rsrc[i]++;
		}
		if (i == 7)
			player->map[pos.y][pos.x].nb_pl++;
		ft_strdel(&sq[j]);
		j++;
	}
	free(sq);
}

static void		reset_map(t_player *player)
{
	int		i;
	t_ipos	m;

	m.y = -1;
	while (++m.y < player->size.y)
	{
		m.x = -1;
		while (++m.x < player->size.x)
		{
			i = -1;
			while (++i < 7)
				player->map[m.y][m.x].rsrc[i] = 0;
			player->map[m.y][m.x].nb_pl = 0;
		}
	}
}

void			update_map(char **see, t_player *player)
{
	int		sq;
	t_ipos	m;
	t_ipos	pos;

	sq = 0;
	m.x = -1;
	reset_map(player);
	while (++m.x < player->lvl + 1)
	{
		m.y = -m.x - 1;
		while (++m.y < m.x + 1)
		{
			pos.x = player->pos.x + m.x * player->ivec.x;
			pos.y = player->pos.y + m.y * player->ivec.y;
			pos.x = (pos.x < 0 ? pos.x + WIDTH : pos.x % WIDTH);
			pos.y = (pos.y < 0 ? pos.y + HEIGHT : pos.y % HEIGHT);
			update_map_sq(pos, see[sq], player);
			ft_strdel(&see[sq]);
			sq++;
		}
	}
}

t_bool			ft_recv_see(t_player *player, char *r_msg)
{
	char	**see;

	see = NULL;
	if (r_msg[0] == '{')
	{
		r_msg = ft_strsub(r_msg, 1, ft_strlen(r_msg) - 3);
		if (r_msg)
		{
			see = ft_strsplit(r_msg, ',');
			ft_strdel(&r_msg);
			if (see)
			{
				update_map(see, player);
				free(see);
			}
		}
	}
	return (TRUE);
}
