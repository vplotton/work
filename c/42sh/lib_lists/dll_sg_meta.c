/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_sg_meta.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarquet <qmarquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 15:19:00 by qmarquet          #+#    #+#             */
/*   Updated: 2014/03/03 11:15:01 by qmarquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lists.h"

t_meta_dll				*dll_sg_meta(int number_list)
{
	static t_meta_dll	meta[NUM_OF_DLL];
	static char			is_first = 1;
	int					i;

	if (number_list < 0 || number_list >= NUM_OF_DLL)
		return (NULL);
	if (is_first)
	{
		i = 0;
		while (i < NUM_OF_DLL)
		{
			meta[i].start = NULL;
			meta[i].end = NULL;
			meta[i].len = 0;
			meta[i].error = 0;
			i++;
		}
	}
	is_first = 0;
	return (&(meta[number_list]));
}
