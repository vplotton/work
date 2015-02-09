/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 20:00:34 by vplotton          #+#    #+#             */
/*   Updated: 2014/06/06 13:52:47 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy_graph.h"

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
	// a virer c du test
	player->rsrc[5] = 2;
	// tooooototototot
    (*env)->map[player->pos.y][player->pos.x].ids[id] = TRUE;
    player->team = ft_strdup("tourte");
    printf("init pos x = %d et y = %d\n", player->pos.y, player->pos.x);
	return (TRUE);
}

t_bool			init(t_env **env)
{
	if ((*env = ft_memalloc(sizeof(t_env))) == FALSE)
	{
		ft_putendl_fd("ERROR: Env not created", 2);
		return (FALSE);
	}
	if (init_env(env) == FALSE)
		return (FALSE);
	if (init_player(&(*env)->pl[0], env) == FALSE)
		return (FALSE);
	if (init_player(&(*env)->pl[1], env) == FALSE)
		return (FALSE);
	return (TRUE);
}
