/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itk_move_curs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarquet <qmarquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 11:32:08 by qmarquet          #+#    #+#             */
/*   Updated: 2014/03/18 14:45:41 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "itk_h.h"

void				itk_move_curs(char s_read[8], t_infos *infos, int i)
{
	struct winsize		size;
	int					len;

	ioctl(STDIN_FILENO, TIOCGWINSZ, (char *)&size);
	len = size.ws_col;
	if (FT_RIGHT && infos->pos_curs <= dll_sg_meta(infos->nl)->len)
		infos->pos_curs++;
	else if (FT_LEFT && infos->pos_curs > 1)
		infos->pos_curs--;
	else if (FT_HOME || FT_A_HOME)
		infos->pos_curs = 1;
	else if (FT_END || FT_A_END)
		infos->pos_curs = dll_sg_meta(NL)->len + 1;
	else if (CR_DN)
	{
		while (++i < size.ws_col && infos->pos_curs <= LEN)
			infos->pos_curs++;
	}
	else if (CR_UP)
	{
		while (++i < size.ws_col && infos->pos_curs > 1)
			infos->pos_curs--;
	}
	itk_refresh(infos);
}

static void			itk_select_letter(t_infos *infos)
{
	t_letter		*letter;
	t_elem_dll		*current;
	int				i;

	if (infos->pos_curs <= dll_sg_meta(infos->nl)->len)
	{
		current = dll_sg_meta(NL)->start;
		i = 1;
		while (i < infos->pos_curs)
		{
			current = current->next;
			i++;
		}
		letter = (t_letter *)(current->data);
		if (letter)
			letter->is_c = (letter->is_c == 1) ? 0 : 1;
	}
}

t_infos				*itk_select(char s_read[8], t_infos *infos)
{
	itk_select_letter(infos);
	if ((FT_SHIFT_LEFT || FT_A_HOME) && infos->pos_curs > 1)
		infos->pos_curs--;
	else if ((FT_SHIFT_RIGHT || FT_A_END)
			&& infos->pos_curs <= dll_sg_meta(NL)->len)
		infos->pos_curs++;
	if (FT_A_HOME && infos->pos_curs > 1)
		itk_select(s_read, infos);
	else if (FT_A_END && infos->pos_curs <= dll_sg_meta(NL)->len)
		itk_select(s_read, infos);
	return (infos);
}
