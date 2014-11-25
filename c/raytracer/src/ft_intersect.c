/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 16:31:48 by vplotton          #+#    #+#             */
/*   Updated: 2014/03/25 23:11:10 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"raytracer.h"
#include	<stdio.h>

t_bool	ft_get_sign(t_posd vec_lum, t_posd vec_ray)
{
	if (ft_dot_prod(vec_lum, vec_ray) > 0.000001)
		return (TRUE);
	return (FALSE);
}

t_posd	ft_inter_obj(double *dst, t_posd vec, t_ray *ray, t_info info)
{
	double		curr_dst;
	double		obj_dst;
	double		ray_obj_dst;
	t_posd		inter;
	t_posd		vec_obj;
	double		(*ft[4])(t_posd *inter, t_posd vec, t_ray *ray, t_info info);

	ft[0] = &ft_inter_sphere;
	ft[1] = &ft_inter_cylinder;
	ft[2] = &ft_inter_plane;
	ft[3] = &ft_inter_cone;
	info.obj = info.obj->first;
	while (info.obj)
	{
		curr_dst = 2147483647;
		if (ray->mode == TRUE || (ray->mode == FALSE
			&& info.obj->data != ray->obj))
			curr_dst = ft[info.obj->data->type](&inter, vec, ray, info);
		if (curr_dst < *dst)
		{
			ft_get_vec(ray->inter, inter,  &vec_obj);
			ft_norm(&vec_obj);
			obj_dst = ft_get_dst(inter, ray->inter);
			if (ray->obj)
				ray_obj_dst = ft_get_dst(ray->inter, info.lgt->data->coord);
			if ((ray_obj_dst > obj_dst && ft_get_sign(vec_obj, vec) == TRUE
					&& ray->mode == FALSE)
					|| ray->mode == TRUE)
				*dst = curr_dst;
			if (ray->mode == TRUE)
			{
				ray->obj = info.obj->data;
				ray->color = info.obj->data->color;
				ray->inter = inter;
				ray->d_ray = vec;
			}
		}
		info.obj = info.obj->next;
	}
	return (inter);
}

double	ft_get_specular(t_posd vec_lum, t_posd vec_cam, t_posd n)
{
	double	scal;
	double	specular;
	t_posd	vec_ref;

	ft_norm(&vec_lum);
	scal = ft_dot_prod(vec_lum, n);
	vec_ref.x = 2 * scal * n.x - vec_lum.x;
	vec_ref.y = 2 * scal * n.y - vec_lum.y;
	vec_ref.z = 2 * scal * n.z - vec_lum.z;
	ft_norm(&vec_ref);
	specular = ft_dot_prod(vec_ref, vec_ref);
	if (specular > ERR)
	{
		vec_ref.x = (1.0 / specular) * vec_ref.x;
		vec_ref.y = (1.0 / specular) * vec_ref.y;
		vec_ref.z = (1.0 / specular) * vec_ref.z;
		scal = (vec_ref.x) * vec_cam.x + (vec_ref.y) * vec_cam.y
			+ (vec_ref.z) * vec_cam.z;
		specular = (scal > ERR ? scal : 0.0);
		specular = pow(specular, 50);
	}
	return (specular);
}

void	ft_get_illum(double dst, t_posd vec, t_ray *ray, t_info info)
{
	double	new_dst;
	double	alpha;
	t_posd	vec_obj;

	(void)dst;
	alpha = 0.0;
	new_dst = 2147483647;
	ft_inter_obj(&new_dst, vec, ray, info);
	if (new_dst == 2147483647)
	{
		ft_get_vec(ray->obj->coord, ray->inter, &vec_obj);
		if (ray->obj->type == SPHERE)
			alpha = ft_dot_prod(vec_obj, vec);
		else if (ray->obj->type == CYLINDER)
		{
			alpha = ft_dot_prod(ray->normal, ray->d_ray);
			printf("alpha: %f\n", alpha);
		}
		else if (ray->obj->type == PLANE)
			alpha = 1.0 - (vec.x * vec.x + vec.y * vec.y);
		else if (ray->obj->type == CONE)
			alpha = (vec_obj.x * vec.x + vec_obj.z * vec.z)
				/ ft_get_dst(vec_obj, vec);
		alpha = (alpha < ERR || alpha > 1.0 ? 0.0 : alpha);
		if (ray->obj->type == SPHERE)
			ray->specular += ft_get_specular(vec, ray->d_ray, vec_obj);
		if (ray->obj->type == CYLINDER)
			ray->specular += ft_get_specular(vec, ray->d_ray, ray->normal);
	}
	ray->alpha += alpha;
}

void	ft_ini_ray(t_ray *ray, t_posd *color)
{
	color->x = 0.0;
	color->y = 0.0;
	color->z = 0.0;
	ray->mode = TRUE;
	ray->alpha = 0.0;
	ray->color.x = 0.0;
	ray->color.y = 0.0;
	ray->color.z = 0.0;
	ray->inter.x = 0.0;
	ray->inter.y = 0.0;
	ray->inter.z = 0.0;
	ray->specular = 0.0;
}

void	ft_raytrace(t_ray *ray, t_posd vec, t_info info)
{
	double	dst;
	t_posd	color;

	ft_ini_ray(ray, &color);
	dst = 2147483647;
	ft_inter_obj(&dst, vec, ray, info);
	ray->mode = FALSE;
	if (dst != 2147483647)
	{
		info.lgt = info.lgt->first;
		while (info.lgt)
		{
			dst = ft_get_vec(ray->inter, info.lgt->data->coord, &vec);
			ft_get_illum(dst, vec, ray, info);
			info.lgt = info.lgt->next;
		}
		ray->color.x = ray->color.x * (0.4 + 0.6 * ray->alpha)
			+ 0xFF * ray->specular;
		ray->color.y = ray->color.y * (0.4 + 0.6 * ray->alpha)
			+ 0xFF * ray->specular;
		ray->color.z = ray->color.z * (0.4 + 0.6 * ray->alpha)
			+ 0xFF * ray->specular;
		ray->color.x = (ray->color.x > 255.0 ? 255.0 : ray->color.x);
		ray->color.y = (ray->color.y > 255.0 ? 255.0 : ray->color.y);
		ray->color.z = (ray->color.z > 255.0 ? 255.0 : ray->color.z);
	}
}
