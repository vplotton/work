/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master_pl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 19:02:06 by vplotton          #+#    #+#             */
/*   Updated: 2014/06/26 20:50:01 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"client.h"

t_bool	brdcst_master_pos(t_player *player, t_cmds **cmds)
{
	modify_cmd(BRDCST, -1, msg_header(player, MST_POS), cmds);
	return (TRUE);
}

t_bool	get_action(int j, t_player *player, t_cmds **cmds)
{
	if (j % 4 == 3)
		modify_cmd(SEE, -1, NULL, cmds);
	else if (j % 4 == 1)
		modify_cmd(BRDCST, -1, msg_header(player, MST_POS), cmds);
	else if (player->rsrc[FOOD] < 5)
	{
		if (goto_rsrc(player, cmds, FOOD) == FALSE)
			modify_cmd(get_rand(4), -1, NULL, cmds);
	}
	else
		return (FALSE);
	return (TRUE);
}

t_bool	process_master(t_env *env, t_player *player, t_cmds **cmds)
{
	static int	j;

	if ((*cmds)->need_c == TRUE)
	{
		while (player->nb_pl > 0)
		{
			ft_fork(env);
			player->nb_pl--;
		}
		if ((*cmds)->nb_cmd < 2)
		{
			if (get_action(j, player, cmds) == TRUE)
				;
			else if (j % 4 == 0)
				modify_cmd(INVTRY, -1, NULL, cmds);
			else if (j % 4 == 2)
				modify_cmd(LEFT, -1, NULL, cmds);
		}
		j++;
	}
	return (TRUE);
}

t_bool	is_master(t_player *player, int pos, char **split)
{
	if (pos == 0)
	{
		player->pos.x = ft_atoi(split[3]);
		player->pos.y = ft_atoi(split[4]);
		player->type = ENHANCED;
	}
	return (TRUE);
}

t_bool	seek_master(t_player *player, t_cmds **cmds)
{
	int		i;
	int		pos;
	char	**split;

	i = -1;
	if ((split = get_broadcast(&pos, &player->msg)) == NULL)
		return (FALSE);
	is_master(player, pos, split);
	if (pos == 1)
		modify_cmd(ADV, -1, NULL, cmds);
	else if (pos == 3)
		modify_cmd(LEFT, -1, NULL, cmds);
	else if (pos == 5)
	{
		modify_cmd(LEFT, -1, NULL, cmds);
		modify_cmd(LEFT, -1, NULL, cmds);
	}
	else if (pos == 7)
		modify_cmd(RIGHT, -1, NULL, cmds);
	while (split[++i])
		ft_strdel(&split[i]);
	free(split);
	return (TRUE);
}
