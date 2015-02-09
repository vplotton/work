/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pause.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 22:57:49 by cycharbo          #+#    #+#             */
/*   Updated: 2014/06/27 01:54:36 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy_graph.h"

static void		k_dwn(t_env *env, SDL_Event event, int *conti)
{
	if (event.key.keysym.sym)
	{
		if (event.key.keysym.sym == SDLK_ESCAPE)
			*conti = 0;
		else if (event.key.keysym.sym == SDLK_UP)
			ft_move_cam_up(env);
		else if (event.key.keysym.sym == SDLK_LEFT)
			ft_move_cam_l(env);
		else if (event.key.keysym.sym == SDLK_RIGHT)
			ft_move_cam_r(env);
		else if (event.key.keysym.sym == SDLK_DOWN)
			ft_move_cam_down(env);
		else
			*conti = 1;
	}
}

static void		k_up(t_env *env, SDL_Event event, int *conti)
{
	if (event.key.keysym.sym)
	{
		if (event.key.keysym.sym == SDLK_ESCAPE)
			*conti = 0;
		else if (event.key.keysym.sym == SDLK_DOWN)
			ft_move_cam_down(env);
		else if (event.key.keysym.sym == SDLK_RIGHT)
			ft_move_cam_r(env);
		else if (event.key.keysym.sym == SDLK_LEFT)
			ft_move_cam_l(env);
		else if (event.key.keysym.sym == SDLK_UP)
			ft_move_cam_up(env);
		else
			*conti = 1;
	}
}

static void		k_event(t_env *env, SDL_Event event, int *conti)
{
	if (event.type)
	{
		if (event.type == SDL_QUIT)
		{
			*conti = 0;
			return ;
		}
		else if (event.type == SDL_KEYDOWN)
			k_dwn(env, event, conti);
		else if (event.type == SDL_KEYUP)
			k_up(env, event, conti);
		else
			*conti = 1;
	}
}

void			ft_pause(t_env *env)
{
	int			conti;
	SDL_Event	event;

	conti = 1;
	while (conti)
	{
		ft_check_anim(env);
		SDL_PollEvent(&event);
		k_event(env, event, &conti);
		SDL_FillRect(env->display->windows, NULL
				, SDL_MapRGB(env->display->windows->format, 255, 255, 255));
		SDL_BlitSurface(env->display->backg
				, &env->display->cam_pos, env->display->windows, NULL);
		SDL_BlitSurface(env->display->level
				, &env->display->cam_pos, env->display->windows, NULL);
		SDL_BlitSurface(env->display->d_rsc
				, &env->display->cam_pos, env->display->windows, NULL);
		SDL_BlitSurface(env->display->anim_event
				, &env->display->cam_pos, env->display->windows, NULL);
		SDL_Flip(env->display->windows);
		SDL_FillRect(env->display->anim_event, NULL
				, SDL_MapRGB(env->display->anim_event->format, 0, 0, 0));
		SDL_Delay(5);
		ft_recv_loop(env, 0);
	}
}
