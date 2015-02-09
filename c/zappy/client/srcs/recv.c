/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 23:55:28 by vplotton          #+#    #+#             */
/*   Updated: 2014/06/26 20:48:54 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"client.h"

extern char		g_rsrc[7][12];

t_bool	ft_recv_expls(t_player *player, char *r_msg)
{
	(void)player;
	if (ft_strcmp("ok", r_msg) == 0)
		return (TRUE);
	return (FALSE);
}

t_bool	ft_recv_incnt(t_player *player, char *r_msg)
{
	player->lvl = ft_atoi(r_msg);
	return (TRUE);
}

t_bool	ft_recv_cnctnbr(t_player *player, char *r_msg)
{
	player->nb_pl = ft_atoi(r_msg);
	return (TRUE);
}

t_bool	ft_recv_gd(t_player *player, char *r_msg, int rsrc, int cmd)
{
	int			change;

	if (ft_strcmp(r_msg, "ok") == 0)
	{
		change = (cmd == GET ? 1 : -1);
		player->rsrc[rsrc] += change;
		return (TRUE);
	}
	return (FALSE);
}

t_bool	ft_recv_invtry(t_player *player, char *r_msg)
{
	int		i;
	int		j;
	char	**rsrc;
	char	**inventory;

	i = -1;
	if ((r_msg = ft_strsub(r_msg, 1, ft_strlen(r_msg) - 3)) == NULL)
		return (FALSE);
	inventory = ft_strsplit(r_msg, ',');
	ft_bzero(player->rsrc, sizeof(player->rsrc));
	while (inventory[++i])
	{
		j = 0;
		rsrc = ft_strsplit(inventory[i], ' ');
		while (j < 7 && ft_strcmp(g_rsrc[j], rsrc[0]))
			j++;
		if (j < 7)
			player->rsrc[i] = ft_atoi(rsrc[1]);
		ft_strdel(&rsrc[0]);
		ft_strdel(&rsrc[1]);
		free(rsrc);
		ft_strdel(&inventory[i]);
	}
	free(inventory);
	return (TRUE);
}
