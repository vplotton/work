/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsclone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-goug <ele-goug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 21:33:40 by ele-goug          #+#    #+#             */
/*   Updated: 2014/03/27 21:33:44 by ele-goug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <meh.h>

char	**ft_strsclone(char **sa)
{
	char	**out;
	char	**cout;

	if (!sa)
		return (NULL);
	out = malloc((ft_strslen(sa) + 1) * sizeof(char *));
	cout = out;
	while (*sa)
		*cout++ = ft_strclone(*sa++);
	*cout = NULL;
	return (out);
}
