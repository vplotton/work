/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 13:27:01 by vplotton          #+#    #+#             */
/*   Updated: 2014/03/19 14:22:06 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"raytracer.h"
#include	<stdio.h>

static double	ft_get_delta(t_posd vec, t_ray *ray, t_info info)
{
	double	delta;

	delta = vec.x * vec.x + vec.y * vec.y + vec.z * vec.z;
	delta = delta * (C(x) + C(y) + C(z) - R2);
	delta = (B(x) + B(y) + B(z)) * (B(x) + B(y) + B(z)) - delta;
	return (delta);
}

double			ft_inter_sphere
(t_posd *intersect, t_posd vec, t_ray *ray, t_info info)
{
	double	delta;
	double	dst[2];
	double	alpha[2];
	t_posd	inter[2];

	delta = ft_get_delta(vec, ray, info);
	if (delta < 0.000001)
		return (2147483647);
	alpha[0] = (-1) * (B(x) + B(y) + B(z) - sqrt(delta))
		/ (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	alpha[1] = (-1) * (B(x) + B(y) + B(z) + sqrt(delta))
		/ (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	(inter[0]).x = V_INI(x, 0);
/*	if (ray->mode == FALSE)
		printf("V_INI : %f -- inter(0,x) : %f\n", V_INI(x, 0), inter[0].x);
*/	(inter[1]).x = V_INI(x, 1);
  /*  if (ray->mode == FALSE)
	        printf("V_INI : %f -- inter(1,x) : %f\n", V_INI(x, 1), inter[1].x);
*/	(inter[0]).y = V_INI(y, 0);
	(inter[1]).y = V_INI(y, 1);
	(inter[0]).z = V_INI(z, 0);
	(inter[1]).z = V_INI(z, 1);
	dst[0] = sqrt(I2(0,x, ray->mode) + I2(0,y, ray->mode) + I2(0,z, ray->mode));
	dst[1] = sqrt(I2(1,x, ray->mode) + I2(1,y, ray->mode) + I2(1,z, ray->mode));
	if (dst[0] > dst[1])
	{
		inter[0] = inter[1];
		dst[0] = dst[1];
	}
/*	if (ray->mode == FALSE)
		printf("dsts : %f -- %f\n", dst[0], dst[1]);
    if (ray->mode == FALSE)
		printf("INTER 0 : %f -- %f -- %f\n\n", (inter[0]).x, (inter[0]).y
				, (inter[0]).z);
*/	*intersect = inter[0];
/*   if (ray->mode == FALSE)
		printf("INTER : %f -- %f -- %f\n\n", (*intersect).x, (*intersect).y
				, (*intersect).z);
*/
	return (dst[0]);
}
