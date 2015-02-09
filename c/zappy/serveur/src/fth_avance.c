/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fth_avance.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 23:56:15 by sbres             #+#    #+#             */
/*   Updated: 2014/06/26 11:38:56 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

static void		translate(t_player **player, t_env *env)
{
	if (!V(x))
	{
		P(y) = (P(y) + V(y) * -1);
		P(y) = (P(y) < 0 ? P(y) + env->world->mapy : P(y) % env->world->mapy);
	}
	else
	{
		P(x) = (P(x) + V(x) * -1);
		P(x) = (P(x) < 0 ? P(x) + env->world->mapy : P(x) % env->world->mapx);
	}
}

void			avance(t_env *env, char *message, int fd)
{
	env->map[env->pl[fd]->pos.y][env->pl[fd]->pos.x].nb_pl--;
	translate(&env->pl[fd], env);
	env->map[env->pl[fd]->pos.y][env->pl[fd]->pos.x].nb_pl++;
	create_message(env, "ok\n", fd, env->what_time_is_it + 7);
	player_moved(env, fd);
	return ;
	(void)message;
}
