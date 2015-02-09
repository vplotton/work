/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 19:30:36 by cycharbo          #+#    #+#             */
/*   Updated: 2014/06/26 19:30:38 by cycharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy_graph.h"

static void fill_lvl(t_env *env, t_point dl, t_point dr, t_point end)
{
	env->display->cam_pos.x = 0;
	env->display->cam_pos.y = 0;
	env->display->cam_pos.h = D_HEIGHT;
	env->display->cam_pos.w = D_WIDTH;
	env->display->cam_max = dr.y;
	env->display->cam_min_x = dl.x;
	env->display->cam_max_x = end.x + dl.x;
}

void		ft_make_level(t_env *env)
{
	t_point	end;
	t_point	dleft;
	t_point	dright;
	int		w_len;
	int		h_len;

	dright = convert(env->m_width, env->m_height, 0);
	dleft = convert(0, env->m_height, 0);
	end = convert(env->m_width - 1, 0, 0);
	w_len = abs(dleft.x) + end.x;
	h_len = dright.y;
	env->display->level = SDL_CreateRGBSurface(SDL_HWSURFACE, w_len + 100,
			h_len, 32, 0, 0, 0, 0);
	env->display->anim_event = SDL_CreateRGBSurface(SDL_HWSURFACE,
			w_len + 100, h_len, 32, 0, 0, 0, 0);
	env->display->d_rsc = SDL_CreateRGBSurface(SDL_HWSURFACE, w_len + 100,
			h_len, 32, 0, 0, 0, 0);
	SDL_SetColorKey(env->display->anim_event, SDL_SRCCOLORKEY,
			SDL_MapRGB(env->display->anim_event->format, 0, 0, 0));
	SDL_SetColorKey(env->display->level, SDL_SRCCOLORKEY,
			SDL_MapRGB(env->display->level->format, 0, 0, 0));
	SDL_SetColorKey(env->display->d_rsc, SDL_SRCCOLORKEY,
			SDL_MapRGB(env->display->d_rsc->format, 0, 0, 0));
	fill_lvl(env, dleft, dright, end);
}
