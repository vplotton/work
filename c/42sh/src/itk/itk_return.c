/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itk_return.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarquet <qmarquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 10:51:07 by qmarquet          #+#    #+#             */
/*   Updated: 2014/03/24 15:05:53 by qmarquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "itk_h.h"

int				itk_ret(t_infos *infos, int i)
{
	itk_cpy(NL, LL + NUM_OF_DLL / 2);
	itk_del_all(infos);
	itk_prompt(infos);
	itk_putstr("\033[32m");
	if (itk_putstr(itk_string_cmd(infos)) == NULL)
		return (itk_ctrl_c(infos));
	itk_putstr("\n\033[0m");
	if (LL == NUM_OF_DLL / 2 - 1)
	{
		LL = 0;
		infos->circle = 1;
	}
	else
		LL++;
	while (i < NUM_OF_DLL / 2)
	{
		itk_cpy(i + NUM_OF_DLL / 2, i);
		i++;
	}
	NL = LL;
	infos->pos_curs = 1;
	dll_remv_list(NL);
	dll_remv_list(NL + NUM_OF_DLL / 2);
	return (2);
}
