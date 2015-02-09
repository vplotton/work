/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 15:45:56 by vplotton          #+#    #+#             */
/*   Updated: 2014/01/10 15:45:56 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s++ == (unsigned char)c)
			return ((char*)(s - 1));
	}
	if (!(*s) && !c)
		return ((char*)s);
	if (*s == (unsigned char)c)
		return ((char*)(s - 1));
	return (NULL);
}
