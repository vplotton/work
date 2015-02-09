/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 23:16:09 by cycharbo          #+#    #+#             */
/*   Updated: 2014/06/26 23:21:28 by cycharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "zappy_graph.h"

void		ft_drop_rscr(char *buffer, t_env *env)
{
	char	**arg;
	int		id;
	int		i;

	arg = ft_strsplit(buffer, ' ');
	i = ft_atoi(arg[2]);
	id = ft_atoi(arg[1]);
	env->pl[id].rsrc[i] -= 1;
	env->map[env->pl[id].pos.y][env->pl[id].pos.x].rsrc[i] += 1;
	SDL_FillRect(env->display->d_rsc, NULL,
			SDL_MapRGB(env->display->windows->format, 0, 0, 0));
	scan_map(env, 0, 1);
}

void		ft_get_rscr(char *buffer, t_env *env)
{
	char	**arg;
	int		id;
	int		i;

	arg = ft_strsplit(buffer, ' ');
	i = ft_atoi(arg[2]);
	id = ft_atoi(arg[1]);
	env->pl[id].rsrc[i] += 1;
	env->map[env->pl[id].pos.y][env->pl[id].pos.x].rsrc[i] -= 1;
	SDL_FillRect(env->display->d_rsc, NULL,
			SDL_MapRGB(env->display->windows->format, 0, 0, 0));
	scan_map(env, 0, 1);
}

void		ft_player_die(char *buffer, t_env *env)
{
	char	**arg;
	int		id;

	arg = ft_strsplit(buffer, ' ');
	id = ft_atoi(arg[1]);
	env->pl[id].dead = TRUE;
	ft_move_player(env, id);
	env->itf->team[env->pl[id].team_id].lvl[env->pl[id].lvl] -= 1;
	env->pl[id].lvl = 0;
	scan_map(env, 1, 0);
}

void		ft_egg_is_ok(char *buffer, t_env *env)
{
	char	**arg;
	int		id;

	arg = ft_strsplit(buffer, ' ');
	id = ft_atoi(arg[1]);
	(void)env;
}
