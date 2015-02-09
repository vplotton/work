/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 19:35:19 by vplotton          #+#    #+#             */
/*   Updated: 2014/06/26 01:52:06 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_bool	rotate(t_player *player, int side)
{
	side = (side == LEFT ? D_LEFT : D_RIGHT);
	if (!player->ivec.x)
	{
		player->ivec.x = (player->ivec.y == D_DOWN ? -side : side);
		player->ivec.y = 0;
	}
	else
	{
		player->ivec.y = (player->ivec.x == D_RIGHT ? side : -side);
		player->ivec.x = 0;
	}
	return (TRUE);
}

t_bool	translate(t_player *player, int side)
{
	side = 1;
	if (!V(x))
	{
		P(y) = P(y) + V(y) * side;
		P(y) = (P(y) < 0 ? P(y) + player->size.y : P(y) % player->size.y);
	}
	else
	{
		P(x) = P(x) + V(x) * side;
		P(x) = (P(x) < 0 ? P(x) + player->size.x : P(x) % player->size.x);
	}
	return (TRUE);
}
