/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 21:35:03 by vplotton          #+#    #+#             */
/*   Updated: 2014/06/26 20:56:19 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"client.h"

extern char		g_msg[11][12];

t_bool	ft_recv(t_env *env, t_player *player, t_cmd cmd)
{
	int			ret;
	char		r_msg[1024];

	ft_bzero(r_msg, 1024);
	ret = recv(env->s_sock, r_msg, 1024, MSG_DONTWAIT);
	if (ret < 0)
		return (FALSE);
	else if (ret == 0)
		return (END);
	if (ft_strncmp(r_msg, "message ", ft_strlen("message ")) == 0)
	{
		player->msg = ft_strsub(r_msg, ft_strlen("message "), ft_strlen(r_msg));
		return (FALSE);
	}
	if (ft_strncmp(r_msg, "mort", ft_strlen("mort")) == 0)
		return (END);
	if (cmd.rsrc != -1)
		player->ft_recv[cmd.id](player, r_msg, cmd.rsrc, cmd.id);
	else if (cmd.id < SEE)
		player->ft_recv[cmd.id](player, cmd.id);
	else if (cmd.id == FORK)
		player->ft_recv[cmd.id](env, player, cmd.id);
	else
		player->ft_recv[cmd.id](player, r_msg);
	return (TRUE);
}

t_bool	ft_send(int s_sock, t_cmd *cmd)
{
	char	*msg;
	char	buf[1024];

	msg = NULL;
	ft_bzero(buf, 1024);
	msg = ft_strsub(g_msg[cmd->id], 0, ft_strlen(g_msg[cmd->id]));
	ft_memcpy(buf, g_msg[cmd->id], ft_strlen(g_msg[cmd->id]));
	if (cmd->id < GET)
	{
		ft_putendl(msg);
		buf[ft_strlen(buf)] = '\n';
		send(s_sock, buf, 1024, 0);
	}
	else
	{
		if (cmd->add)
			ft_memcpy(buf + ft_strlen(buf), cmd->add, ft_strlen(cmd->add));
		ft_putendl(msg);
		buf[ft_strlen(buf)] = '\n';
		send(s_sock, buf, 1024, 0);
		if (cmd->add)
			ft_strdel(&cmd->add);
		cmd->add = NULL;
	}
	return (TRUE);
}
