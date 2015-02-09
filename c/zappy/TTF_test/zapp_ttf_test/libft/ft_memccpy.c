/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 15:44:35 by vplotton          #+#    #+#             */
/*   Updated: 2014/01/10 15:44:35 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char	*cpy1;

	cpy1 = (unsigned char*)s1;
	while (n--)
	{
		if ((*cpy1++ = *(unsigned char*)s2++) == (unsigned char)c)
			return (cpy1);
	}
	return (NULL);
}
