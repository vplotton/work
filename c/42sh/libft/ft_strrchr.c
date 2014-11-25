/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 15:48:07 by vplotton          #+#    #+#             */
/*   Updated: 2014/01/10 15:48:07 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;

	temp = NULL;
	while (*s)
	{
		if (*s++ == (unsigned char)c)
			temp = (char*)(s - 1);
	}
	if (!(*s) && !c)
		return ((char*)s);
	if (*s == (unsigned char)c)
		temp = (char*)(s - 1);
	return (temp);
}
