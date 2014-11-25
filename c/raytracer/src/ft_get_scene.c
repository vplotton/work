/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 17:46:39 by vplotton          #+#    #+#             */
/*   Updated: 2014/03/03 15:52:44 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"raytracer.h"

t_bool	ft_get_compound(int fd, char *input, t_data **data)
{
	t_bool	is_valid;
	int		i;
	char	**compound;
	t_bool	(*ft[4])(int fd, int type, t_data **data);

	i = -1;
	ft[0] = &ft_prs_scn;
	ft[1] = &ft_prs_cam;
	ft[2] = &ft_prs_obj;
	ft[3] = &ft_prs_lgt;
	is_valid = FALSE;
	compound = ft_strsplit(COMPOUND, '|');
	while (compound[++i])
	{
		if (ft_strcmp(compound[i], input) == 0
				&& (is_valid = ft[i](fd, i, data)))
			break ;
	}
	i = -1;
	while (compound[++i])
		ft_strdel(&(compound[i]));
	free(compound);
	return (is_valid);
}

t_bool	ft_get_scene(t_data **data, char *scene)
{
	char	*input;
	int		fd;
	t_bool	empty;
	t_bool	end;

	end = FALSE;
	empty = TRUE;
	if ((fd = open(scene, O_RDONLY)) < 2)
		return (ft_print_ferror(scene, 0));
	while (end == FALSE)
	{
		if ((input = ft_read_line(fd)) == NULL)
			end = TRUE;
		else
		{
			if (ft_get_compound(fd, input, data) == FALSE)
				return (FALSE); 
			ft_strdel(&input);
			empty = FALSE;
		}
	}
	if (empty == TRUE)
		return (ft_print_ferror(scene, 1));
	return (TRUE);
}
