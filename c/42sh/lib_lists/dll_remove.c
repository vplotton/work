/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarquet <qmarquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 08:35:03 by qmarquet          #+#    #+#             */
/*   Updated: 2014/03/26 18:24:38 by qmarquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lists.h"

int					dll_remv_first(int nbr_list)
{
	t_elem_dll		*tmp_remv;
	t_meta_dll		*list;

	if ((list = dll_sg_meta(nbr_list)) == NULL)
		return (dll_error(nbr_list, -2));
	if (list->start)
	{
		tmp_remv = list->start;
		list->start = list->start->next;
		if (list->start == NULL)
			list->end = NULL;
		else
			list->start->prev = NULL;
		dll_free_node(tmp_remv, list);
	}
	return (0);
}

int					dll_remv_last(int nbr_list)
{
	t_elem_dll		*tmp_remv;
	t_meta_dll		*list;

	if ((list = dll_sg_meta(nbr_list)) == NULL)
		return (dll_error(nbr_list, -2));
	if (list->len == 1)
	{
		dll_remv_first(nbr_list);
		return (-1);
	}
	tmp_remv = list->end;
	list->end->prev->next = NULL;
	list->end = list->end->prev;
	dll_free_node(tmp_remv, list);
	return (0);
}

int					dll_remv_link(t_elem_dll *link, int nbr_list)
{
	t_meta_dll		*list;
	t_elem_dll		*current;
	t_elem_dll		*tmp_remv;
	int				i;

	if ((list = dll_sg_meta(nbr_list)) == NULL)
		return (dll_error(nbr_list, -2));
	if (list->len == 0)
		return (-1);
	if (link == list->start)
		dll_remv_first(nbr_list);
	else if (!(i = 0) && link == list->end)
		dll_remv_last(nbr_list);
	else
	{
		current = list->start;
		i = 0;
		while (current != link)
			current = current->next;
		tmp_remv = current;
		current->prev->next = current->next;
		current->next->prev = current->prev;
		dll_free_node(tmp_remv, list);
	}
	return (0);
}

int					dll_remv_pos(int pos, int nbr_list)
{
	t_meta_dll		*list;
	t_elem_dll		*current;
	t_elem_dll		*tmp_remv;
	int				i;

	if ((list = dll_sg_meta(nbr_list)) == NULL)
		return (dll_error(nbr_list, -2));
	if (list->len == 0 || pos < 0 || pos > list->len)
		return (-1);
	if (pos == 1)
		dll_remv_first(nbr_list);
	else if (!(i = 0) && pos == list->len)
		dll_remv_last(nbr_list);
	else
	{
		current = list->start;
		i = 0;
		while (++i < pos)
			current = current->next;
		tmp_remv = current;
		current->prev->next = current->next;
		current->next->prev = current->prev;
		dll_free_node(tmp_remv, list);
	}
	return (0);
}

int					dll_remv_list(int nbr_list)
{
	t_meta_dll		*list;

	if ((list = dll_sg_meta(nbr_list)) == NULL)
		return (dll_error(nbr_list, -2));
	while (list->len > 0)
		dll_remv_first(nbr_list);
	return (0);
}
