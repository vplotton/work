/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 15:48:22 by vplotton          #+#    #+#             */
/*   Updated: 2014/01/10 15:48:22 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*output;

	if (!s)
		return (NULL);
	output = (char *)malloc(len + 1);
	if (output == NULL)
		return (NULL);
	output[len] = '\0';
	while (len-- && s[len])
		output[len] = s[start + len];
	return (output);
}
