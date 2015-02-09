/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 15:47:58 by vplotton          #+#    #+#             */
/*   Updated: 2014/01/10 15:47:58 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strnew(size_t size)
{
	char	*output;

	output = (char *)malloc(size);
	if (output == NULL)
		return (NULL);
	while (size)
		output[size--] = '\0';
	output[size] = '\0';
	return (output);
}
