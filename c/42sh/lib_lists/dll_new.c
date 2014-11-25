/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarquet <qmarquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 09:23:12 by qmarquet          #+#    #+#             */
/*   Updated: 2014/03/26 18:19:12 by qmarquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lists.h"

int				dll_new_at_first(int data_size, void *data, int nbr_list)
{
	t_elem_dll		*new;
	t_meta_dll		*list;

	if ((list = dll_sg_meta(nbr_list)) == NULL)
		return (dll_error(nbr_list, -2));
	if (list->len == 0)
		return (dll_new_in_empty(data_size, data, nbr_list));
	if ((new = dll_new_node(data_size, data)) == NULL)
		return (dll_error(nbr_list, -1));
	new->prev = NULL;
	new->next = list->start;
	list->start->prev = new;
	list->start = new;
	list->len++;
	return (0);
}

int				dll_new_at_last(int data_size, void *data, int nbr_list)
{
	t_elem_dll		*new;
	t_meta_dll		*list;

	if ((list = dll_sg_meta(nbr_list)) == NULL)
		return (dll_error(nbr_list, -2));
	if (list->len == 0)
		return (dll_new_in_empty(data_size, data, nbr_list));
	if ((new = dll_new_node(data_size, data)) == NULL)
		return (dll_error(nbr_list, -1));
	new->next = NULL;
	new->prev = list->end;
	list->end->next = new;
	list->end = new;
	list->len++;
	return (0);
}

static int		add_node(int dt_sz, void *data, t_elem_dll *current, int nb_l)
{
	t_elem_dll		*new;

	if ((new = dll_new_node(dt_sz, data)) == NULL)
		return (dll_error(nb_l, -1));
	new->next = current;
	new->prev = current->prev;
	current->prev->next = new;
	current->prev = new;
	return (0);
}

int				dll_new_before(int dt_sz, void *data, int pos, int nbr_list)
{
	t_meta_dll		*list;
	t_elem_dll		*current;
	int				i;

	i = 0;
	if ((list = dll_sg_meta(nbr_list)) == NULL)
		return (dll_error(nbr_list, -2));
	current = list->start;
	if (list->len == 0)
		return (dll_new_in_empty(dt_sz, data, nbr_list));
	else if (pos <= 1)
		return (dll_new_at_first(dt_sz, data, nbr_list));
	else if (pos > list->len)
		return (dll_new_at_last(dt_sz, data, nbr_list));
	else
	{
		while (++i < pos)
			current = current->next;
		if (add_node(dt_sz, data, current, nbr_list) < 0)
			return (-1);
		list->len++;
	}
	return (0);
}
