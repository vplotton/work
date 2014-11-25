/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 14:15:29 by vplotton          #+#    #+#             */
/*   Updated: 2014/03/03 11:47:56 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"raytracer.h"

double	ft_is_int(char *s)
{
	int		i;
	int		output;

	i = (s[0] == '-' ? 0 : -1);
	output = -2147483648;
	if (!s)
		return (output);
	while (s[++i])
	{
		if (ft_isdigit(s[i]) == FALSE)
			return (output);
	}
	output = ft_atoi(s);
	return ((double)output);
}

double	ft_is_double(char *s)
{
	t_bool	dot;
	int		i;
	int		j;
	int		dec;
	double	output;

	dot = 0;
	dec = 1;
	i = (s[0] == '-' ? 0 : -1);
	output = -2147483648;
	while (s[++i])
	{
		if (s[i] == '.' && dot++ == 0 && (j = i))
			continue ;
		if (ft_isdigit(s[i]) == FALSE)
			return (output);
		if (dot)
			dec = dec * 10;
	}
	if (dot == 0)
		return (output);
	output = (double)ft_atoi(s);
	output = output + (double)ft_atoi(s + j + 1) / dec;
	return (output);
}
