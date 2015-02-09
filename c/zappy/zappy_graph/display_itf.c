/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_itf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 19:51:44 by cycharbo          #+#    #+#             */
/*   Updated: 2014/06/26 21:41:54 by cycharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy_graph.h"

void			ft_load_numbers(t_env **env)
{
	(*env)->itf->num = (SDL_Surface**)ft_memalloc(sizeof(SDL_Surface*) * 11);
	(*env)->itf->num[0] = SDL_LoadBMP("img/0.bmp");
	(*env)->itf->num[1] = SDL_LoadBMP("img/1.bmp");
	(*env)->itf->num[2] = SDL_LoadBMP("img/2.bmp");
	(*env)->itf->num[3] = SDL_LoadBMP("img/3.bmp");
	(*env)->itf->num[4] = SDL_LoadBMP("img/4.bmp");
	(*env)->itf->num[5] = SDL_LoadBMP("img/5.bmp");
	(*env)->itf->num[6] = SDL_LoadBMP("img/6.bmp");
	(*env)->itf->num[7] = SDL_LoadBMP("img/7.bmp");
	(*env)->itf->num[8] = SDL_LoadBMP("img/8.bmp");
	(*env)->itf->num[9] = SDL_LoadBMP("img/9.bmp");
	(*env)->itf->num[10] = SDL_LoadBMP("img/lvl.bmp");
}

static void		ft_display_team(t_env *env)
{
	int			i;
	int			nb;
	int			j;
	SDL_Rect	p;

	i = -1;
	p.y = 30;
	p.x = 55;
	while (++i < env->t_nb)
	{
		j = 0;
		while (++j < 9)
		{
			nb = env->itf->team[i].lvl[j];
			if (nb / 10 != 0)
				SDL_BlitSurface(env->itf->num[nb / 10], NULL, env->itf->d_itf,
						&p);
			p.x += 10;
			SDL_BlitSurface(env->itf->num[nb % 10], NULL, env->itf->d_itf, &p);
			p.x += 20;
		}
		p.y += 15;
		p.x = 55;
	}
}

static void		first_line_itf(t_env *env)
{
	SDL_Rect	pos;
	int			i;

	i = 1;
	pos.y = 0;
	pos.x = 30;
	SDL_BlitSurface(env->itf->num[10], NULL, env->itf->d_itf, NULL);
	while (i < 9)
	{
		pos.x += 30;
		SDL_BlitSurface(env->itf->num[i], NULL, env->itf->d_itf, &pos);
		i++;
	}
}

void			ft_display_itf(t_env *env)
{
	env->itf->d_itf = SDL_CreateRGBSurface(SDL_HWSURFACE, 300,
			env->t_nb * 30, 32, 0, 0, 0, 0);
	SDL_FillRect(env->itf->d_itf, NULL,
			SDL_MapRGB(env->itf->d_itf->format, 0, 0, 0));
	SDL_SetAlpha(env->itf->d_itf, SDL_SRCALPHA, 128);
	first_line_itf(env);
	ft_display_team(env);
}
