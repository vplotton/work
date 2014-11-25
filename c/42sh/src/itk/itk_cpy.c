/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itk_cpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarquet <qmarquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/15 18:56:58 by qmarquet          #+#    #+#             */
/*   Updated: 2014/03/16 14:05:19 by qmarquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "itk_h.h"

void				itk_cpy(int nw, int last)
{
	t_elem_dll		*current;
	t_letter		letter;

	dll_remv_list(last);
	current = dll_sg_meta(nw)->start;
	while (current)
	{
		letter = *(t_letter *)(current->data);
		letter.is_c = 0;
		dll_new_at_last(VAR(letter), last);
		current = current->next;
	}
}
