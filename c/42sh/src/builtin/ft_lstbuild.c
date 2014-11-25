/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstbuild.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-goug <ele-goug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 21:29:56 by ele-goug          #+#    #+#             */
/*   Updated: 2014/03/27 22:14:36 by ele-goug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <meh.h>

t_strlst		*ft_lstbuild(const char *s1, const char *s2)
{
	t_strlst	*pp;
	t_bool		state1;
	t_bool		state2;

	state1 = ft_isvalid(s1);
	state2 = ft_isvalid(s2);
	if (!state1 && !state2)
		return (NULL);
	pp = malloc(sizeof(t_strlst));
	(*pp).x = NULL;
	(*pp).prev = NULL;
	(*pp).next = NULL;
	if (state1 && state2)
		ft_lststrst(ft_lststrst(pp, s1, FALSE), s2, TRUE);
	else if (!state2)
		ft_lststrst(pp, s1, TRUE);
	else
		ft_lststrst(pp, s2, TRUE);
	return (pp);
}
