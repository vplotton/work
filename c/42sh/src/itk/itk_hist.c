/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itk_hist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarquet <qmarquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/15 17:39:33 by qmarquet          #+#    #+#             */
/*   Updated: 2014/03/18 14:44:59 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "itk_h.h"

void			itk_hist(char s_read[8], t_infos *infos)
{
	if (FT_DOWN && infos->ll == infos->nl)
		return ;
	if (FT_UP && (NL == LL + 1 || (NL == 0 && LL == NUM_OF_DLL / 2 - 1)))
		return ;
	infos->pos_curs = dll_sg_meta(NL)->len + 1;
	itk_del_all(infos);
	if (FT_UP)
	{
		if (NL == 0 && infos->circle)
			NL = NUM_OF_DLL / 2 - 1;
		else if (NL > 0)
			NL--;
	}
	else if (FT_DOWN)
	{
		if (NL == NUM_OF_DLL / 2 - 1)
			NL = 0;
		else
			NL++;
	}
	infos->pos_curs = dll_sg_meta(NL)->len + 1;
	itk_print(infos);
}
