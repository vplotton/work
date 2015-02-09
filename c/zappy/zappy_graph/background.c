/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 23:12:24 by cycharbo          #+#    #+#             */
/*   Updated: 2014/06/26 23:12:25 by cycharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy_graph.h"

static void	back_loop(t_env *env, SDL_Surface **flower)
{
	int				i;
	int				j;

	i = -1;
	srand(time(NULL));
	while (++i < env->display->level->h)
	{
		j = -1;
		env->display->g_pos->y = i * HGROUND;
		while (++j < env->display->level->w)
		{
			env->display->g_pos->x = j * WGROUND;
			SDL_BlitSurface(env->display->ground, NULL,
					env->display->level, env->display->g_pos);
			SDL_BlitSurface(env->display->ground, NULL,
					env->display->backg, env->display->g_pos);
			if (rand() % 5 == 1)
			{
				SDL_BlitSurface(flower[rand() % 4], NULL,
						env->display->level, env->display->g_pos);
				SDL_BlitSurface(flower[rand() % 4], NULL,
						env->display->backg, env->display->g_pos);
			}
		}
	}
}

int			ft_display_background(t_env *env)
{
	int				i;
	int				j;
	SDL_Surface		**decor;
	SDL_Surface		**flower;

	decor = NULL;
	flower = NULL;
	j = 0;
	i = 0;
	decor = init_texture(decor);
	flower = ft_init_flower(flower);
	env->display->backg = SDL_CreateRGBSurface(SDL_HWSURFACE,
			D_WIDTH + 150, D_HEIGHT + 150, 32, 0, 0, 0, 0);
	back_loop(env, flower);
	env->display->g_pos->x = 0;
	env->display->g_pos->y = 0;
	put_decor(decor, env);
	free_surface(decor, 5);
	free_surface(flower, 6);
	return (1);
}
