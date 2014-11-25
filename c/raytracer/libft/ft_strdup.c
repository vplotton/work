/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 15:46:41 by vplotton          #+#    #+#             */
/*   Updated: 2014/01/10 15:46:41 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strdup(const char *s)
{
	size_t		len;
	char		*output;

	len = ft_strlen(s);
	if (len == 1)
		return (NULL);
	output = (char *)malloc(len * sizeof(char));
	if (output == NULL)
		return (NULL);
	ft_strcpy(output, s);
	return (output);
}
