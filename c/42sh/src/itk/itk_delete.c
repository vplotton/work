/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itk_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarquet <qmarquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 11:00:22 by qmarquet          #+#    #+#             */
/*   Updated: 2014/03/25 21:15:54 by qmarquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "itk_h.h"

void			itk_delete(t_infos *infos)
{
	if (dll_sg_meta(infos->nl)->len == 0)
		return ;
	if (infos->pos_curs <= 1)
		return ;
	itk_del_all(infos);
	infos->pos_curs--;
	dll_remv_pos(infos->pos_curs, infos->nl);
	itk_print(infos);
}
