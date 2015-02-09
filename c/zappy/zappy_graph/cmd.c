/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 23:14:03 by cycharbo          #+#    #+#             */
/*   Updated: 2014/06/27 01:55:47 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy_graph.h"

void			ft_recv_map(t_env *env)
{
	int			i;
	char		*msg;

	i = 0;
	msg = (char*)ft_memalloc(sizeof(char) * 1024);
	send(env->sock, "mct\n", 4, 0);
	while (i < env->m_width * env->m_height)
	{
		ft_recv(env, 0);
		i++;
	}
	(void)msg;
}

void			ft_get_map(char *buffer, t_env *env)
{
	char		**arg;
	int			i;
	int			j;

	j = 0;
	i = 0;
	arg = ft_strsplit(buffer, ' ');
	env->m_width = ft_atoi(arg[1]);
	env->m_height = ft_atoi(arg[2]);
	env->map = (t_map**)ft_memalloc(sizeof(t_map*) * env->m_height);
	while (i < env->m_height)
	{
		j = 0;
		while (j < env->m_width)
		{
			env->map[i] = (t_map*)ft_memalloc(sizeof(t_map) * env->m_width);
			j++;
		}
		i++;
	}
}

void			ft_map_rscr(char *buffer, t_env *env)
{
	int			i;
	char		**arg;
	t_point		p;

	arg = ft_strsplit(buffer, ' ');
	i = 0;
	p.x = ft_atoi(arg[1]);
	p.y = ft_atoi(arg[2]);
	while (i < 7)
	{
		env->map[p.y][p.x].rsrc[i] = ft_atoi(arg[i + 2]);
		i++;
	}
}

void			ft_get_team_name(char *buffer, t_env *env)
{
	static int	i = 0;
	char		**arg;

	arg = ft_strsplit(buffer, ' ');
	env->itf->team[i].name = ft_strdup(arg[1]);
	i++;
}

void			ft_new_player(char *buffer, t_env *env)
{
	char		**arg;
	int			i;
	int			j;

	j = 0;
	init_player(&env);
	arg = ft_strsplit(buffer, ' ');
	i = ft_atoi(arg[1]);
	env->pl[i].pos.x = ft_atoi(arg[2]);
	env->pl[i].pos.y = ft_atoi(arg[3]);
	env->pl[i].dvec.x = ft_atoi(arg[4]);
	env->pl[i].lvl = ft_atoi(arg[5]);
	env->pl[i].team = ft_strdup(arg[6]);
	env->nb += 1;
	env->map[env->pl[i].pos.y][env->pl[i].pos.x].ids[i] = TRUE;
	env->pl[i].dead = FALSE;
	j = 0;
	while (j < 7)
	{
		env->pl[i].anim[i] = FALSE;
		j++;
	}
	check_player(env, env->pl[i].pos.x, env->pl[i].pos.y, env->display->level);
}
