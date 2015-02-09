/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 20:00:34 by vplotton          #+#    #+#             */
/*   Updated: 2014/06/09 20:19:56 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ia_zappy.h"

static t_bool	init_env(t_env **env)
{
	int		i;

	i = -1;
	if (init_map(env) == FALSE)
	{
		ft_putendl_fd("Error: map not created", 2);
		return (FALSE);
	}
	(*env)->pl = ft_memalloc(MAX_PLAYER * sizeof(t_player));
	while (++i < MAX_PLAYER)
		(*env)->pl[i].used = FALSE;
	(*env)->nb = 0;
	(*env)->t_nb = 0;
	ft_bzero((*env)->t, sizeof((*env)->t));
	return (TRUE);
}

t_bool			init_player(t_player *player, t_env **env)
{
	int			id;
	static int	val = 1;

	id = -1;
	ft_bzero(player, sizeof(t_player));
	while ((*env)->pl[++id].used == TRUE)
		;
	player->used = TRUE;
	player->id = id;
	srand(val * time(NULL));
	val = rand();
	player->pos.x = val % WIDTH;
	srand(val * time(NULL));
	val = rand();
	player->pos.y = val % HEIGHT;
	val = val % 100;
	if (val < 50)
		player->ivec.x = (val < 25 ? 1 : -1);
	else
		player->ivec.y = (val > 74 ? 1 : -1);
	player->lvl = 1;
	ft_bzero(player->rsrc, sizeof(player->rsrc));
	return (TRUE);
}

t_bool			init(t_env **env)
{
	int		i;

	i = -1;
	if ((*env = ft_memalloc(sizeof(t_env))) == FALSE)
	{
		ft_putendl_fd("ERROR: Env not created", 2);
		return (FALSE);
	}
	if (init_env(env) == FALSE)
		return (FALSE);
	while (++i < N_NET)
	if (init_player(&(*env)->pl[i], env) == FALSE)
		return (FALSE);
	return (TRUE);
}
