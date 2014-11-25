/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 14:52:44 by vplotton          #+#    #+#             */
/*   Updated: 2014/03/27 14:38:42 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"lexer.h"

t_bool	ft_construct_entry_file(int *entry, t_ast *ast)
{
	while (42)
	{
		if (ast->type == T_RFL)
		{
			if (ft_file_to_tmp(ast->file) == FALSE)
				return (FALSE);
		}
		if (!ast->next)
			break ;
		ast = ast->next;
	}
	if ((*entry = open(".tmp", O_RDONLY)) == -1)
		return (FALSE);
	return (TRUE);
}

t_bool	ft_construct_output_file(t_ast *ast)
{
	while (42)
	{
		if (ast->type == T_RFR)
		{
			if (ft_tmp_to_file(ast->file) == FALSE)
				return (FALSE);
		}
		if (ast->type == T_RFRR)
		{
			if (ft_tmp_dr_to_file(ast->file) == FALSE)
				return (FALSE);
		}
		if (!ast->next)
			break ;
		ast = ast->next;
	}
	return (TRUE);
}

t_bool	ft_file_to_tmp(char *file)
{
	int		fd_tmp;
	int		fd;
	char	c;

	if ((fd = open(file, O_RDONLY)) < 2)
	{
		ft_putendl_fd("open error in >> : tmp fail", 2);
		return (FALSE);
	}
	if ((fd_tmp = ft_mk_tmp(TRUE)) == -1)
	{
		ft_putendl_fd("Couldn't create tmp", 2);
		return (FALSE);
	}
	while (read(fd, &c, 1) > 0)
		write(fd_tmp, &c, 1);
	if (close (fd) == -1)
	{
		ft_putendl_fd("close error in >> : tmp fail", 2);
		return (FALSE);
	}
	if (close (fd_tmp) == -1)
		return (FALSE);
	return (TRUE);
}

t_bool	ft_tmp_to_file(char *file)
{
	int		fd_tmp;
	int		fd;
	char	c;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if ((fd_tmp = open(".tmp", O_RDONLY)) == -1)
	{
		ft_putendl_fd("Couldn't create tmp", 2);
		return (FALSE);
	}
	if (fd <= 0)
	{
		ft_putendl_fd("open error in >> : tmp fail", 2);
		return (FALSE);
	}
	while (read(fd_tmp, &c, 1) > 0)
		write(fd, &c, 1);
	if (close (fd) == -1)
	{
		ft_putendl_fd("close error in >> : tmp fail", 2);
		return (FALSE);
	}
	if (close(fd_tmp) == -1)
		return (FALSE);
	return (TRUE);
}

t_bool	ft_tmp_dr_to_file(char *file)
{
	int		fd_tmp;
	int		fd;
	char	c;

	fd = open(file, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if ((fd_tmp = open(".tmp", O_RDONLY)) == -1)
	{
		ft_putendl_fd("Couldn't create tmp", 2);
		return (FALSE);
	}
	if (fd < 1)
	{
		ft_putendl_fd("open error in >> : tmp fail", 2);
		return (FALSE);
	}
	while (read(fd_tmp, &c, 1) > 0)
		write(fd, &c, 1);
	if (close (fd) == -1)
	{
		ft_putendl_fd("close error in >> : tmp fail", 2);
		return (FALSE);
	}
	if (close(fd_tmp) == -1)
		return (FALSE);
	return (1);
}
