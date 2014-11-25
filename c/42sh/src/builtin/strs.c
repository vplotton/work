/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-goug <ele-goug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 21:37:09 by ele-goug          #+#    #+#             */
/*   Updated: 2014/03/27 21:37:15 by ele-goug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <meh.h>

void		ft_putstrs(char **sa)
{
	while (*sa != NULL)
	{
		ft_putstr(*sa++);
		write(1, "\n", 1);
	}
}

void		ft_putstrs_fd(char **sa, int fd)
{
	while (*sa != NULL)
	{
		ft_putstr_fd(*sa++, fd);
		write(fd, "\n", 1);
	}
}

void		ft_rem(char **in)
{
	char	**cin;

	cin = in;
	while (*cin)
		free(*cin++);
	free(in);
}

size_t		ft_strslen(char **sa)
{
	size_t		i;

	i = 0;
	while (sa[i] != NULL)
		i++;
	return (i);
}
