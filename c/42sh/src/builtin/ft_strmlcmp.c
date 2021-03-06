/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmlcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-goug <ele-goug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 21:32:44 by ele-goug          #+#    #+#             */
/*   Updated: 2014/03/27 21:32:51 by ele-goug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "meh.h"

t_bool	ft_strmlcmp(const char *s1, const char *s2)
{
	while ((*s1 == *s2) && *s1 && s1++ && s2++)
		;
	if ((*s1 - *s2) == 0)
		return (TRUE);
	return (FALSE);
}
