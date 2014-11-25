/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itk_ini.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 21:27:14 by vplotton          #+#    #+#             */
/*   Updated: 2014/03/27 22:44:55 by qmarquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "itk_h.h"

t_infos					*itk_ini(void)
{
	static t_infos		*infos = NULL;

	if (infos == NULL)
	{
		infos = (t_infos *)malloc(sizeof(*infos));
		infos->pos_curs = 1;
		infos->ll = 0;
		infos->nl = 0;
		infos->circle = 0;
		infos->clip = NULL;
		infos->string = NULL;
		if (isatty(0))
			itk_welcome();
		itk_first();
	}
	return (infos);
}
