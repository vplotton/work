/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 19:52:30 by cycharbo          #+#    #+#             */
/*   Updated: 2014/06/26 19:52:58 by cycharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy_graph.h"

static int		calcx(int x, int y, int resize)
{
	x = (x * resize) + 500;
	y = (y * resize);
	return ((0.9 * x - 0.9 * y));
}

static int		calcy(int x, int y, int z, int resize)
{
	x = (x * resize) + 500;
	y = (y * resize);
	return ((-z * 3 + (0.9 / 2) * x + (0.9 / 2) * y));
}

t_point			convert(int x, int y, int z)
{
	t_point		pt;
	int			resize;

	resize = 50;
	pt.x = calcx(x, y, resize);
	pt.y = calcy(x, y, z, resize);
	pt.z = z;
	return (pt);
}
