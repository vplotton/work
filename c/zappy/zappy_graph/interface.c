/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 22:47:03 by cycharbo          #+#    #+#             */
/*   Updated: 2014/06/26 22:47:40 by cycharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "zappy_graph.h"

void			ft_init_itf(t_env *env)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	if ((env->itf = (t_interface*)ft_memalloc(sizeof(t_interface))) == NULL)
		ft_putstr("Malloc error\n");
	if ((env->itf->team = (t_team*)ft_memalloc(sizeof(t_team) * (env->t_nb))) ==
			NULL)
		ft_putstr("Malloc error");
	while (i < env->t_nb)
	{
		j = 0;
		while (j < 7)
		{
			env->itf->team[i].trsc[j] = 0;
			env->itf->team[i].lvl[j] = 0;
			env->itf->team[i].name = NULL;
			j++;
		}
		env->itf->team[i].lvl[j] = 0;
		env->itf->team[i].nb_ply = 0;
		i++;
	}
}

static void		ft_get_team_info(t_player player, t_team *team)
{
	int			i;

	i = 0;
	team->lvl[player.lvl] += 1;
	while (i < 7)
	{
		team->trsc[i] += player.rsrc[i];
		i++;
	}
	team->nb_ply++;
}

static void		ft_read_team(t_env *env, int x, int y)
{
	int			i;
	int			j;

	j = 0;
	i = 0;
	while (i < env->nb)
	{
		j = 0;
		if (env->map[y][x].ids[i] == TRUE)
		{
			while (j < env->t_nb && i < MAX_PLAYER && env->itf->team[j].name
				&& env->pl[i].team
				&& ft_strcmp(env->pl[i].team, env->itf->team[j].name) != 0)
				j++;
			ft_get_team_info(env->pl[i], &(env->itf->team[j]));
		}
		i++;
	}
}

void			ft_interface(t_env *env)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < env->m_height)
	{
		j = 0;
		while (j < env->m_width)
		{
			ft_read_team(env, j, i);
			j++;
		}
		i++;
	}
}
