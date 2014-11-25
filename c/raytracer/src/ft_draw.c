/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 16:12:30 by vplotton          #+#    #+#             */
/*   Updated: 2014/03/18 20:06:27 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"raytracer.h"

char	*ft_get_img(t_info info)
{
	char	*output;
	int		size_line;
	int		endian;
	int		bpp;

	output = mlx_get_data_addr(info.img, &bpp, &size_line, &endian);
	return (output);
}

void	ft_draw_point(t_posd color, t_info *info)
{
	static int		cpt = 0;

	if (cpt == info->winsz.y * info->winsz.x * 4)
		cpt = 0;
	info->d_img[cpt] = color.z;
	info->d_img[cpt + 1] = color.y;
	info->d_img[cpt + 2] = color.x;
	info->d_img[cpt + 3] = 0;
	cpt = cpt + 4;
}
