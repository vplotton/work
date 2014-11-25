/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 17:35:28 by vplotton          #+#    #+#             */
/*   Updated: 2014/03/24 20:40:24 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"raytracer.h"

void	ft_rotate_x(t_posd *vec, double angle)
{
	double	tmp;

	tmp = vec->y;
	vec->x = vec->x;
	vec->y = vec->y * cos(angle) + vec->z * sin(angle);
	vec->z = - tmp * sin(angle) + vec->z * cos(angle);
}

void	ft_rotate_y(t_posd *vec, double angle)
{
	double	tmp;

	tmp = vec->x;
	vec->x = vec->x * cos(angle) - vec->z * sin(angle);
	vec->y = vec->y;
	vec->z = tmp * sin(angle) + vec->z * cos(angle);
}

void	ft_rotate_z(t_posd *vec, double angle)
{
	double	tmp;

	tmp = vec->x;
	vec->x = vec->x * cos(angle) + vec->y * sin(angle);
	vec->y = - tmp * sin(angle) + vec->y * cos(angle);
	vec->z = vec->z;
}
