/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 15:44:56 by vplotton          #+#    #+#             */
/*   Updated: 2014/01/10 15:44:56 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static int	ft_check_overlap(void *s1, const void *s2, size_t n)
{
	while (n--)
	{
		if (s2++ == s1)
			return (1);
	}
	return (0);
}

void		*ft_memmove(void *s1, const void *s2, size_t n)
{
	const unsigned char	*cpy2;
	unsigned char		*cpy1;

	cpy2 = (const unsigned char *)s2 + n - 1;
	cpy1 = (unsigned char *)s1 + n - 1;
	if (ft_check_overlap(s1, s2, n))
	{
		while (n--)
			*cpy1-- = *cpy2--;
	}
	else
		ft_memcpy(s1, s2, n);
	return (s1);
}
