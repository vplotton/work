/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 17:33:40 by vplotton          #+#    #+#             */
/*   Updated: 2014/03/25 19:43:26 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"raytracer.h"

int		main(int ac, char **av)
{
	t_data	*data;
	t_info	info;

	data = NULL;
	if (ac == 2)
	{
		if (ft_get_scene(&data, av[1]) == FALSE)
			return (FALSE);
		data = data->first;
		if (ft_check_scene(data) == FALSE)
			return (FALSE);
		ft_get_info(&info, &data);
		ft_compute(info);
	}
	else
		ft_putendl_fd("Usage : ./raytracer [maps/map]", 2);
	return (0);
}
