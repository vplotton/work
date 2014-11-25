/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarquet <qmarquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 09:51:17 by qmarquet          #+#    #+#             */
/*   Updated: 2014/03/14 12:43:09 by qmarquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lists.h"

t_elem_dll		*dll_find_index(int index, int nbr_list)
{
	int			i;
	t_meta_dll	*list;
	t_elem_dll	*current;

	if ((list = dll_sg_meta(nbr_list)) == NULL)
		return (dll_error_p(nbr_list, ERR_NBR_LIST));
	current = list->start;
	i = 0;
	if (index < 0 || index >= list->len)
		dll_error_p(nbr_list, ERR_NOT_FOUND);
	while (++i < index && current->next)
		current = current->next;
	if (i != index)
		dll_error_p(nbr_list, ERR_NOT_FOUND);
	return (current);
}

t_elem_dll		*dll_find_data(int dt_sz, void *to_find, int nbr_list)
{
	t_meta_dll	*list;
	t_elem_dll	*current;

	if (to_find == NULL)
		return (dll_error_p(nbr_list, ERR_NULL_PTR));
	if ((list = dll_sg_meta(nbr_list)) == NULL)
		return (dll_error_p(nbr_list, ERR_NBR_LIST));
	current = list->start;
	while (my_memcmp(to_find, current->data, dt_sz) != 0 && current->next)
		current = current->next;
	if (my_memcmp(to_find, current->data, dt_sz) != 0)
		return (dll_error_p(nbr_list, ERR_NOT_FOUND));
	return (current);
}
