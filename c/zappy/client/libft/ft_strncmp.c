/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 15:47:39 by vplotton          #+#    #+#             */
/*   Updated: 2014/01/10 15:47:39 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n-- && (*s1++ == *s2++))
	{
		if (!(*(s1 - 1)))
			return (*(s1 - 1) - *(s2 - 1));
	}
	return (*(s1 - 1) - *(s2 - 1));
}