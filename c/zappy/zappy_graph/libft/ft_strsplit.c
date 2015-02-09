/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 15:48:14 by vplotton          #+#    #+#             */
/*   Updated: 2014/01/10 15:48:14 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**output;
	int		i;
	int		j;
	int		size;

	i = -1;
	j = -1;
	size = 1;
	if (!s)
		return (NULL);
	while (s[++i])
		size = ((s[i] == c && s[i + 1] != c) ? size + 1 : size);
	output = (char**)ft_memalloc((size + 1) * sizeof(char*));
	while (size--)
	{
		i = -1;
		while (*s == c)
			s++;
		while (s[++i] && s[i] != c)
			;
		output[++j] = ft_strsub(s, 0, i);
		s = s + i + 1;
	}
	return (output);
}
