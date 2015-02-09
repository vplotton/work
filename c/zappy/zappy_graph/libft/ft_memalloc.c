/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 15:44:31 by vplotton          #+#    #+#             */
/*   Updated: 2014/01/10 15:44:31 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*output;

	output = (unsigned char*)malloc(size);
	if (output == NULL)
		return (NULL);
	while (size--)
		output[size] = 0;
	return ((void *)output);
}
