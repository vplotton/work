/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itk_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarquet <qmarquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 12:31:24 by qmarquet          #+#    #+#             */
/*   Updated: 2014/03/27 22:09:14 by qmarquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "itk_h.h"

int					itk_ctrl_c(t_infos *infos)
{
	infos->pos_curs = 1;
	dll_remv_list(NL);
	dll_remv_list(NL + NUM_OF_DLL / 2);
	write(1, "\n", 1);
	itk_prompt(infos);
	return (1);
}

int					detect_keys(char s_read[8], t_infos *infos)
{
	if (FT_DELETE)
		itk_delete(infos);
	else if (IS_ASCII)
		itk_new_char(s_read[0], infos, 1);
	else if (FT_X || FT_C || FT_V)
		itk_clipboard(s_read, infos);
	else if (FT_LEFT || FT_RIGHT || FT_HOME || FT_END || CR_UP || CR_DN)
		itk_move_curs(s_read, infos, -1);
	else if (FT_SHIFT_LEFT || FT_SHIFT_RIGHT || FT_A_HOME || FT_A_END)
		itk_refresh(itk_select(s_read, infos));
	else if (FT_UP || FT_DOWN)
		itk_hist(s_read, infos);
	else if (s_read[0] == -1)
		itk_ctrl_c(infos);
	else if (FT_CTRL_D)
		itk_exit(infos);
	else if (FT_RETURN)
		return (itk_ret(infos, 0));
	else if (FT_F1)
		itk_help(infos);
	else if (FT_F2)
		itk_credits(infos);
	else if (FT_CTRL_L)
		itk_clear(infos);
	return (1);
}

int					itk_read(t_infos *infos)
{
	char			s_read[8];
	int				ret;
	int				tr;

	itk_start();
	itk_prompt(infos);
	ret = 1;
	if (isatty(0))
		tr = 8;
	else
		tr = 1;
	while (ret == 1)
	{
		*(long *)s_read = 0;
		read(0, s_read, tr);
		ret = detect_keys(s_read, infos);
		if (s_read[0] == 0)
			itk_exit(infos);
	}
	itk_end();
	if (FT_CTRL_D)
		return (0);
	return (1);
}
