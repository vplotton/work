/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 15:46:56 by vplotton          #+#    #+#             */
/*   Updated: 2014/05/09 23:07:24 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*output;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	if (!s1 && !s2)
		return (NULL);
	output = (char *)ft_memalloc(len1 + len2 + 1);
	if (output == NULL)
		return (NULL);
	while (len2--)
		output[len1 + len2] = s2[len2];
	while (len1--)
		output[len1] = s1[len1];
	return (output);
}
