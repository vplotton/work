/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rscr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 19:20:54 by cycharbo          #+#    #+#             */
/*   Updated: 2014/06/26 20:56:15 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy_graph.h"

void				scan_map(t_env *env, t_bool pl, t_bool rsc)
{
	int				i;
	int				j;

	i = 0;
	while (i < env->m_height)
	{
		j = 0;
		while (j < env->m_width)
		{
			if (pl)
				check_player(env, j, i, env->display->level);
			if (rsc)
				check_rsc(env, j, i);
			j++;
		}
		i++;
	}
}

void				ft_init_ressource_img(t_env **env)
{
	(*env)->display->rsc = (SDL_Surface**)malloc(sizeof(SDL_Surface*) * 7);
	(*env)->display->rsc[0] = SDL_LoadBMP("img/rsc1.bmp");
	SDL_SetColorKey((*env)->display->rsc[0], SDL_SRCCOLORKEY,
			SDL_MapRGB((*env)->display->rsc[0]->format, 255, 255, 0));
	(*env)->display->rsc[1] = SDL_LoadBMP("img/rsc2.bmp");
	SDL_SetColorKey((*env)->display->rsc[1], SDL_SRCCOLORKEY,
			SDL_MapRGB((*env)->display->rsc[1]->format, 255, 255, 0));
	(*env)->display->rsc[2] = SDL_LoadBMP("img/rsc3.bmp");
	SDL_SetColorKey((*env)->display->rsc[2], SDL_SRCCOLORKEY,
			SDL_MapRGB((*env)->display->rsc[2]->format, 255, 255, 0));
	(*env)->display->rsc[3] = SDL_LoadBMP("img/rsc4.bmp");
	SDL_SetColorKey((*env)->display->rsc[3], SDL_SRCCOLORKEY,
			SDL_MapRGB((*env)->display->rsc[3]->format, 255, 255, 0));
	(*env)->display->rsc[4] = SDL_LoadBMP("img/rsc5.bmp");
	SDL_SetColorKey((*env)->display->rsc[4], SDL_SRCCOLORKEY,
			SDL_MapRGB((*env)->display->rsc[4]->format, 255, 255, 0));
	(*env)->display->rsc[5] = SDL_LoadBMP("img/rsc6.bmp");
	SDL_SetColorKey((*env)->display->rsc[5], SDL_SRCCOLORKEY,
			SDL_MapRGB((*env)->display->rsc[5]->format, 255, 255, 0));
	(*env)->display->rsc[6] = SDL_LoadBMP("img/rsc7.bmp");
	SDL_SetColorKey((*env)->display->rsc[6], SDL_SRCCOLORKEY,
			SDL_MapRGB((*env)->display->rsc[6]->format, 255, 255, 0));
}

static void			ft_chk_nxt(SDL_Rect *pos, int *j, int i, t_point pt)
{
	if (i < 4)
	{
		pos->x = pt.x + i * 10;
		pos->y = pt.y + i * 5;
		*j = 1;
	}
	else if (i == 4)
	{
		pos->y = pt.y + 20;
		pos->x = pt.x;
		*j = 1;
	}
	else if (i > 4)
	{
		pos->x = pt.x - *j * 10;
		pos->y = pt.y + *j * 5;
	}
}

void				check_rsc(t_env *env, int x, int y)
{
	int				i;
	SDL_Rect		pos;
	int				j;
	t_point			pt;

	pt = convert(x, y, 0);
	pos.w = 10;
	pos.h = 10;
	pt.x = pt.x + abs(env->display->cam_min_x);
	pos.x = pt.x;
	i = 0;
	pos.y = pt.y;
	j = 1;
	while (i < 7)
	{
		if (env->map[y][x].rsrc[i] == 1)
		{
			ft_chk_nxt(&pos, &j, i, pt);
			j++;
			SDL_BlitSurface(env->display->rsc[i], NULL, env->display->d_rsc,
					&pos);
		}
		i++;
	}
}
