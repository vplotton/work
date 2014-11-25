/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 20:36:10 by vplotton          #+#    #+#             */
/*   Updated: 2014/03/03 15:57:25 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"raytracer.h"

t_bool	ft_first_check(int fd, int type, t_data **data)
{
	char	*input;

	if ((input = ft_read_line(fd)) == NULL)
		return (ft_print_prserror(0, T_SCN));
	if (input[0] != '{' && input[1] != '\0')
		return (ft_print_prserror(1, T_SCN));
	ft_strdel(&input);
	ft_add_data(data, type);
	return (TRUE);
}

t_bool	ft_check_posd(char *input, char *compound, t_data **data)
{
	int		i;
	double	nb;
	char	**posd;
	t_posd	tmp;

	i = -1;
	posd = ft_strsplit(input + 7, ' ');
	input[5] = '\0';
	while (posd[++i])
	{
		if (i == 0 && (nb = tmp.x = ft_is_double(posd[i])) == -2147483648)
			break ;
		if (i == 1 && (nb = tmp.y = ft_is_double(posd[i])) == -2147483648)
			break ;
		if (i == 2 && (nb = tmp.z = ft_is_double(posd[i])) == -2147483648)
			break ;
	}
	i = -1;
	while (posd[++i])
		ft_strdel(&(posd[i]));
	free(posd);
	if (i > 3 || nb == -2147483648)
		return (FALSE);
	ft_get_data(data, compound, input, tmp);
	return (TRUE);
}

t_bool	ft_check_size(char *input, char *compound, t_data **data)
{
	t_posd	tmp;

	input[6] = '\0';
	if ((tmp.x = ft_is_double(input + 8)) == -2147483648)
		return (FALSE);
	ft_get_data(data, compound, input, tmp);
	return (TRUE);
}

t_bool	ft_check_type(char *input, char *compound, t_data **data)
{
	t_bool	is_valid;
	int		i;
	char	**type;
	t_posd	tmp;

	i = -1;
	is_valid = FALSE;
	type = ft_strsplit(FORM, '|');
	input[4] = '\0';
	while (type[++i])
	{
		if (ft_strcmp(type[i], input + 6) == 0 && (is_valid = TRUE))
			tmp.x = i;
	}
	ft_get_data(data, compound, input, tmp);
	i = -1;
	while (type[++i])
		ft_strdel(&(type[i]));
	free(type);
	return (is_valid);
}

t_bool	ft_check_name(char *input, char *compound, t_data **data)
{
	t_bool	has_quote;
	int		i;
	t_posd	tmp;

	has_quote = (input[6] == '\"' ? TRUE : FALSE);
	input[4] = '\0';
	i = 6 + has_quote;
	while (input[++i])
	{
		if (has_quote && input[i] == '\"')
		{
			if (input[i + 1] != '\0')
				return (ft_print_prserror(3, compound));
			break ;
		}
		if (ft_strchr(NAME_CHARS, input[i]) == NULL)
			return (ft_print_prserror(3, compound));
	}
	ft_get_data(data, compound, input, tmp);
	return (TRUE);
}
