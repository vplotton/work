/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 11:26:42 by vplotton          #+#    #+#             */
/*   Updated: 2014/03/25 21:22:11 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"raytracer.h"

void	ft_norm(t_posd *vec)
{
	double	norm;

	norm = sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
	vec->x = vec->x / norm;
	vec->y = vec->y / norm;
	vec->z = vec->z / norm;
}

double	ft_get_dst(t_posd coord1, t_posd coord2)
{
	double	dst;

	dst = sqrt((coord2.x - coord1.x) * (coord2.x - coord1.x)
			+ (coord2.y - coord1.y) * (coord2.y - coord1.y)
			+ (coord2.z - coord1.z) * (coord2.z - coord1.z));
	return (dst);
}

double	ft_get_vec(t_posd inter, t_posd lum, t_posd *vec)
{
	double	dst;

	vec->x = inter.x - lum.x;
	vec->y = inter.y - lum.y;
	vec->z = inter.z - lum.z;
	dst = sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
	ft_norm(vec);
	return (dst);
}

double	ft_dot_prod(t_posd vec1, t_posd vec2)
{
	double	scal;

	scal = vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
	return (scal);
}

t_posd	ft_cross_prod(t_posd vec1, t_posd vec2)
{
	t_posd	vec;

	vec.x = vec1.y * vec2.z - vec1.z * vec2.y;
	vec.y = vec1.z * vec2.x - vec1.x * vec2.z;
	vec.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return (vec);
}
