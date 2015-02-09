/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_world.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obengelo <obengelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 07:48:05 by sbres             #+#    #+#             */
/*   Updated: 2014/06/26 16:22:26 by obengelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

static t_bool	set_rsrc(int rsrc)
{
	int			tab[7];
	static int	val = 1;

	tab[FOOD] = 25;
	tab[SIBUR] = 25;
	tab[PHIRAS] = 15;
	tab[LINEMATE] = 23;
	tab[MENDIANE] = 13;
	tab[THYSTAME] = 3;
	tab[DERAUMERE] = 20;
	srand(val * time(NULL));
	val = rand();
	if (val % (100 * RANDOMNESS) < tab[rsrc] * RICHNESS)
		return (TRUE);
	return (FALSE);
}

static t_bool	init_mem(t_env **env, int y)
{
	(*env)->map[y] = (t_map *)ft_memalloc(sizeof(t_map) * X + 1));
	if ((*env)->map[y] == NULL)
		return (FALSE);
	return (TRUE);
}

static void		init_rsrc(t_env **env, int turn, t_ipos m)
{
	int		i;

	i = -1;
	while (++i < 8)
	{
		if (!turn)
			(*env)->map[m.y][m.x].rsrc[i] = 0;
		if (set_rsrc(i) == TRUE)
			(*env)->map[m.y][m.x].rsrc[i]++;
	}
}

t_bool			init_map(t_env **env)
{
	int		turn;
	t_ipos	m;

	turn = -1;
	(*env)->map = (t_map **)ft_memalloc(sizeof(t_map *) *
		((*env)->world->mapy + 1));
	if ((*env)->map == NULL)
		return (FALSE);
	while (++turn < RANDOMNESS)
	{
		m.y = -1;
		while (++m.y < (*env)->world->mapy)
		{
			m.x = -1;
			if (!turn && init_mem(env, m.y) == FALSE)
				return (FALSE);
			while (++m.x < (*env)->world->mapx)
				init_rsrc(env, turn, m);
		}
	}
	return (TRUE);
}
