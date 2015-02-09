/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 19:35:19 by vplotton          #+#    #+#             */
/*   Updated: 2014/06/06 13:39:35 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ia_zappy.h"

void	rotate(t_bool side, t_player *player)
{
	if (!player->ivec.x)
	{
		player->ivec.x = (player->ivec.y == DOWN ? -side : side);
		player->ivec.y = 0;
	}
	else
	{
		player->ivec.x = 0;
		player->ivec.y = (player->ivec.x == RIGHT ? side : -side);
	}
}

void	translate(t_bool side, t_player *player, t_env **env)
{
	(*env)->map[P(y)][P(x)].ids[player->id] = FALSE;
	if (!V(x))
	{
		P(y) = (P(y) + V(y) * side);
		P(y) = (P(y) < 0 ? P(y) + HEIGHT : P(y) % HEIGHT);
	}
	else
	{
		P(x) = (P(x) + V(x) * side);
		P(x) = (P(x) < 0 ? P(x) + HEIGHT : P(x) % WIDTH);
	}
	(*env)->map[P(y)][P(x)].ids[player->id] = TRUE;
}
