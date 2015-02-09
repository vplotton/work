/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 23:14:20 by cycharbo          #+#    #+#             */
/*   Updated: 2014/06/26 23:18:20 by cycharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "zappy_graph.h"

void		ft_change_player_pos(char *buffer, t_env *env)
{
	char	**arg;
	int		id;

	arg = ft_strsplit(buffer, ' ');
	id = ft_atoi(arg[1]);
	env->map[env->pl[id].pos.y][env->pl[id].pos.x].ids[id] = FALSE;
	ft_move_player(env, id);
	env->pl[id].pos.x = ft_atoi(arg[2]);
	env->pl[id].pos.y = ft_atoi(arg[3]);
	env->pl[id].dvec.x = ft_atoi(arg[4]);
	env->map[env->pl[id].pos.y][env->pl[id].pos.x].ids[id] = TRUE;
	check_player(env, env->pl[id].pos.x, env->pl[id].pos.y,
			env->display->level);
}

void		ft_change_player_level(char *buffer, t_env *env)
{
	char	**arg;
	int		id;

	arg = ft_strsplit(buffer, ' ');
	id = ft_atoi(arg[1]);
	env->itf->team[env->pl[id].team_id].lvl[env->pl[id].lvl] -= 1;
	env->pl[id].lvl = ft_atoi(arg[2]);
	env->pl[id].anim[0] = TRUE;
	env->itf->team[env->pl[id].team_id].lvl[env->pl[id].lvl] += 1;
}

void		ft_change_inventory(char *buffer, t_env *env)
{
	char	**arg;
	int		id;
	int		i;

	i = 0;
	arg = ft_strsplit(buffer, ' ');
	id = ft_atoi(arg[1]);
	while (i < 7)
	{
		env->pl[id].rsrc[i] = ft_atoi(arg[i + 2]);
		i++;
	}
}

void		ft_expulse(char *buffer, t_env *env)
{
	char	**arg;
	int		id;

	arg = ft_strsplit(buffer, ' ');
	id = ft_atoi(arg[1]);
	env->pl[id].anim[1] = TRUE;
}
