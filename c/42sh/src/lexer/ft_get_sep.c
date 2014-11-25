/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_sep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 11:07:45 by vplotton          #+#    #+#             */
/*   Updated: 2014/02/26 19:59:55 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"lexer.h"

t_bool	ft_comma(t_llist **list, char *arg, int arg_type, int *i)
{
	if (arg_type == 0)
		ft_add_list(list, ft_strsub(arg, 0, 1), arg_type);
	(*i)++;
	return (TRUE);
}

t_bool	ft_and(t_llist **list, char *arg, int arg_type, int *i)
{
	t_bool	is_and;

	is_and = FALSE;
	if (arg[1] == '&')
		is_and = TRUE;
	ft_add_list(list, ft_strsub(arg, 0, 1 + is_and), arg_type);
	*i = *i + 1 + is_and;
	return (TRUE);
}

t_bool	ft_pipes(t_llist **list, char *arg, int arg_type, int *i)
{
	t_bool	is_or;

	is_or = FALSE;
	if (arg[1] == '|')
		is_or = TRUE;
	ft_add_list(list, ft_strsub(arg, 0, 1 + is_or), arg_type - is_or);
	*i = *i + 1 + is_or;
	return (TRUE);
}

t_bool	ft_rft_r(t_llist **list, char *arg, int arg_type, int *i)
{
	if (arg[1] == RFT_R)
	{
		ft_add_list(list, ft_strsub(arg, 0, 2), arg_type + 2);
		(*i)++;
	}
	else
		ft_add_list(list, ft_strsub(arg, 0, 1), arg_type);
	(*i)++;
	return (TRUE);
}

t_bool	ft_rft_l(t_llist **list, char *arg, int arg_type, int *i)
{
	if (arg[1] == RFT_L)
	{
		ft_add_list(list, ft_strsub(arg, 0, 2), arg_type + 2);
		(*i)++;
	}
	else
		ft_add_list(list, ft_strsub(arg, 0, 1), arg_type);
	(*i)++;
	return (TRUE);
}
