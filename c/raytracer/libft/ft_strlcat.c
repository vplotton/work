/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 18:46:19 by vplotton          #+#    #+#             */
/*   Updated: 2014/01/21 19:18:09 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const char	*cpy_s;
	char		*cpy_d;
	size_t		n;
	size_t		dst_len;

	cpy_d = dst;
	cpy_s = src;
	n = size;
	while ((n--) && *cpy_d)
		cpy_d++;
	dst_len = cpy_d - dst;
	n = size - dst_len + 1;
	if (n == 1)
		return (dst_len + ft_strlen(cpy_s));
	while (*cpy_s)
	{
		if (--n != 1)
			*cpy_d++ = *cpy_s;
		cpy_s++;
	}
	*cpy_d = '\0';
	return (dst_len + (cpy_s - src));
}
