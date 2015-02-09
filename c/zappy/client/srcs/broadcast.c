/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   broadcast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 03:24:52 by vplotton          #+#    #+#             */
/*   Updated: 2014/06/26 13:04:25 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"client.h"

extern int	g_rsrc_lvl[7][7];

t_bool	ft_recv_brdcst(t_player *player, char *r_msg)
{
	(void)player;
	if (ft_strncmp(r_msg, "ok", 2) == 0)
		return (TRUE);
	return (FALSE);
}

char	*msg_header(t_player *player, int msg_type)
{
	char	*msg;

	msg = NULL;
	ft_join(&msg, NULL, msg_type, TRUE);
	ft_join(&msg, NULL, player->id, TRUE);
	ft_join(&msg, NULL, player->lvl, TRUE);
	ft_join(&msg, NULL, player->pos.x, TRUE);
	ft_join(&msg, NULL, player->pos.y, TRUE);
	return (msg);
}

t_bool	msg_info_pl(t_player *player, t_cmd *cmd)
{
	int		i;
	char	*msg;

	i = 1;
	msg = msg_header(player, INFO_PL);
	while (i < 6)
	{
		ft_join(&msg, NULL, player->rsrc[i], TRUE);
		i++;
	}
	ft_join(&msg, NULL, player->rsrc[i], FALSE);
	cmd->add = msg;
	return (TRUE);
}
