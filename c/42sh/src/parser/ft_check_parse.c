/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 16:39:41 by vplotton          #+#    #+#             */
/*   Updated: 2014/03/17 19:03:12 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"lexer.h"

t_bool	ft_check_com(t_llist *list, t_llist *left, t_ast **ast)
{
	if (list->arg_type == T_COM)
	{
		if (!list->prev || !list->next)
			return (ft_print_prserr(list->next));
		if ((list->prev->arg_type | list->next->arg_type) != T_CMD)
			return (ft_print_prserr(list->next));
		return (ft_check_next(list, left, ast, T_COM));
	}
	return (CONTINUE);
}

t_bool	ft_check_and(t_llist *list, t_llist *left, t_ast **ast)
{
	if (list->arg_type == T_AND)
	{
		if (!list->prev || !list->next)
			return (ft_print_prserr(list->next));
		if ((list->prev->arg_type | list->next->arg_type) != T_CMD)
			return (ft_print_prserr(list->next));
		return (ft_check_next(list, left, ast, T_AND));
	}
	return (CONTINUE);
}

t_bool	ft_check_or(t_llist *list, t_llist *left, t_ast **ast)
{
	if (list->arg_type == T_OR)
	{
		if (!list->prev || !list->next)
			return (ft_print_prserr(list->next));
		if ((list->prev->arg_type | list->next->arg_type) != T_CMD)
			return (ft_print_prserr(list->next));
		return (ft_check_next(list, left, ast, T_OR));
	}
	return (CONTINUE);
}

t_bool	ft_check_pip(t_llist *list, t_llist *left, t_ast **ast)
{
	if (list->arg_type == T_PIP)
	{
		if (!list->prev || !list->next)
			return (ft_print_prserr(list->next));
		if ((list->prev->arg_type | list->next->arg_type) != T_CMD)
			return (ft_print_prserr(list->next));
		return (ft_check_next(list, left, ast, T_PIP));
	}
	return (CONTINUE);
}

t_bool	ft_check_cmd(t_llist *list, t_llist *left, t_ast **ast)
{
	t_bool	cmd;

	cmd = FALSE;
	while (list && list->arg_type != STOP)
	{
		if (list->arg_type == T_CMD && left)
			ft_add_cmd(ast, &list, &cmd);
		else if (list->arg_type == T_RFL || list->arg_type == T_RFR
				|| list->arg_type == T_RFRR)
		{
			if ((list = list->next) && list->arg_type == T_CMD)
			{
				if (cmd == TRUE && list->next && list->next->arg_type == T_CMD)
					return (ft_print_prserr(list));
				ft_add_file(ast, list);
			}
			else
				return (ft_print_prserr(list));
		}
		if (list && list->arg_type != STOP)
			list = list->next;
	}
	*ast = (*ast)->first;
	return (TRUE);
}
