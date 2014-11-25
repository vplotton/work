/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_new_in_empty.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarquet <qmarquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 13:35:12 by qmarquet          #+#    #+#             */
/*   Updated: 2014/03/18 14:41:26 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lists.h"

int					dll_new_in_empty(int data_size, void *data, int number_list)
{
	t_elem_dll		*new;
	t_meta_dll		*list;

	if ((new = dll_new_node(data_size, data)) == NULL)
		return (dll_error(number_list, -1));
	new->prev = NULL;
	new->next = NULL;
	list = dll_sg_meta(number_list);
	list->start = new;
	list->end = new;
	list->len = 1;
	return (0);
}
