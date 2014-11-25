/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 18:56:39 by vplotton          #+#    #+#             */
/*   Updated: 2014/03/27 18:57:06 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"lexer.h"

t_bool	ft_has_redir(t_ast *ast, t_bool mode)
{
	ast = ast->first;
	while (42)
	{
		if ((ast->type == T_RFR || ast->type == T_RFRR) && mode == 0)
			return (TRUE);
		if (ast->type == T_RFL && mode == 1)
			return (TRUE);
		if (!ast->next)
			break ;
		ast = ast->next;
	}
	return (FALSE);
}
