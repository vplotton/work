/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststrstore.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-goug <ele-goug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 21:31:10 by ele-goug          #+#    #+#             */
/*   Updated: 2014/03/27 22:12:59 by ele-goug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <meh.h>

void		ft_gen_next_element(t_strlst **pp)
{
	(**pp).next = malloc(sizeof(t_strlst));
	(*(**pp).next).prev = *pp;
	*pp = (**pp).next;
}

t_strlst	*ft_lststrst(t_strlst *pp, const char *s, t_bool end)
{
	int			j;
	const char	*cs = s;

	while (*s)
	{
		j = 0;
		(*pp).x = malloc(ft_wordlen((char **)&cs, SPRT) + 1);
		while (*s)
		{
			if (*s == SPRT)
			{
				s++;
				continue ;
			}
			while (*s && *s != SPRT)
				(*pp).x[j++] = *s++;
			(*pp).x[j] = '\0';
			break ;
		}
		if (!ft_thisistheend((char **)&s) || !end)
			ft_gen_next_element(&pp);
		else
			(*pp).next = NULL;
	}
	return (pp);
}
