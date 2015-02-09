/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 16:59:53 by sbres             #+#    #+#             */
/*   Updated: 2013/12/01 15:34:29 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
void	ft_strclr(char *s)
{
	int	counter;

	counter = 0;
	if (s == NULL)
		return ;
	while (s[counter] != '\0')
	{
		s[counter] = '\0';
		counter++;
	}
}
