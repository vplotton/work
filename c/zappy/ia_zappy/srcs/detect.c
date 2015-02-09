/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/31 16:16:39 by vplotton          #+#    #+#             */
/*   Updated: 2014/06/08 21:51:44 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ia_zappy.h"

extern t_rsrc	g_rsrc[7];

static int		d_players(t_env *env, t_player *player, t_ipos pos)
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
			if (env->pl[i].lvl == player->lvl)
				count++;
		}
	}
	return (count);
}

static void		show_rsrc(t_env *env, t_ipos pos)
{
	int		i;
	int		rsrc;

	i = -1;
	while (++i < 7)
	{
		rsrc = -1;
		while (++rsrc < env->map[pos.y][pos.x].rsrc[i])
			printf(" %s", g_rsrc[rsrc].name);
	}
}

static void		show(t_env *env, t_player *player, t_ipos pos, t_ipos m)
{
	int			i;
	static int	sq = 0;

	if (m.x == 0)
	{
		sq = 0;
		printf("{");
	}
	if (sq > 0)
	{
		printf("case %d", sq);
		i = -1;
		while (++i < MAX_PLAYER)
		{
			if (env->map[pos.y][pos.x].ids[i])
				printf(" joueur");
		}
		show_rsrc(env, pos);
		if (sq < (player->lvl + 2) * player->lvl && sq > 0)
			printf(", ");
		else if (sq == (player->lvl + 2) * player->lvl)
			printf("}\n");
	}
	sq++;
}

double			detect_max_sq(int rsrc, int *max, t_env *env, t_player *player)
{
	int		count;
	t_ipos	m;
	t_ipos	pos;
	t_ipos	tmp;

	m.x = -1;
	tmp.x = -1;
	count = 0;
	while (++m.x < player->lvl + 1)
	{
		m.y = -m.x - 1;
		while (++m.y < m.x + 1)
		{
			pos.x = player->pos.x + m.x * player->ivec.x;
			pos.y = player->pos.y + m.y * player->ivec.y;
			pos.x = (pos.x < 0 ? pos.x + WIDTH : pos.x % WIDTH);
			pos.y = (pos.y < 0 ? pos.y + HEIGHT : pos.y % HEIGHT);
			if (env->map[pos.y][pos.x].rsrc[rsrc] > *max)
			{
				*max = env->map[pos.y][pos.x].rsrc[rsrc];
				tmp = pos;
			}
		}
	}
	if (tmp.x != -1)
		return (get_dst(player->pos, tmp));
	return (-1);
}

double			detect_sq(int rsrc, t_env *env, t_player *player)
{
	int		count;
	t_ipos	m;
	t_ipos	pos;

	m.x = -1;
	count = 0;
	while (++m.x < player->lvl + 1)
	{
		m.y = -m.x - 1;
		while (++m.y < m.x + 1)
		{
			pos.x = player->pos.x + m.x * player->ivec.x;
			pos.y = player->pos.y + m.y * player->ivec.y;
			pos.x = (pos.x < 0 ? pos.x + WIDTH : pos.x % WIDTH);
			pos.y = (pos.y < 0 ? pos.y + HEIGHT : pos.y % HEIGHT);
			if (env->map[pos.y][pos.x].rsrc[rsrc])
				return (get_dst(player->pos, pos));
		}
	}
	return (-1);
}

double			detect_rtv_sq(int rtv, int rsrc, t_env *env, t_player *player)
{
	int		count;
	t_ipos	m;
	t_ipos	pos;

	m.x = -1;
	count = 0;
	while (++m.x < player->lvl + 1)
	{
		m.y = -m.x - 1;
		while (++m.y < m.x + 1)
		{
			pos.x = player->pos.x + m.x * player->ivec.x;
			pos.y = player->pos.y + m.y * player->ivec.y;
			pos.x = (pos.x < 0 ? pos.x + WIDTH : pos.x % WIDTH);
			pos.y = (pos.y < 0 ? pos.y + HEIGHT : pos.y % HEIGHT);
			if (!rtv)
				return (env->map[pos.y][pos.x].rsrc[rsrc]);
			rtv--;
		}
	}
	return (0);
}

int				detect(int rsrc, t_env *env, t_player *player)
{
	int		count;
	t_ipos	m;
	t_ipos	pos;

	m.x = -1;
	count = 0;
	while (++m.x < player->lvl + 1)
	{
		m.y = -m.x - 1;
		while (++m.y < m.x + 1)
		{
			pos.x = player->pos.x + m.x * player->ivec.x;
			pos.y = player->pos.y + m.y * player->ivec.y;
			pos.x = (pos.x < 0 ? pos.x + WIDTH : pos.x % WIDTH);
			pos.y = (pos.y < 0 ? pos.y + HEIGHT : pos.y % HEIGHT);
			if (rsrc == ALL)
				show(env, player, pos, m);
			else if (rsrc == -1)
				count += d_players(env, player, pos);
			else
				count += env->map[pos.y][pos.x].rsrc[rsrc];
		}
	}
	return (count);
}
