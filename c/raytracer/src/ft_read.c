/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 18:47:06 by vplotton          #+#    #+#             */
/*   Updated: 2014/03/03 12:48:36 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"raytracer.h"

char	*ft_read_line(int fd)
{
	char	buf;
	char	*input;
	char	*tmp;
	int		i;

	i = 1;
	input = NULL;
	buf = '\0';
	while (read(fd, &buf, 1))
	{
		if (buf == '\n' || buf == '\0')
			break ;
		tmp = input;
		input = ft_memalloc(i + 1);
		input = (tmp ? ft_strcpy(input, tmp) : input);
		input[i++ - 1] = buf;
		if (tmp)
			ft_strdel(&tmp);
	}
	tmp = input;
	input = ft_strtrim(input);
	if (tmp)
		ft_strdel(&tmp);
	return (input);
}
