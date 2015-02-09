/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 18:06:47 by vplotton          #+#    #+#             */
/*   Updated: 2014/06/26 19:54:18 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_bool			live(t_env *env, t_player *player)
{
	t_bool	action;
	t_bool	alive;
	int		i;
	t_cmds	*cmds;

	i = 0;
	alive = TRUE;
	action = TRUE;
	cmds = ft_memalloc(sizeof(t_cmds));
	cmds->need_c = TRUE;
	cmds->nb_cmd = 0;
	while (alive)
	{
		process_ia(env, player, &cmds);
		if ((action = ft_recv(env, player, cmds->order[0])) == TRUE)
			reorder_cmd(&cmds);
		if (action == TRUE || !i)
			ft_send(env->s_sock, &cmds->order[0]);
		else if (action == END)
			break ;
		action = FALSE;
		i++;
	}
	free(cmds);
	return (TRUE);
}
