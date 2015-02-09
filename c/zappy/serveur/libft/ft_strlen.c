/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obengelo <obengelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:12:01 by sbres             #+#    #+#             */
/*   Updated: 2014/06/26 04:29:52 by obengelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
size_t		ft_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	while (str && *str)
	{
		counter++;
		str++;
	}
	return (counter);
}
