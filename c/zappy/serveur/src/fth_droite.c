/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fth_droite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obengelo <obengelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 23:57:35 by sbres             #+#    #+#             */
/*   Updated: 2014/06/25 22:09:17 by obengelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

static void		rotate(t_player **player)
{
	if (!(*player)->ivec.x)
	{
		(*player)->ivec.x = ((*player)->ivec.y == DOWN ? -1 : 1);
		(*player)->ivec.y = 0;
	}
	else
	{
		(*player)->ivec.y = ((*player)->ivec.x == RIGHT ? 1 : -1);
		(*player)->ivec.x = 0;
	}
}

void			droite(t_env *env, char *message, int fd)
{
	rotate(&env->pl[fd]);
	create_message(env, "ok\n", fd, env->what_time_is_it + 7);
	player_moved(env, fd);
	(void)message;
}
