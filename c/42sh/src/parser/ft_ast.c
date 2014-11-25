/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 14:46:14 by vplotton          #+#    #+#             */
/*   Updated: 2014/03/18 14:48:42 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"lexer.h"

void	ft_add_ast(t_ast **ast, int type)
{
	t_ast	*new;

	new = (t_ast*)ft_memalloc(sizeof(t_ast));
	new->down = NULL;
	new->next = NULL;
	new->first = (*ast ? (*ast)->first : new);
	new->type = type;
	new->file = NULL;
	new->cmd = NULL;
	if (*ast)
		(*ast)->next = new;
	*ast = new;
}

void	ft_add_file(t_ast **ast, t_llist *list)
{
	if (!list)
		return ;
	ft_add_ast(ast, list->prev->arg_type);
	(*ast)->file = ft_strsub(list->arg, 0, ft_strlen(list->arg));
}

void	ft_add_cmd(t_ast **ast, t_llist **list, t_bool *cmd)
{
	t_llist	*tmp;
	int		i;
	int		size;

	i = -1;
	size = 1;
	*cmd = TRUE;
	ft_add_ast(ast, T_CMD);
	if (!(*list))
		return ;
	tmp = *list;
	while ((tmp = tmp->next) != NULL && tmp->arg_type == T_CMD
			&& tmp->arg_type != STOP)
		size++;
	(*ast)->cmd = (char**)ft_memalloc((size + 1) * sizeof(char *));
	while (++i < size)
	{
		(*ast)->cmd[i] = ft_strsub((*list)->arg, 0, ft_strlen((*list)->arg));
		if (i + 1 == size)
			break ;
		*list = (*list)->next;
	}
}

void	ft_delete_ast(t_ast **ast, int side)
{
	int		i;
	t_ast	*tmp;

	i = -1;
	if (ast && *ast)
	{
		if (side == 1)
			*ast = (*ast)->first;
		if ((*ast)->down)
			ft_delete_ast(&(*ast)->down, 1);
		tmp = (*ast)->next;
		if ((*ast)->cmd)
		{
			while ((*ast)->cmd[++i])
				ft_strdel(&((*ast)->cmd[i]));
			free((*ast)->cmd);
		}
		if ((*ast)->file)
			ft_strdel(&((*ast)->file));
		free(*ast);
		*ast = NULL;
		if (tmp)
			ft_delete_ast(&tmp, 2);
	}
}
