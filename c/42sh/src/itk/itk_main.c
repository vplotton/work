/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itk_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarquet <qmarquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 12:25:53 by qmarquet          #+#    #+#             */
/*   Updated: 2014/03/24 22:43:02 by qmarquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "itk_h.h"

t_infos					*itk_ini(void)
{
	t_infos				*infos;

	infos = (t_infos *)malloc(sizeof(*infos));
	infos->pos_curs = 1;
	infos->ll = 0;
	infos->nl = 0;
	infos->circle = 0;
	infos->clip = NULL;
	infos->string = NULL;
	itk_welcome();
	return (infos);
}
