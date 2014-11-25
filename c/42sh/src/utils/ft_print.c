/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 14:07:42 by vplotton          #+#    #+#             */
/*   Updated: 2014/03/18 14:53:33 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"lexer.h"

t_bool	ft_print_prserr(t_llist *list)
{
	ft_putstr_fd(ERR_PARSE, 2);
	if (!list)
		ft_putstr_fd(END, 2);
	else if (list->arg_type == T_COM)
		ft_putchar_fd(COMMA, 2);
	else if (list->arg_type == T_PIP)
		ft_putchar_fd(PIPES, 2);
	else if (list->arg_type == T_RFR)
		ft_putchar_fd(RFT_R, 2);
	else if (list->arg_type == T_RFL)
		ft_putchar_fd(RFT_L, 2);
	else if (list->arg_type == T_RFRR)
		ft_putstr_fd(RFT_RR, 2);
	else if (list->arg_type == T_RFLL)
		ft_putstr_fd(RFT_LL, 2);
	ft_putendl_fd("'", 2);
	return (FALSE);
}
