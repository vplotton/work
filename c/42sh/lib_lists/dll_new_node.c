/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_new_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarquet <qmarquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 10:06:23 by qmarquet          #+#    #+#             */
/*   Updated: 2014/03/26 18:23:30 by qmarquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lists.h"

t_elem_dll			*dll_new_node(int data_size, void *data)
{
	t_elem_dll		*new;

	if ((new = (t_elem_dll *)malloc(sizeof(*new))) == NULL)
		return (NULL);
	if ((new->data = (void *)malloc(data_size)) == NULL)
		return (NULL);
	my_memcpy(new->data, data, data_size);
	return (new);
}
