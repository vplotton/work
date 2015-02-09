/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 16:00:15 by cycharbo          #+#    #+#             */
/*   Updated: 2014/06/26 23:23:15 by cycharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy_graph.h"

void	ft_draw_pixel(int x, int y, t_env *env)
{
	SDL_Rect	pos;

	pos.x = x + abs(env->display->cam_min_x);
	pos.y = y;
	pos.h = 1;
	pos.w = 1;
	SDL_BlitSurface(env->display->px, NULL, env->display->backg, &pos);
}
