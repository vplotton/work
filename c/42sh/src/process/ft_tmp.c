/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 15:36:47 by vplotton          #+#    #+#             */
/*   Updated: 2014/03/27 15:48:00 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"tmp.h"

t_bool	ft_pipe_to_tmp(int *pipe, t_bool has_pipe)
{
	int		fd_tmp;
	char	c;

	if ((fd_tmp = ft_mk_tmp(TRUE)) == -1)
		return (FALSE);
	while (read(*pipe, &c, 1) > 0)
		write(fd_tmp, &c, 1);
	if (*pipe != -1 && close (*pipe) == -1)
	{
		ft_putendl_fd("close error in >> : tmp fail", 2);
		return (FALSE);
	}
	if (has_pipe == FALSE && close (fd_tmp) == -1)
		return (FALSE);
	else
	{
		close(fd_tmp);
		if ((fd_tmp = open(".tmp", O_RDONLY)) == -1)
			return (FALSE);
		*pipe = fd_tmp;
	}
	return (TRUE);
}

t_bool	ft_read_tmp(void)
{
	int		fd_tmp;
	char	c;

	if ((fd_tmp = open(".tmp", O_RDONLY)) == -1)
		return (FALSE);
	while (read(fd_tmp, &c, 1) > 0)
		write(1, &c, 1);
	if (close (fd_tmp) == -1)
		return (FALSE);
	return (TRUE);
}

int		ft_mk_tmp(t_bool append)
{
	int		fd_tmp;

	if (append == TRUE)
	{
		fd_tmp = open(".tmp", O_RDWR | O_CREAT | O_APPEND, 0644);
		if (fd_tmp == -1)
			return (-1);
	}
	else
	{
		if ((fd_tmp = open(".tmp", O_RDWR | O_CREAT, 0644)) == -1)
			return (-1);
	}
	return (fd_tmp);
}

t_bool	ft_del_tmp(char *tmp_name)
{
	if (unlink(tmp_name) == -1)
		return (-1);
	return (1);
}
