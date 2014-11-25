/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 15:45:51 by vplotton          #+#    #+#             */
/*   Updated: 2014/01/10 15:45:51 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		len1;
	int		len2;

	i = 0;
	len1 = (int)ft_strlen(s1);
	len2 = (int)ft_strlen((char *)s2);
	while (i < len1 + len2)
	{
		s1[len1 + i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
