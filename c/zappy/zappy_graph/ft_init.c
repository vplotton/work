/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 16:02:48 by cycharbo          #+#    #+#             */
/*   Updated: 2014/06/26 16:37:21 by cycharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "zappy_graph.h"

int			ft_init_video(t_env *env)
{
	int		x;
	int		y;

	env->display = (t_display*)malloc(sizeof(t_display));
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		ft_putstr("Unable to init SDL:");
		ft_putstr(SDL_GetError());
		return (-1);
	}
	x = env->m_width;
	y = env->m_height;
	env->display->windows = SDL_SetVideoMode(x * 50 + 400, y * 50 + 200, 16,
			SDL_HWSURFACE);
	printf("taille fenetre %d %d\n", D_WIDTH, D_HEIGHT);
	if (env->display->windows == NULL)
	{
		ft_putstr("Unable to make windows:");
		ft_putstr(SDL_GetError());
		return (-1);
	}
	return (1);
}

int			ft_load_ground(t_env *env)
{
	env->display->g_pos = (SDL_Rect*)malloc(sizeof(SDL_Rect));
	env->display->g_pos->x = 0;
	env->display->g_pos->y = 0;
	env->display->ground = SDL_LoadBMP("img/ground.bmp");
	env->display->ground = SDL_DisplayFormat(env->display->ground);
	env->display->mv_cam = 0;
	env->display->pl_img = SDL_LoadBMP("img/player.bmp");
	env->pl = (t_player*)ft_memalloc(sizeof(t_player) * MAX_PLAYER);
	if (!env->display->ground)
	{
		ft_putstr("Unable to load ground\n");
		return (-1);
	}
	env->nb = 0;
	return (1);
}
