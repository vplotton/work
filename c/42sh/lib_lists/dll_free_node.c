/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_free_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarquet <qmarquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 09:03:39 by qmarquet          #+#    #+#             */
/*   Updated: 2014/03/04 09:14:19 by qmarquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lists.h"

void				dll_free_node(t_elem_dll *node_to_rm, t_meta_dll *info)
{
	free(node_to_rm->data);
	free(node_to_rm);
	info->len--;
}
