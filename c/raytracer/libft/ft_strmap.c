/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 15:47:25 by vplotton          #+#    #+#             */
/*   Updated: 2014/01/10 15:47:25 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	int		i;
	char	*output;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen((char *)s);
	output = (char *)malloc(len + 1);
	while (s[i])
	{
		output[i] = f(s[i]);
		i++;
	}
	output[i] = '\0';
	return (output);
}
