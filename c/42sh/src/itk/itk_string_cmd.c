/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itk_string_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarquet <qmarquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 13:23:02 by qmarquet          #+#    #+#             */
/*   Updated: 2014/03/24 14:53:51 by qmarquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "itk_h.h"

char				*itk_string_cmd(t_infos *infos)
{
	t_elem_dll		*current;
	t_meta_dll		*list;
	char			*s;
	int				i;

	list = dll_sg_meta(infos->nl);
	if (list->len == 0)
		return (NULL);
	s = (char *)malloc(sizeof(*s) * (dll_sg_meta(NL)->len + 1));
	s[dll_sg_meta(NL)->len] = '\0';
	current = list->start;
	i = 0;
	while (current != NULL)
	{
		s[i] = ((t_letter *)(current->data))->l;
		current = current->next;
		i++;
	}
	infos->string = s;
	return (s);
}
