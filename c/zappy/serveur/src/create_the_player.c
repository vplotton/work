/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_the_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 07:47:49 by sbres             #+#    #+#             */
/*   Updated: 2014/06/26 11:24:37 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

static	t_player	*init_player(t_env *env, t_eggs *team)
{
	t_player	*tmp;

	tmp = (t_player *)malloc(sizeof(t_player));
	tmp->lvl = 1;
	tmp->live = 1260;
	random_pos(env->world, &(tmp));
	tmp->pos.x = team->x;
	tmp->pos.y = team->y;
	tmp->dvec.x = 0;
	tmp->dvec.y = 0;
	tmp->queu_request = 0;
	return (tmp);
}

void				create_the_player(t_env *env, t_to_do *todo)
{
	char		buff[1024];
	t_eggs		*team;
	int			i;

	team = env->egg;
	while (team)
	{
		if (team->fdpl == todo->player)
			break ;
		team = team->next;
	}
	env->pl[todo->player] = init_player(env, team);
	i = 0;
	while (i < 7)
	{
		env->pl[todo->player]->rsrc[i] = 0;
		i++;
	}
	env->pl[todo->player]->team = env->world->teams[team->team];
	send_mapxy(env, todo->player);
	buff[0] = '\0';
	ft_strcat(buff, "eht ");
	ft_strcat(buff, ft_itoa(team->egg_nb));
	ft_strcat(buff, "\n");
	tell_graphic(env, buff, 0);
}
