/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-goug <ele-goug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 21:30:45 by ele-goug          #+#    #+#             */
/*   Updated: 2014/03/27 21:30:54 by ele-goug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <meh.h>

t_bool		ft_lstrem(t_strlst **pp)
{
	t_strlst	*cpp;

	if (pp)
	{
		cpp = *pp;
		if ((**pp).next)
			(*(**pp).next).prev = (**pp).prev;
		if ((**pp).prev)
			(*(**pp).prev).next = (**pp).next;
		*pp = (**pp).next;
		free((*cpp).x);
		free(cpp);
		return (TRUE);
	}
	return (FALSE);
}
