/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordlen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-goug <ele-goug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 21:37:35 by ele-goug          #+#    #+#             */
/*   Updated: 2014/03/27 21:37:36 by ele-goug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "meh.h"

int		ft_wordlen(char **s, char c)
{
	int		count;

	count = 0;
	while (**s)
	{
		if (**s == c)
		{
			*s = *s + 1;
			continue ;
		}
		while (**s && **s != c)
		{
			*s = *s + 1;
			count++;
		}
		return (count);
	}
	return (count);
}
