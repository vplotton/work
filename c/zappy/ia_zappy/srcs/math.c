/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 13:08:37 by vplotton          #+#    #+#             */
/*   Updated: 2014/06/04 22:15:36 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ia_zappy.h"

double	get_dst(t_ipos p1, t_ipos p2)
{
	double	dst;

	dst = sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
	return (dst);
}

t_dpos	get_vec(t_ipos p1, t_ipos p2)
{
	double	norm;
	t_dpos	vec;

	vec.x = p2.x - p1.x;
	vec.y = p2.y - p1.y;
	norm = sqrt(vec.x * vec.x + vec.y * vec.y);
	vec.x = vec.x / norm;
	vec.y = vec.y / norm;
	return (vec);
}

double	dot_prod(t_ipos vec1, t_dpos vec2)
{
	double  scal;

	scal = (double)vec1.x * vec2.x + (double)vec1.y * vec2.y;
	return (scal);
}
