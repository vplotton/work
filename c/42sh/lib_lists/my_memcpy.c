/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarquet <qmarquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 19:11:52 by qmarquet          #+#    #+#             */
/*   Updated: 2014/03/03 13:34:45 by qmarquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lists.h"

void	*my_memcpy(void *s1, const void *s2, int size)
{
	unsigned char		*tmp1;
	const unsigned char	*tmp2;

	if (s2 == NULL)
		return (NULL);
	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	while (size--)
		*tmp1++ = *tmp2++;
	return (s1);
}
