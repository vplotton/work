/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 15:44:48 by vplotton          #+#    #+#             */
/*   Updated: 2014/01/10 15:44:48 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned char	*cpy1;

	cpy1 = (unsigned char*)s1;
	while (n--)
		*(unsigned char*)s1++ = *(unsigned char*)s2++;
	return (cpy1);
}
