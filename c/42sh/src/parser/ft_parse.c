/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 17:56:46 by vplotton          #+#    #+#             */
/*   Updated: 2014/03/26 18:59:37 by cycharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"lexer.h"

t_bool	ft_check_next(t_llist *list, t_llist *left, t_ast **ast, int arg_type)
{
	t_ast	*tmp;

	tmp = NULL;
	tmp = *ast;
	if (!(*ast) || (*ast && arg_type != (*ast)->type))
		ft_add_ast(ast, arg_type);
	if (*ast && arg_type != (*ast)->type)
		tmp->down = *ast;
	tmp = *ast;
	ft_add_ast(ast, arg_type);
	if (ft_get_next(list->next, ast, arg_type) == FALSE)
		return (FALSE);
	list->arg_type = STOP;
	if (ft_get_next(left, &(tmp->down), arg_type + 1) == FALSE)
		return (FALSE);
	return (TRUE);
}

t_bool	ft_parse(t_llist *list, t_ast **ast, int arg_type)
{
	t_llist	*left;
	t_bool	(*ft[5])(t_llist *list, t_llist *left, t_ast **ast);
	int		ret;

	ft[0] = &ft_check_com;
	ft[1] = &ft_check_and;
	ft[2] = &ft_check_or;
	ft[3] = &ft_check_pip;
	ft[4] = &ft_check_cmd;
	left = list;
	while (list && list->arg_type != STOP)
	{
		if ((ret = ft[arg_type](list, left, ast)) == FALSE)
			return (FALSE);
		if (ret == TRUE)
			return (TRUE);
		list = list->next;
	}
	return (CONTINUE);
}

t_bool	ft_get_next(t_llist *list, t_ast **ast, int start)
{
	int		ret;

	while (start < 5)
	{
		if ((ret = ft_parse(list, ast, start)) == CONTINUE)
			start++;
		else if (ret == FALSE)
			return (FALSE);
		else
			return (TRUE);
	}
	return (FALSE);
}

t_bool	ft_get_ast(t_llist **list, t_ast **ast)
{
	t_bool	is_valid;

	is_valid = ft_get_next(*list, ast, T_COM);
	ft_delete_list(list);
	if (is_valid == FALSE && *ast)
		ft_delete_ast(ast, 1);
	return (is_valid);
}
