/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/31 16:16:39 by vplotton          #+#    #+#             */
/*   Updated: 2014/06/26 19:51:55 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"client.h"

t_ipos		detect_sq(int rsrc, t_player *player)
{
	t_ipos	m;
	t_ipos	pos;

	m.x = -1;
	while (++m.x < player->lvl + 1)
	{
		m.y = -m.x - 1;
		while (++m.y < m.x + 1)
		{
			pos.x = player->pos.x + m.x * player->ivec.x;
			pos.y = player->pos.y + m.y * player->ivec.y;
			pos.x = (pos.x < 0 ? pos.x + WIDTH : pos.x % WIDTH);
			pos.y = (pos.y < 0 ? pos.y + HEIGHT : pos.y % HEIGHT);
			if (rsrc < 7 && player->map[pos.y][pos.x].rsrc[rsrc])
				return (m);
			else if (rsrc == PLAYER && player->map[pos.y][pos.x].nb_pl > 0)
				return (m);
		}
	}
	m.x = -1;
	m.y = -1;
	return (m);
}

int			detect_rtv_sq(int rtv, int rsrc, t_player *player)
{
	t_ipos	m;
	t_ipos	pos;

	m.x = -1;
	while (++m.x < player->lvl + 1)
	{
		m.y = -m.x - 1;
		while (++m.y < m.x + 1)
		{
			pos.x = player->pos.x + m.x * player->ivec.x;
			pos.y = player->pos.y + m.y * player->ivec.y;
			pos.x = (pos.x < 0 ? pos.x + WIDTH : pos.x % WIDTH);
			pos.y = (pos.y < 0 ? pos.y + HEIGHT : pos.y % HEIGHT);
			if (!rtv)
				return (player->map[pos.y][pos.x].rsrc[rsrc]);
			rtv--;
		}
	}
	return (0);
}
