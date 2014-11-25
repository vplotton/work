/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 20:03:25 by vplotton          #+#    #+#             */
/*   Updated: 2014/03/03 15:49:58 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"raytracer.h"

t_bool	ft_parse(char *input, char *compound, char **args, t_data **data)
{
	t_bool	is_valid;
	int		i;
	t_bool	(*ft[8])(char *input, char *compound, t_data **data);

	i = -1;
	is_valid = FALSE;
	ft[0] = &ft_check_name;
	ft[1] = &ft_check_posd;
	ft[2] = &ft_check_size;
	ft[3] = &ft_check_posd;
	ft[4] = &ft_check_posd;
	ft[5] = &ft_check_posd;
	ft[6] = &ft_check_size;
	ft[7] = &ft_check_type;
	while (args[++i])
	{
		if (ft_strncmp(args[i], input, ft_strlen(args[i])) == 0)
		{
			is_valid = ft[i](input, compound, data);
			break ;
		}
	}
	return (is_valid);
}

t_bool	ft_prs_scn(int fd, int type, t_data **data)
{
	t_bool	is_valid;
	int		i;
	char	*input;
	char	**args;

	i = -1;
	is_valid = FALSE;
	args = ft_strsplit(V_SCN, '|');
	if (ft_first_check(fd, type, data) == FALSE)
		return (FALSE);
	while ((input = ft_read_line(fd)) && input[0] != '}' && input[1] != '\0')
	{
		if (input == NULL)
			return (ft_print_prserror(2, T_SCN));
		else if ((is_valid = ft_parse(input, T_SCN, args, data)) == FALSE)
			break ;
		ft_strdel(&input);
	}
	while (args[++i])
		ft_strdel(&(args[i]));
	free(args);
	if (input)
		ft_strdel(&input);
	return (is_valid);
}

t_bool	ft_prs_cam(int fd, int type, t_data **data)
{
	t_bool  is_valid;
	int     i;
	char	*input;
	char	**args;

	i = -1;
	is_valid = FALSE;
	args = ft_strsplit(V_CAM, '|');
	if (ft_first_check(fd, type, data) == FALSE)
		return (FALSE);
	while ((input = ft_read_line(fd)) && input[0] != '}' && input[1] != '\0')
	{
		if (input == NULL)
			return (ft_print_prserror(2, T_CAM));
		else if ((is_valid = ft_parse(input, T_CAM, args, data)) == FALSE)
			break ;
		ft_strdel(&input);
	}
	while (args[++i])
		ft_strdel(&(args[i]));
	free(args);
	if (input)
		ft_strdel(&input);
	return (is_valid);
}

t_bool	ft_prs_obj(int fd, int type, t_data **data)
{
	t_bool  is_valid;
	int     i;
	char	*input;
	char	**args;

	i = -1;
	is_valid = FALSE;
	args = ft_strsplit(V_OBJ, '|');
	if (ft_first_check(fd, type, data) == FALSE)
		return (FALSE);
	while ((input = ft_read_line(fd)) && input[0] != '}' && input[1] != '\0')
	{
		if (input == NULL)
			return (ft_print_prserror(2, T_OBJ));
		else if ((is_valid = ft_parse(input, T_OBJ, args, data)) == FALSE)
			break ;
		ft_strdel(&input);
	}
	while (args[++i])
		ft_strdel(&(args[i]));
	free(args);
	if (input)
		ft_strdel(&input);
	return (is_valid);
}

t_bool	ft_prs_lgt(int fd, int type, t_data **data)
{
	t_bool  is_valid;
	int     i;
	char	*input;
	char	**args;

	i = -1;
	is_valid = FALSE;
	args = ft_strsplit(V_LGT, '|');
	if (ft_first_check(fd, type, data) == FALSE)
		return (FALSE);
	while ((input = ft_read_line(fd)) && input[0] != '}' && input[1] != '\0')
	{
		if (input == NULL)
			return (ft_print_prserror(2, T_LGT));
		else if ((is_valid = ft_parse(input, T_LGT, args, data)) == FALSE)
			break ;
		ft_strdel(&input);
	}
	while (args[++i])
		ft_strdel(&(args[i]));
	free(args);
	if (input)
		ft_strdel(&input);
	return (is_valid);
}
