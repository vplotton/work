/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 15:43:21 by cycharbo          #+#    #+#             */
/*   Updated: 2014/03/24 22:46:56 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include <stdio.h>

static void	ft_get_color(t_ray *ray, t_posd color)
{
	ray->color.x = color.x;
	ray->color.y = color.y;
	ray->color.z = color.z;
}

static void     ft_wood(t_ray *ray, t_posd color1, t_posd color2)
{
	int         l;
    int         x1;
    int         x2;
    int         x3;
	static 		int	t 	= 0;
//	static		int	t1 	= 0;
//	static		int	t3 	= 0;
	l = ray->obj->radius / 2 ;
    x1 = color1.x - color2.x;
	   x2 = color1.y - color2.y;
    x3 = color1.z - color2.z;
    if (x3 % 2 == 0)
    {
        if ((x2 % 2 == 1 && x1 % 2 == 1) || (x2 %2 == 0 && x1 % 2 == 0))
        {
			ray->color.x = color1.x;
			ray->color.y = color1.y;
			ray->color.z = color1.z;
		}
        else
		{
			ray->color.x = color2.x + t;
            ray->color.y = color2.y + t;
            ray->color.z = color2.z + t;
		}
    }
    else
    {
        if ((x2 % 2 == 1 && x1 % 2 == 1) || (x2 %2 == 0 && x1 % 2 == 0))
		{
			ray->color.x = color2.x + t;
            ray->color.y = color2.y + t;
            ray->color.z = color2.z + t;
		}
        else
		{
			ray->color.x = color1.x;
            ray->color.y = color1.y;
            ray->color.z = color1.z;
		}
    }
	t++;
}

void	ft_gradient(t_ray *ray, t_posd color1, t_posd color2)
{
	static int	t =  0;
	(void)color1;
	ray->obj->color.x = color2.x + t;
	ray->obj->color.y = color2.y + t;
	ray->obj->color.z = color2.z + t;
	if (t + color2.x > 249)
		t = 0;
	t++;
}

static void		ft_checkerboard(t_ray *ray, t_posd color1, t_posd color2)
{
	int      	l;
    int         x1;
    int         x2;
    int         x3;

    l = ray->obj->radius / 2 ;
    x1 = ray->inter.x / l;
    x2 = ray->inter.y / l;
    x3 = ray->inter.z / l;
	if (x3 % 2 == 0)
	{
		if ((x2 % 2 == 1 && x1 % 2 == 1) || (x2 %2 == 0 && x1 % 2 == 0))
			ft_get_color(ray, color1);
		else
			ft_get_color(ray, color2);
	}
	else	
	{
		if ((x2 % 2 == 1 && x1 % 2 == 1) || (x2 %2 == 0 && x1 % 2 == 0))
			ft_get_color(ray, color2);
        else
			ft_get_color(ray, color1);
	}
}

void    ft_texture(t_ray *ray, char txt_type, t_posd color1, t_posd color2)
{
	if (txt_type == 'D')
		ft_checkerboard(ray, color1, color2);
	if (txt_type == 'B')
		ft_wood(ray, color1, color2);
	if (txt_type == 'G')
		ft_gradient(ray, color1, color2);
}
