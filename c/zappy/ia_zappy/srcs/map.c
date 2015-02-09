/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 18:16:33 by vplotton          #+#    #+#             */
/*   Updated: 2014/06/09 15:52:34 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ia_zappy.h"

static t_bool	init_mem(t_env **env, int y)
{
	(*env)->map[y] = (t_map *)ft_memalloc(sizeof(t_map) * (WIDTH + 1));
	if ((*env)->map[y] == NULL)
		return (FALSE);
	return (TRUE);
}

static void		init_rsrc(t_env **env, int turn, t_ipos m)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		if (!turn)
			(*env)->map[m.y][m.x].rsrc[i] = 0;
		if (set_rsrc(i) == TRUE)
			(*env)->map[m.y][m.x].rsrc[i]++;
		i++;
	}
}

t_bool			init_map(t_env **env)
{
	int		turn;
	t_ipos	m;

	turn = -1;
	(*env)->map = (t_map **)ft_memalloc(sizeof(t_map *) * (HEIGHT + 1));
	if ((*env)->map == NULL)
		return (FALSE);
	while (++turn < RANDOMNESS)
	{
		m.y = -1;
		while (++m.y < HEIGHT)
		{
			m.x = -1;
			if (!turn && init_mem(env, m.y) == FALSE)
				return (FALSE);
			while (++m.x < WIDTH)
				init_rsrc(env, turn, m);
		}
	}
	return (TRUE);
}

t_bool			reset_map(t_env **env)
{
	int		turn;
	t_ipos	m;

	turn = 0;
	while (turn < RANDOMNESS)
	{
		m.y = 0;
		while (m.y < HEIGHT)
		{
			m.x = 0;
			if (!turn)
				ft_bzero((*env)->map[m.y], sizeof(t_map) * (WIDTH + 1));
			while (++m.x < WIDTH)
			{
				init_rsrc(env, turn, m);
				m.x++;
			}
			m.y++;
		}
		turn++;
	}
	return (TRUE);
}
