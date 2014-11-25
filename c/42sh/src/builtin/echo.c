/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 14:22:02 by cycharbo          #+#    #+#             */
/*   Updated: 2014/03/27 21:56:06 by cycharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "echo.h"
#include <unistd.h>
#include "lexer.h"
#include "meh.h"

void		ft_print_echo(char c, int fd)
{
	if (c == 92)
	{
		write(fd, "\\", 1);
	}
	else
		write(fd, &c, 1);
}

void		ft_simple_echo(char **str, int n, int i)
{
	int		j;
	int		fd;

	if (session.has_pipe == FALSE)
		fd = 1;
	else
		fd = ft_fd_echo();
	j = 0;
	while (str && str[i])
	{
		if (i > 1 && str[i - 1][j] != '-')
			write(fd, " ", 1);
		j = 0;
		while (str[i][j] != '\0')
		{
			if (str[i][j] && *str[i] == '\\')
				j++;
			ft_print_echo(str[i][j], fd);
			j++;
		}
		i++;
	}
	if (n == 0)
		write(fd, "\n", 1);
}

int			ft_check_e_arg(char **arg, int	*bol, char *last, int i)
{
	int		last_bol;
	char	last_c;
	int		j;

	j = 1;
	last_c = *last;
	last_bol = *bol;
	while (arg[i][j] != '\0')
	{
		if (arg[i][j] == 'n')
			*bol = 1;
		else if (arg[i][j] == 'E')
			*last = 'E';
		else
		{
			if (last_bol == 0)
				*bol = 0;
			*last = last_c;
			return (0);
		}
		j++;
	}
	return (1);
}

void		ft_parse_echo(char **arg, int i)
{
	char	last;
	int		bol;

	last = 'D';
	bol = 0;
	while (arg[i] && arg[i][0] == '-' && arg[i][1])
	{
		if (ft_check_e_arg(arg, &bol, &last, i) == 0)
			break ;
		i++;
	}
	ft_simple_echo(arg, bol, i);
}

int			ft_echo(char **arg)
{
	if (arg)
	{
		if (!arg[1] || *arg[1] != '-')
			ft_simple_echo(arg, 0, 1);
		else
			ft_parse_echo(arg, 1);
		return (1);
	}
	return (1);
}
