/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 19:34:38 by cycharbo          #+#    #+#             */
/*   Updated: 2014/06/26 19:34:40 by cycharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy_graph.h"
#include <math.h>

static void		ft_draw_case_one(t_point a, t_point b, t_point inc, t_env *env)
{
	int			cumul;
	int			i;
	int			dx;
	int			dy;

	dx = b.x - a.x;
	dy = b.y - a.y;
	cumul = dx / 2;
	i = 1;
	dx = fabs(dx);
	dy = fabs(dy);
	while (i <= dx)
	{
		a.x += inc.x;
		cumul += dy;
		if (cumul >= dx)
		{
			cumul -= dx;
			a.y += inc.y;
		}
		ft_draw_pixel(a.x, a.y, env);
		i++;
	}
}

static void		ft_draw_case_two(t_point a, t_point b, t_point inc, t_env *env)
{
	int			cumul;
	int			i;
	int			dx;
	int			dy;

	dx = b.x - a.x;
	dy = b.y - a.y;
	cumul = dy / 2;
	i = 1;
	dx = fabs((double)dx);
	dy = fabs((double)dy);
	while (i <= dy)
	{
		a.y += inc.y;
		cumul += dx;
		if (cumul >= dy)
		{
			cumul -= dy;
			a.x += inc.x;
		}
		ft_draw_pixel(a.x, a.y, env);
		i++;
	}
}

void			ft_draw_line(t_point a, t_point b, t_env *env)
{
	int			dx;
	int			dy;
	t_point		inc;

	dx = b.x - a.x;
	dy = b.y - a.y;
	inc.x = (dx > 0) ? 1 : -1;
	inc.y = (dy > 0) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	ft_draw_pixel(a.x, a.y, env);
	if (dx > dy)
		ft_draw_case_one(a, b, inc, env);
	else
		ft_draw_case_two(a, b, inc, env);
}

void			ft_draw_grid(t_env *env)
{
	int			i;
	int			j;
	int			z;

	srand(time(NULL));
	i = 0;
	z = 0;
	env->display->px = SDL_LoadBMP("img/pixel.bmp");
	SDL_SetAlpha(env->display->px, SDL_SRCALPHA, 45);
	while (i < env->m_height)
	{
		j = 0;
		while (j < env->m_width)
		{
			ft_draw_line(convert(j, i, z), convert(j + 1, i, z), env);
			ft_draw_line(convert(j, i, z), convert(j, i + 1, z), env);
			j++;
		}
		ft_draw_line(convert(j, i, z), convert(j, i + 1, z), env);
		i++;
	}
	ft_draw_line(convert(0, i, z), convert(j, i, z), env);
	SDL_SetColorKey(env->display->level, SDL_SRCCOLORKEY,
			SDL_MapRGB(env->display->level->format, 0, 0, 0));
	SDL_FreeSurface(env->display->px);
}
