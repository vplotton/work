/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_user_conected.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obengelo <obengelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 20:04:05 by sbres             #+#    #+#             */
/*   Updated: 2014/06/26 15:13:07 by obengelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

static char *get_coordination_point(t_player **player)
{
	if (V(x) == 0 && V(y) == 1)
		return ("1");
	else if (V(x) == 1 && V(y) == 0)
		return ("4");
	else if (V(x) == -1 && V(y) == 0)
		return ("2");
	else if (V(x) == 0 && V(y) == -1)
		return ("3");
	return ("3");
}

void		ft_user_conected(t_env *env, t_player *pl, int fd)
{
	char	buff[1024];

	buff[0] = '\0';
	ft_strcat(buff, "pnw ");
	ft_strcat(buff, ft_itoa(fd));
	ft_strcat(buff, " ");
	ft_strcat(buff, ft_itoa(pl->pos.x));
	ft_strcat(buff, " ");
	ft_strcat(buff, ft_itoa(pl->pos.y));
	ft_strcat(buff, " ");
	ft_strcat(buff, get_coordination_point(&pl));
	ft_strcat(buff, " ");
	ft_strcat(buff, ft_itoa(pl->lvl));
	ft_strcat(buff, " ");
	ft_strcat(buff, pl->team);
	tell_graphic(env, buff, 0);
}
