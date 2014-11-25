/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xcheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-goug <ele-goug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 21:34:41 by ele-goug          #+#    #+#             */
/*   Updated: 2014/03/27 21:34:47 by ele-goug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <meh.h>

void		ft_xcheck(t_strlst *pp)
{
	ft_putchar('\n');
	if (!pp)
	{
		ft_putstr("NULL\n");
		return ;
	}
	while ((*pp).prev)
		pp = (*pp).prev;
	while (pp)
	{
		if (!(*pp).prev)
			ft_putstr("START ");
		if ((*pp).x)
			ft_putstr((*pp).x);
		else
			ft_putstr("NULL");
		if (!(*pp).next)
			ft_putstr(" END");
		ft_putchar(' ');
		pp = (*pp).next;
	}
	ft_putchar('\n');
	ft_putchar('\n');
}
