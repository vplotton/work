/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 13:13:01 by vplotton          #+#    #+#             */
/*   Updated: 2014/03/13 17:11:00 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"raytracer.h"

t_bool	ft_check_scn(t_data *data)
{
	static int	scn_nb = 0;

	if (scn_nb > 0)
		return (FALSE);
	if (data->name == NULL)
		return (FALSE);
	if (data->scn->winsz.x < 320)
		return (FALSE);
	if (data->scn->winsz.y < 240)
		return (FALSE);
	scn_nb++;
	return (TRUE);
}

t_bool	ft_check_cam(t_data *data)
{
	static int	cam_nb = 0;

	(void)data;
	if (cam_nb > 0)
		return (FALSE);
	cam_nb++;
	return (TRUE);
}

t_bool	ft_check_obj(t_data *data)
{
	(void)data;
	return (TRUE);
}

t_bool	ft_check_lgt(t_data *data)
{
	static int	lgt_nb = 0;

	(void)data;
	if (lgt_nb > 1)
		return (FALSE);
	lgt_nb++;
	return (TRUE);
}

t_bool	ft_check_scene(t_data *data)
{
	t_bool	is_valid;
	int		i;
	t_bool	(*ft[4])(t_data *data);

	is_valid = FALSE;
	ft[0] = &ft_check_scn;
	ft[1] = &ft_check_cam;
	ft[2] = &ft_check_obj;
	ft[3] = &ft_check_lgt;
	while (42)
	{
		i = -1;
		while (++i < 4)
		{
			if (data->type == i)
			{
				is_valid = ft[i](data);
				break ;
			}
		}
		if (!data->next)
			break ;
		data = data->next;
	}
	return (is_valid);
}
