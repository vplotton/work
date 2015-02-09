/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ressource.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 18:25:10 by vplotton          #+#    #+#             */
/*   Updated: 2014/06/02 23:53:27 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ia_zappy.h"

t_bool	set_rsrc(int rsrc)
{
	int			tab[7];
	static int	val = 1;

	tab[FOOD] = 25;
	tab[SIBUR] = 25;
	tab[PHIRAS] = 15;
	tab[LINEMATE] = 23;
	tab[MENDIANE] = 13;
	tab[THYSTAME] = 3;
	tab[DERAUMERE] = 20;
	srand(val * time(NULL));
	val = rand();
	if (val % (100 * RANDOMNESS) < tab[rsrc] * RICHNESS)
		return (TRUE);
	return (FALSE);
}
