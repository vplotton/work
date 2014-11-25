/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itk_new_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarquet <qmarquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 11:16:54 by qmarquet          #+#    #+#             */
/*   Updated: 2014/03/17 13:12:11 by qmarquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "itk_h.h"

void			itk_new_char(char c, t_infos *infos, char refresh)
{
	t_letter	letter;

	letter.l = c;
	letter.pos = infos->pos_curs;
	letter.is_c = 0;
	if (refresh)
		itk_del_all(infos);
	dll_new_before(VAR(letter), infos->pos_curs, infos->nl);
	infos->pos_curs++;
	if (refresh)
		itk_print(infos);
}
