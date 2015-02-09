/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obengelo <obengelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 18:56:12 by sbres             #+#    #+#             */
/*   Updated: 2014/06/26 04:32:12 by obengelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;

	if (s1 == NULL)
		return ((char *)s2);
	if (s1 != NULL && s2 != NULL)
	{
		string = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (string != NULL)
		{
			string = ft_strcpy(string, s1);
			return (ft_strcat(string, s2));
		}
	}
	return (NULL);
}
