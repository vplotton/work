/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 22:51:17 by cycharbo          #+#    #+#             */
/*   Updated: 2014/06/27 01:06:48 by cycharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy_graph.h"
t_bool	ft_recv(t_env *env, int	size)
{
	char		*r_msg;
	char		*msg;

	if (size == 0)
		size = 1024;
	r_msg = (char*)ft_memalloc(sizeof(char) * 1024);
	ft_bzero(r_msg, 1024);
	recv(env->sock, r_msg, size, 0);
	msg = ft_strtrim(r_msg);
	ft_strdel(&r_msg);
	if (msg && ft_strcmp(msg, "BIENVENUE") != 0 && ft_strcmp(msg, "sgt") != 0)
	{
		ft_get_cmd(msg, env);
	}
	return (TRUE);
}

t_bool	ft_recv_loop(t_env *env, int size)
{
	char		r_msg[1024];
	char		*msg;

	if (size == 0)
		size = 1024;
	ft_bzero(r_msg, 1024);
	recv(env->sock, r_msg, size, MSG_DONTWAIT);
	msg = ft_strtrim(r_msg);
	if (msg && ft_strcmp(msg, "BIENVENUE") != 0 && ft_strcmp(msg, "sgt") != 0)
	{
		ft_get_cmd(msg, env);
	}
	return (TRUE);
}

t_bool	ft_send(int s_sock, char *msg, t_env *env)
{
	send(s_sock, msg, ft_strlen(msg), 0);
	ft_recv(env, 0);
	return (TRUE);
}
