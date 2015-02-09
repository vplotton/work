/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 22:36:21 by vplotton          #+#    #+#             */
/*   Updated: 2014/06/26 19:52:34 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"client.h"

void	add_cmd(t_cmds **c, t_cmd new, int mod)
{
	int		i;

	i = 0;
	while (++i < (*c)->nb_cmd)
	{
		if (i < mod)
			continue ;
		else if (i > mod)
			ft_memcpy(&(*c)->order[i], &(*c)->order[i - 1], sizeof(t_cmd));
	}
	ft_memcpy(&(*c)->order[mod], &new, sizeof(t_cmd));
}

void	reorder_cmd(t_cmds **cmds)
{
	int		i;

	i = 0;
	(*cmds)->nb_cmd--;
	while (i < (*cmds)->nb_cmd)
	{
		ft_memcpy(&(*cmds)->order[i], &(*cmds)->order[i + 1], sizeof(t_cmd));
		i++;
	}
	if ((*cmds)->nb_cmd == 0)
		(*cmds)->need_c = TRUE;
}

void	modify_cmd(int id, int rsrc, char *add, t_cmds **cmds)
{
	t_cmd	new;

	new.id = id;
	new.rsrc = rsrc;
	if (add)
		new.add = add;
	else
		new.add = NULL;
	add_cmd(cmds, new, (*cmds)->nb_cmd);
	(*cmds)->nb_cmd++;
}
