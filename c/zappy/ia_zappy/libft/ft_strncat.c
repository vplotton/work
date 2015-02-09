/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 15:47:34 by vplotton          #+#    #+#             */
/*   Updated: 2014/01/10 15:47:34 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*output;

	output = s1;
	while (*output++)
		;
	output--;
	while (n-- && *s2)
		*output++ = *s2++;
	*output = '\0';
	return (s1);
}
