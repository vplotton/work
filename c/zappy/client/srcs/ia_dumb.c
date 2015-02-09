/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia_dumb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 04:42:23 by vplotton          #+#    #+#             */
/*   Updated: 2014/06/26 20:52:02 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"client.h"

extern char	g_rsrc[7][12];
extern int	g_rsrc_lvl[7][7];

int		check_lvl_rsrc(t_player *player)
{
	int		i;

	i = 1;
	while (i < 7)
	{
		if (player->rsrc[i] < g_rsrc_lvl[player->lvl][i])
			return (i);
		i++;
	}
	return (-1);
}

t_bool	goto_rsrc(t_player *player, t_cmds **cmds, int rsrc)
{
	int		i;
	t_ipos	m;
	t_ipos	target;

	i = -1;
	m.x = -1;
	m.y = -1;
	if ((target = detect_sq(rsrc, player)).x != -1)
	{
		while (++m.x < target.x)
			modify_cmd(ADV, -1, NULL, cmds);
		if (target.y < 0)
			modify_cmd(LEFT, -1, NULL, cmds);
		else if (target.y > 0)
			modify_cmd(RIGHT, -1, NULL, cmds);
		while (++m.y < ABS(target.y))
			modify_cmd(ADV, -1, NULL, cmds);
		modify_cmd(GET, rsrc, ft_strdup(g_rsrc[rsrc]), cmds);
		modify_cmd(INVTRY, -1, NULL, cmds);
		return (TRUE);
	}
	return (FALSE);
}

t_bool	process_player(t_player *player, t_cmds **cmds)
{
	int			rsrc;
	static int	i;

	rsrc = -1;
	if ((*cmds)->need_c)
	{
		if (i % 4 == 0 && player->type == ENHANCED)
			modify_cmd(SEE, -1, NULL, cmds);
		else if (player->rsrc[FOOD] < 2)
		{
			if (goto_rsrc(player, cmds, FOOD) == FALSE)
				modify_cmd(get_rand(3), -1, NULL, cmds);
		}
		else if ((rsrc = check_lvl_rsrc(player)) != -1)
			goto_rsrc(player, cmds, rsrc);
		else
			goto_rsrc(player, cmds, PLAYER);
		i++;
	}
	return (TRUE);
}

t_bool	process_ia(t_env *env, t_player *player, t_cmds **cmds)
{
	if (player->type == MASTER)
		process_master(env, player, cmds);
	else
		process_player(player, cmds);
	return (TRUE);
}
