/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_ground.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obengelo <obengelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/27 01:47:15 by obengelo          #+#    #+#             */
/*   Updated: 2014/06/27 03:32:17 by obengelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy_graph.h"

void		free_surface(SDL_Surface **img, int img_len)
{
	int		i;

	i = 0;
	while(i < img_len)
	{
		SDL_FreeSurface(img[i]);
		i++;
	}
	ft_memdel((void**)img);
}

static void	first_line(t_env *env, SDL_Surface **decor)
{
	int			i;
	SDL_Rect	pos;

	i = 0;
	pos.y = 0;
	while(i < env->display->backg->w)
	{
		if(i % 630 == 1)
		{
			pos.x = i;
			SDL_BlitSurface(decor[0], NULL, env->display->backg, &pos);
		}
		i++;
	}
}

static void	tree_line(t_env *env, SDL_Surface **decor, int y)
{
	int			i;
	int			dev;
	SDL_Rect	pos;
	SDL_Surface	*bg;

	i = 0;
	pos.y = y;
	bg = env->display->backg;
	srand(time(NULL));
	while(i < env->display->backg->w)
	{
		if(i % 94 == 1)
		{
			dev = rand() % 20;
			pos.y = pos.y + dev;
			pos.x = i;
			SDL_BlitSurface(decor[randoms(3, 4)], NULL, bg, &pos);
			pos.y -= dev + y / 3;
			SDL_BlitSurface(decor[randoms(1, 2)], NULL, bg, &pos);
			pos.y = pos.y + rand() % 8;
		}
		i++;
	}
}

SDL_Surface	**init_texture(SDL_Surface **d)
{
	d = (SDL_Surface**)malloc(sizeof(SDL_Surface*) * 5);
	d[0] = SDL_LoadBMP("img/fond_arbre.bmp");
	d[1] = SDL_LoadBMP("img/arbre1.bmp");
	SDL_SetColorKey(d[1], SDL_SRCCOLORKEY, SDL_MapRGB(d[1]->format, 255, 0, 0));
	d[2] = SDL_LoadBMP("img/arbre2.bmp");
	SDL_SetColorKey(d[2], SDL_SRCCOLORKEY, SDL_MapRGB(d[2]->format, 255, 0, 0));
	d[3] = SDL_LoadBMP("img/arbre3.bmp");
	SDL_SetColorKey(d[3], SDL_SRCCOLORKEY, SDL_MapRGB(d[3]->format, 255, 0, 0));
	d[4] = SDL_LoadBMP("img/arbre4.bmp");
	SDL_SetColorKey(d[4], SDL_SRCCOLORKEY, SDL_MapRGB(d[4]->format, 255, 0, 0));
	return (d);
}

void			put_decor(SDL_Surface **decor, t_env *env)
{
	first_line(env, decor);
	tree_line(env, decor, 30);
	tree_line(env, decor, 60);
}

static	void	ft_display_ground2(t_env *env, SDL_Surface	**flower)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while(i <= env->display->backg->h)
	{
		j = 0;
		env->display->g_pos->y = HGROUND * i;
		while(j <= env->display->backg->w)
		{
			env->display->g_pos->x = WGROUND * j;
			SDL_BlitSurface(env->display->ground
					, NULL, env->display->backg, env->display->g_pos);
			if(randoms(1, 3) == 1)
				SDL_BlitSurface(flower[randoms(0, 5)]
						, NULL, env->display->backg, env->display->g_pos);
			j++;
		}
		i++;
	}
}

int				ft_display_ground(t_env *env)
{
	SDL_Surface		**decor;
	SDL_Surface		**flower;

	decor = NULL;
	flower = NULL;
	decor = init_texture(decor);
	flower = ft_init_flower(flower);
	env->display->backg = SDL_CreateRGBSurface(SDL_HWSURFACE
			, env->display->level->w + 250
			, env->display->level->h + 350, 32, 0, 0, 0, 255);
	ft_display_ground2(env, flower);
	env->display->g_pos->x = 0;
	env->display->g_pos->y = 0;
	put_decor(decor, env);
	return (1);
}
