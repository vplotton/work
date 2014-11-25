/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 19:29:30 by vplotton          #+#    #+#             */
/*   Updated: 2014/02/27 21:57:46 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"raytracer.h"

t_bool	ft_print_prserror(int code, char *compound)
{
	ft_putstr_fd("In ", 2);
	ft_putstr(compound);
	if (code == 0)
		ft_putendl_fd(": file not complete.", 2);
	if (code == 1)
		ft_putendl_fd(": parsing not valid near `{'", 2);
	if (code == 2)
		ft_putendl_fd(": unexpected end of file", 2);
	if (code == 3)
		ft_putendl_fd(": name not valid", 2);
	return (FALSE);
}

t_bool	ft_print_ferror(char *s, int code)
{
	if (s)
		ft_putstr_fd(s, 2);
	if (code == 0)
		ft_putendl_fd(": no such file.", 2);
	if (code == 1)
		ft_putendl_fd(": empty file.", 2);
	if (code == 2)
		ft_putendl_fd(": parse error.", 2);
	return (FALSE);
}
