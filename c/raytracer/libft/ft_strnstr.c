/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 15:48:03 by vplotton          #+#    #+#             */
/*   Updated: 2014/01/10 15:48:03 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*cpy1;
	char	*cpy2;
	size_t	i;

	cpy1 = (char *)s1;
	cpy2 = (char *)s2;
	i = 0;
	if (cpy2 == NULL)
		return (cpy1);
	while (*cpy1 && *cpy2 && (i < n))
	{
		if (*cpy1 == *cpy2)
			cpy2++;
		else
		{
			i = i - (cpy2 - s2);
			cpy1 = cpy1 - (cpy2 - s2);
			cpy2 = (char *)s2;
		}
		cpy1++;
		i++;
	}
	if (!*cpy2)
		return (cpy1 - ft_strlen((char *)s2));
	return (NULL);
}
