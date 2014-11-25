/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-goug <ele-goug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 21:30:22 by ele-goug          #+#    #+#             */
/*   Updated: 2014/03/27 21:30:31 by ele-goug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <meh.h>

void		ft_set_first(t_strlst **pp, t_strlst **first)
{
	if (*pp == *first)
		*first = (**first).next;
}

t_strlst	*ft_lstclean(t_strlst *pp)
{
	t_strlst	*first;

	first = pp;
	while (pp)
	{
		if (ft_strmlcmp((*pp).x, "."))
		{
			ft_set_first(&pp, &first);
			ft_lstrem(&pp);
		}
		else if (ft_strmlcmp((*pp).x, ".."))
		{
			if ((*pp).prev)
			{
				pp = (*pp).prev;
				ft_set_first(&pp, &first);
				ft_lstrem(&pp);
			}
			ft_set_first(&pp, &first);
			ft_lstrem(&pp);
		}
		else
			pp = (*pp).next;
	}
	return (first);
}
