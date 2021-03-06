/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-goug <ele-goug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 21:29:32 by ele-goug          #+#    #+#             */
/*   Updated: 2014/03/27 21:29:40 by ele-goug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <meh.h>

t_bool		ft_isvalid(const char *s)
{
	if (s)
		while (*s)
			if (*s++ != SPRT)
				return (TRUE);
	return (FALSE);
}
