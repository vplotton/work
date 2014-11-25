/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 21:19:57 by cycharbo          #+#    #+#             */
/*   Updated: 2014/03/27 21:32:29 by cycharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lexer.h"
#include "echo.h"
#include "meh.h"

int			ft_fd_echo(void)
{
	int		fd;

	fd = ft_mk_tmp(TRUE);
	session.entry = fd;
	return (fd);
}
