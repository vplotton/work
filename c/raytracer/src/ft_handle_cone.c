/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 12:09:07 by vplotton          #+#    #+#             */
/*   Updated: 2014/03/24 22:41:53 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"raytracer.h"
#include	<stdio.h>

static double	ft_get_delta(t_posd vec, t_ray *ray, t_info info)
{
	double	delta;
	double	alpha;

	alpha = info.obj->data->radius * vec.y * 10;
	delta = vec.x * vec.x + vec.z * vec.z;
	delta = delta * (C(x) + C(z) - alpha * alpha);
	delta = (B(x) + B(z)) * (B(x) + B(z)) - delta;
	return (delta);
}

double			ft_inter_cone
(t_posd *intersect, t_posd vec, t_ray *ray, t_info info)
{
	double	dst[2];
	double	delta;
	double	alpha[2];
	t_posd	inter[2];

	delta = ft_get_delta(vec, ray, info);
	if (delta < 0.0001)
		return (2147483647);
	alpha[0] = (-1) * (B(x) + B(z) - sqrt(delta))
		/ (vec.x * vec.x + vec.z * vec.z);
	alpha[1] = (-1) * (B(x) + B(z) + sqrt(delta))
		/ (vec.x * vec.x + vec.z * vec.z);
	(inter[0]).x = V_INI(x, 0);
	(inter[1]).x = V_INI(x, 1);
	(inter[0]).y = V_INI(y, 0);
	(inter[1]).y = V_INI(y, 1);
	if ((inter[1]).y - O(y) > (info.obj->data->height + O(y))
			&& (inter[0]).y - O(y) > (info.obj->data->height) + O(y))
		return (2147483647);
/*	printf("I1:%f -- I2:%f -- H:%f\n", (inter[1]).y - O(y), (inter[0]).y - O(y)
			, info.obj->data->height + O(y));
*/	(inter[0]).z = V_INI(z, 0);
	(inter[1]).z = V_INI(z, 1);
	dst[0] = sqrt(I2(0,x, ray->mode) + I2(0,y, ray->mode) + I2(0,z, ray->mode));
	dst[1] = sqrt(I2(1,x, ray->mode) + I2(1,y, ray->mode) + I2(1,z, ray->mode));
	if (dst[0] > dst[1])
	{
		inter[0] = inter[1];
		dst[0] = dst[1];
	}
	*intersect = inter[0];
	return (dst[0]);
}
