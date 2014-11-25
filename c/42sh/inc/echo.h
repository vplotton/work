/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycharbo <cycharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 16:45:44 by cycharbo          #+#    #+#             */
/*   Updated: 2014/03/27 21:41:32 by cycharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ECHO_H
# define ECHO_H

# include "libft.h"

int		ft_echo(char **arg);
void	ft_simple_echo(char **str, int n, int i);
void	ft_echo_e(char **arg, int bol, int i);
void	ft_parse_echo(char **arg, int i);
int		ft_redir_echo(int bol, char last, char **arg, int i);
void	ft_print_echo(char c, int fd);
int		ft_fd_echo(void);
#endif
