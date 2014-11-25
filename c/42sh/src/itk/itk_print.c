/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itk_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarquet <qmarquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 13:14:06 by qmarquet          #+#    #+#             */
/*   Updated: 2014/03/24 22:41:06 by qmarquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "itk_h.h"

int					tputs_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

void				itk_del_all(t_infos *infos)
{
	int				i;
	int				max;

	max = dll_sg_meta(NL)->len + 1 + infos->prompt;
	i = 1;
	while (i < max)
	{
		TERM("le");
		i++;
	}
	TERM("cd");
}

static void			print_char(t_infos *infos, int i, t_elem_dll *current)
{
	char			c;
	t_letter		*letter;

	letter = (t_letter *)(current->data);
	c = letter->l;
	if (i == infos->pos_curs)
		write(1, "\033[30;47m", 9);
	else if (letter->is_c)
		write(1, "\033[37;44m", 9);
	if (letter->is_c)
		TERM("us");
	write(1, &c, 1);
	TERM("ue");
	write(1, "\033[0m", 5);
}

void				itk_print(t_infos *infos)
{
	t_elem_dll		*current;
	t_meta_dll		*list;
	int				i;

	TERM("vi");
	list = dll_sg_meta(infos->nl);
	itk_prompt(infos);
	if (list->len > 0)
	{
		current = list->start;
		i = 1;
		while (current != NULL)
		{
			print_char(infos, i, current);
			current = current->next;
			i++;
		}
	}
	if (infos->pos_curs == list->len + 1)
		TERM("ve");
}

void				itk_refresh(t_infos *infos)
{
	itk_del_all(infos);
	itk_print(infos);
}
