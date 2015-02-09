/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obengelo <obengelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 19:29:41 by cycharbo          #+#    #+#             */
/*   Updated: 2014/06/27 03:42:12 by obengelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy_graph.h"

SDL_Rect			ft_pos_player(t_env *env, int x, int y)
{
	t_point			pt;
	SDL_Rect		pos;

	pt = convert(x, y, 0);
	pos.x = pt.x + abs(env->display->cam_min_x) - 25;
	pos.y = pt.y - 25;
	pos.w = 30;
	pos.h = 30;
	return (pos);
}

void				ft_move_player(t_env *env, int id)
{
	int				i;
	SDL_Surface		*del;
	SDL_Rect		pos;

	i = 0;
	pos = ft_pos_player(env, env->pl[id].pos.x, env->pl[id].pos.y);
	while (i < env->nb)
	{
		if (env->map[env->pl[id].pos.y][env->pl[id].pos.x].ids[i] == TRUE)
			return ;
		i++;
	}
	del = SDL_CreateRGBSurface(0, env->display->pl_img->w,
			env->display->pl_img->h, 32, 0, 0, 0, 0);
	SDL_BlitSurface(del, NULL, env->display->level, &pos);
}

void				check_player(t_env *env, int x, int y, SDL_Surface *img)
{
	int				i;
	SDL_Surface		*player;
	SDL_Rect		pos;

	pos = ft_pos_player(env, x, y);
	i = 0;
	while (i < MAX_PLAYER)
	{
		if (env->map[y][x].ids[i] && env->map[y][x].ids[i] == TRUE)
		{
			player = SDL_LoadBMP("img/player.bmp");
			player = SDL_DisplayFormat(player);
			SDL_SetAlpha(player, SDL_SRCALPHA, 255);
			SDL_SetColorKey(player, SDL_SRCCOLORKEY,
					SDL_MapRGB(player->format, 255, 255, 0));
			if (env->pl[i].dead == FALSE)
				SDL_BlitSurface(player, NULL, img, &pos);
			SDL_FreeSurface(player);
			return ;
		}
		i++;
	}
}
