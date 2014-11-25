/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 17:40:11 by vplotton          #+#    #+#             */
/*   Updated: 2014/03/25 21:23:38 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"raytracer.h"

int		ft_expose_hook(t_info *info)
{
	mlx_put_image_to_window(info->mlx_ptr, info->mlx_win, info->img, 0, 0);
	return (1);
}
#include	<stdio.h>
void	ft_compute_scene(t_info *info)
{
	t_cam	*cam;
	t_posd	coord;
	t_posd	vec;
	t_ray	ray;

	ray.obj = NULL;
	cam = info->cam->data;
	coord.y = 0.0;
	while (coord.y < info->winsz.y)
	{
		coord.x = 0.0;
		while (coord.x < info->winsz.x)
		{
			vec.x = (coord.x - cam->coord.x) * info->pitch.x;
			vec.y = (coord.y - cam->coord.y) * info->pitch.y;
			vec.z = - cam->coord.z;
			/* Funny map	info->cam->data->d_vec.z = info->cam->data->d_vec.z + 0.01 * PI;*/
			ft_rotate_x(&vec, info->cam->data->d_vec.x);
			ft_rotate_y(&vec, info->cam->data->d_vec.y);
			ft_rotate_z(&vec, info->cam->data->d_vec.z);
			ft_norm(&vec);
			ft_raytrace(&ray, vec, *info);
			ft_draw_point(ray.color, info);
			coord.x = coord.x + 1.0;
		}
		coord.y = coord.y + 1.0;
	}
}

void	ft_compute_cam(t_info *info)
{
	while (info->cam)
	{
		ft_compute_scene(info);
		info->cam = info->cam->next;
	}
}

void	ft_compute(t_info info)
{
	if ((info.mlx_ptr = mlx_init()) == NULL)
	{
		ft_putendl_fd("Couldn't create window", 2);
		exit(0);
	}
	if ((info.mlx_win = mlx_new_window(info.mlx_ptr
					, info.winsz.x, info.winsz.y, info.name)) == NULL)
	{
		ft_putendl_fd("Couldn't create window", 2);
		exit(0);
	}
	info.img = mlx_new_image(info.mlx_ptr, info.winsz.x, info.winsz.y);
	info.d_img = ft_get_img(info);
	if (!info.d_img)
	{
		ft_putendl_fd("Error", 2);
		exit(0);
	}
	ft_compute_cam(&info);
	mlx_put_image_to_window(info.mlx_ptr, info.mlx_win, info.img, 0, 0);
	mlx_expose_hook(info.mlx_win, &ft_expose_hook, &info);
	mlx_loop(info.mlx_ptr);
}
