/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 23:12:55 by cycharbo          #+#    #+#             */
/*   Updated: 2014/06/26 23:12:57 by cycharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy_graph.h"
#include <math.h>

void	ft_move_cam_down(t_env *env)
{
	SDL_Rect	p;

	if (env->display->cam_pos.y + env->display->windows->h - 200 <
			env->display->level->h)
	{
		env->display->mv_cam += 1;
		env->display->cam_pos.y += 10;
		p.y = 0;
		p.x = 0;
	}
}

void	ft_move_cam_up(t_env *env)
{
	SDL_Rect	p;

	if (env->display->cam_pos.y - 5 > 0)
	{
		env->display->mv_cam -= 1;
		env->display->cam_pos.y -= 10;
		p.y = 0;
		p.x = 0;
	}
	else
	{
		env->display->mv_cam = 0;
		env->display->cam_pos.y = 0;
	}
}

void	ft_move_cam_l(t_env *env)
{
	SDL_Rect	p;

	if (env->display->cam_pos.x > env->display->cam_min_x)
	{
		if (env->display->cam_pos.x >= 1)
			env->display->cam_pos.x -= 10;
		p.y = 0;
		p.x = 0;
	}
}

void	ft_move_cam_r(t_env *env)
{
	SDL_Rect	p;

	if (env->display->cam_pos.x + env->display->windows->w <
			env->display->level->w)
	{
		env->display->cam_pos.x += 10;
		p.y = 0;
		p.x = 0;
	}
}
