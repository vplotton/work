/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 15:47:19 by vplotton          #+#    #+#             */
/*   Updated: 2014/01/10 15:47:19 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t	ft_strlen(const char *s)
{
	char		*cpy;

	if (!s)
		return (0);
	cpy = (char*)s;
	while (*cpy++)
		;
	return (cpy - s - 1);
}
