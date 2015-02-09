/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __debug.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 22:50:26 by vplotton          #+#    #+#             */
/*   Updated: 2014/06/04 15:39:05 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ia_zappy.h"

extern t_rsrc	g_rsrc[7];

void	check_pl_pos(t_player *player)
{
	printf("pos (%d|%d) -- vec (%d|%d)\n"
			, player->pos.x, player->pos.y
			, player->ivec.x, player->ivec.y);
}

void	check_pl_vision(int pl, t_player *player, t_env *env)
{
	int		i;

	i = -1;
	if (pl == TRUE)
		printf("%s : %d\n", g_rsrc[i].name, detect(i, env, player));
	else
	{
		while (++i < 7)
			printf("%s : %d\n", g_rsrc[i].name, detect(i, env, player));
	}

}

void    check_rsrc_map(t_env *env)
{
	int     i;
	t_ipos  m;
	int     rsrc[8];

	m.y = -1;
	i = -1;
	while (++i < 8)
		rsrc[i] = 0;
	while (++m.y < HEIGHT)
	{
		m.x = -1;
		while (++m.x < WIDTH)
		{
			i = -1;
			while (++i < 7)
				rsrc[i] += env->map[m.y][m.x].rsrc[i];
		}
	}
	printf("\n===  MAP RESSOURCES  ===\n");
	i = -1;
	while (++i < 7)
	{
		printf("rsrc: %s -- %d\n", g_rsrc[i].name, rsrc[i]);
		if (i)
			rsrc[7] += rsrc[i];
	}
	printf("[ total: %d ]\n", rsrc[7]);
	printf(" -- percentage:\n");
	i = 0;
	while (++i < 7)
		printf("rsrc: %s -- %f\n", g_rsrc[i].name
				, ((double)rsrc[i] / (double)rsrc[7]) * 100);
}
