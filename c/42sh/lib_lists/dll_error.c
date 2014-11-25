/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarquet <qmarquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 13:46:21 by qmarquet          #+#    #+#             */
/*   Updated: 2014/03/04 10:41:05 by qmarquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lists.h"

int				dll_error(int number_list, int error)
{
	dll_sg_meta(number_list)->error = error;
	return (error);
}

t_elem_dll		*dll_error_p(int nbr_list, int error)
{
	int			i;

	i = -1;
	if (error == ERR_NBR_LIST)
	{
		while (++i < NUM_OF_DLL)
			dll_sg_meta(i)->error = error;
		return (NULL);
	}
	dll_sg_meta(nbr_list)->error = error;
	return (NULL);
}
