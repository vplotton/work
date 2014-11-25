/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 12:09:07 by vplotton          #+#    #+#             */
/*   Updated: 2014/03/25 23:10:46 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"raytracer.h"
#include	<stdio.h>
/*
static double	ft_get_delta(t_posd vec, t_ray *ray, t_info info)
{
	double	delta;

	delta = vec.x * vec.x + vec.z * vec.z;
	delta = delta * (C(x) + C(z) - R2);
	delta = (B(x) + B(z)) * (B(x) + B(z)) - delta;
	return (delta);
}
*/
double			ft_inter_cylinder
(t_posd *intersect, t_posd vec, t_ray *ray, t_info info)
{
	t_posd	vec_n;
	t_posd	vec_d;
	t_posd	vec_o;
	t_posd	l_pos;
	double	dst;
	double	dst_d;
	double	dst_t;
	double	dst_s;
	double	in;
	double	out;
	double	alpha;
	double	scale;

	ft_norm(&info.obj->data->d_vec);
	vec_d.x = ICAM(x, ray->mode) - O(x);
	vec_d.y = ICAM(y, ray->mode) - O(y);
	vec_d.z = ICAM(z, ray->mode) - O(z);
	vec_n = ft_cross_prod(info.obj->data->d_vec, vec);
	dst = sqrtf(vec_n.x * vec_n.x + vec_n.y * vec_n.y + vec_n.z * vec_n.z);
	if (dst < ERR && dst > - ERR)
	{
		printf("PARALEL\n");
		return (2147483647);
	}
	ft_norm(&vec_n);
	dst_d = fabs(ft_dot_prod(vec_d, vec_n));
	if (dst_d <= (info.obj->data->radius))
	{
		vec_o = ft_cross_prod(vec_d, info.obj->data->d_vec);
		ft_norm(&vec_o);
		dst_t = - ft_dot_prod(vec_o, vec_n) / dst;
		vec_o = ft_cross_prod(vec_n, info.obj->data->d_vec);
		ft_norm(&vec_o);
		dst_s = fabs(sqrtf(R2 - dst_d * dst_d) / ft_dot_prod(vec, vec_o));
/*		printf("dst: %f\ndst_d: %f\ndst_t: %f\ndst_s: %f\n"
				, dst, dst_d, dst_t, dst_s);
*/		in = dst_t - dst_s;
		out = dst_t + dst_s;
/*		printf("in: %f -- out: %f\n", in, out);
*/		if (in < -ERR)
		{
			if (out < -ERR)
				return (2147483647);
			else
				alpha = in;
		}
		else if (out < ERR)
			alpha = out;
		else if (in < out)
			alpha = out;
		else
			alpha = in;
		(*intersect).x = vec.x * alpha + O(x);
		(*intersect).y = vec.y * alpha + O(y);
		(*intersect).z = vec.z * alpha + O(z);
		dst = sqrtf(((*intersect).x - ICAM(x, ray->mode))
				* ((*intersect).x - ICAM(x, ray->mode))
				+ ((*intersect).y - ICAM(y, ray->mode))
				* ((*intersect).y - ICAM(y, ray->mode))
				+ ((*intersect).z - ICAM(z, ray->mode))
				* ((*intersect).z - ICAM(z, ray->mode)));
		if (ray->mode == TRUE)
		{
			l_pos.x = (*intersect).x - O(x);
			l_pos.y = (*intersect).y - O(y);
			l_pos.z = (*intersect).z - O(z);
			printf("h: %f -- %f -- %f\n", l_pos.x, l_pos.y, l_pos.z);
			scale = ft_dot_prod(l_pos, info.obj->data->d_vec);
			ft_norm(&l_pos);
			ray->normal.x = l_pos.x - info.obj->data->d_vec.x * scale;
			ray->normal.y = l_pos.y - info.obj->data->d_vec.y * scale;
			ray->normal.z = l_pos.z - info.obj->data->d_vec.z * scale;
			printf("scale: %f\n", scale);
			ft_norm(&ray->normal);
			printf("Normal: %f -- %f -- %f\n", ray->normal.x, ray->normal.y, ray->normal.z);
		}
		/*		if (ray->mode == TRUE)
				{
				printf("\n");
				printf("vec: %f -- %f -- %f\n", vec.x, vec.y, vec.z);
				printf("ICAM: %f -- %f -- %f\n"
				, ICAM(x, ray->mode), ICAM(y, ray->mode), ICAM(z, ray->mode));
				printf("inter: %f -- %f -- %f\n"
				, (*intersect).x, (*intersect).y, (*intersect).z);
				printf("Final dst: %f\n", dst);
				}
				*/		return (dst);
	}
	return (2147483647);
}

/*
   double			ft_inter_cylinder
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
   if ((inter[1]).y > info.obj->data->height / 2.0
   && (inter[0]).y > info.obj->data->height / 2.0)
   return (2147483647);
   if (-((inter[1]).y) > info.obj->data->height / 2.0
   && (-(inter[0]).y) > info.obj->data->height / 2.0)
   return (2147483647);
   printf("I1:%f -- I2:%f -- H:%f\n", (inter[1]).y
   , (inter[0]).y
   , info.obj->data->height);
   (inter[0]).z = V_INI(z, 0);
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
 */
