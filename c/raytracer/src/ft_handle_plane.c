/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 13:13:05 by vplotton          #+#    #+#             */
/*   Updated: 2014/03/19 22:31:20 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"raytracer.h"
#include	<stdio.h>

double	ft_inter_plane(t_posd *intersect, t_posd vec, t_ray *ray, t_info info)
{
	double	alpha;
	double	dst;
	double	scal;

	scal = vec.x * VEC(x) + vec.y * VEC(y) + vec.z * VEC(z);
	if (scal != 0.000000)
	{
/*		printf("scal : %f\n", scal);*/
		alpha = - (((ICAM(x, ray->mode) - O(x)) * VEC(x))
					+ ((ICAM(y, ray->mode) - O(y)) * VEC(y))
					+ ((ICAM(z, ray->mode) - O(z)) * VEC(z)))
					/ scal;
/*		printf("cam - O : %f -- %f -- %f\n"
				, ICAM(x, ray->mode) - O(x), ICAM(y, ray->mode) - O(y)
				, ICAM(z, ray->mode) - O(z));
		printf("alpha : %f\n", alpha);*/
	}
	else
		alpha = 0.000000;
	if (alpha == 0.000000)
		return (2147483647);
	else
	{
/*		printf("alpha : %f\n", alpha);*/
		(*intersect).x = ICAM(x, ray->mode) + alpha * vec.x;
		(*intersect).y = ICAM(y, ray->mode) + alpha * vec.y;
		(*intersect).z = ICAM(z, ray->mode) + alpha * vec.z;
/*		printf("inter %f -- %f -- %f\n"
				, (*intersect).x, (*intersect).y, (*intersect).z);*/
	}
	if (ray->mode == TRUE)
		dst = ft_get_dst(*intersect, info.cam->data->coord);
	else
		dst = ft_get_dst(*intersect, ray->inter);
	return (dst);
}
