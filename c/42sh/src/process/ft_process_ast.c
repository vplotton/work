/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_ast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 18:20:13 by vplotton          #+#    #+#             */
/*   Updated: 2014/03/27 17:22:32 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"lexer.h"
#include	<sys/types.h>

t_bool	ft_process_com(t_ast *ast)
{
	int		wait;

	wait = 0;
	while (ast->type == T_COM)
	{
		if (ast->down)
			ft_process_ast(ast->down);
		else if (ast->next)
		{
			ft_process_ast(ast->next);
			break ;
		}
		ast = ast->next;
	}
	while (wait != -1)
		wait = waitpid(-1, NULL, 0);
	return (TRUE);
}

t_bool	ft_process_and(t_ast *ast)
{
	int		wait;

	wait = 0;
	while (ast->type == T_AND)
	{
		if (ast->down && ft_process_ast(ast->down) == FALSE)
			break ;
		else if (ast->next)
		{
			ft_process_ast(ast->next);
			break ;
		}
		ast = ast->next;
	}
	while (wait != -1)
		wait = waitpid(-1, NULL, 0);
	return (TRUE);
}

t_bool	ft_process_or(t_ast *ast)
{
	int		wait;

	wait = 0;
	while (ast->type == T_OR)
	{
		if (ast->down && ft_process_ast(ast->down) == TRUE)
			break ;
		else if (ast->next)
		{
			ft_process_ast(ast->next);
			break ;
		}
		ast = ast->next;
	}
	while (wait != -1)
		wait = waitpid(-1, NULL, 0);
	return (TRUE);
}

t_bool	ft_process_nopipe(t_ast *ast, int *curr_pipe)
{
	int		wait;

	wait = 0;
	if (ft_process_cmd(ast, curr_pipe, FALSE) == FALSE)
		return (FALSE);
	while (wait != -1)
		wait = waitpid(-1, NULL, 0);
	return (TRUE);
}

t_bool	ft_process_pip(t_ast *ast)
{
	int		curr_pipe;
	int		wait;

	wait = 0;
	curr_pipe = 0;
	if (ast->type == T_PIP)
	{
		ft_process_cmd(ast->down, &curr_pipe, TRUE);
		ast = ast->next;
	}
	else
		return (ft_process_nopipe(ast, &curr_pipe));
	while (ast->next->next)
	{
		if (ast->down)
			ft_process_cmd(ast->down, &curr_pipe, TRUE);
		ast = ast->next;
	}
	if (ft_process_cmd(ast->next, &curr_pipe, FALSE) == FALSE)
		return (FALSE);
	while (wait != -1)
		wait = waitpid(-1, NULL, 0);
	return (TRUE);
}
