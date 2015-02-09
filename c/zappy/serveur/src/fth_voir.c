/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fth_voir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obengelo <obengelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 23:59:17 by sbres             #+#    #+#             */
/*   Updated: 2014/06/26 17:12:09 by obengelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

extern char	g_rsrc[7][12];

static int		d_players(t_env *env, t_ipos pos, int fd)
{
	int		i;
	int		count;
	t_map	**map;

	i = -1;
	count = 0;
	map = env->map;
	while (++i < MAX_PLAYER)
	{
		if (map[pos.y][pos.x].ids[i])
		{
			if (env->pl[i]->lvl == env->pl[fd]->lvl)
				count++;
		}
	}
	return (count);
}

static char		*show_rsrc(t_env *env, t_ipos pos)
{
	int		i;
	int		rsrc;

	i = -1;
	while (++i < 7)
	{
		rsrc = -1;
		while (++rsrc < env->map[pos.y][pos.x].rsrc[i])
			ft_join(&(env->msg), g_rsrc[i], -1, ' ');
	}
	return (env->msg);
}

static void		show(t_env *env, t_ipos pos, t_ipos m, int fd)
{
	int			i;
	static int	sq;

	if (m.x == 0)
	{
		sq = 0;
		ft_join(&(env->msg), "{", -1, 0);
	}
	if (sq >= 0)
	{
		i = -1;
		while (++i < MAX_PLAYER)
		{
			if (env->map[pos.y][pos.x].ids[i])
				ft_join(&(env->msg), "joueur", -1, ' ');
		}
		env->msg = show_rsrc(env, pos);
		ft_join(&(env->msg), " ", -1, 0);
		if (sq < (env->pl[fd]->lvl + 2) * env->pl[fd]->lvl && sq >= 0)
			ft_join(&(env->msg), ",", -1, 0);
		else if (sq == (env->pl[fd]->lvl + 2) * env->pl[fd]->lvl)
			ft_join(&(env->msg), "}\n", -1, 0);
	}
	sq++;
}

int				detect(int rsrc, t_env *env, int fd)
{
	int		count;
	t_ipos	m;
	t_ipos	pos;

	m.x = -1;
	count = 0;
	while (++m.x < env->pl[fd]->lvl + 1)
	{
		m.y = -m.x - 1;
		while (++m.y < m.x + 1)
		{
			pos.x = env->pl[fd]->pos.x + m.x * env->pl[fd]->ivec.x;
			pos.y = env->pl[fd]->pos.y + m.y * env->pl[fd]->ivec.y;
			pos.x = (DETCX : pos.x % env->world->mapx);
			pos.y = (DETCY : pos.y % env->world->mapy);
			if (rsrc == ALL)
				show(env, pos, m, fd);
			else if (rsrc == -1)
				count += d_players(env, pos, fd);
			else
				count += env->map[pos.y][pos.x].rsrc[rsrc];
		}
	}
	return (count);
}

void		voir(t_env *env, char *message, int fd)
{
	env->msg = NULL;
	env->pl[fd]->fd = fd;
	detect(ALL, env, fd);
	create_message(env, env->msg, fd, env->what_time_is_it + 7);
	free(env->msg);
	env->msg = NULL;
	(void)message;
}
