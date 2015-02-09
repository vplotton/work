/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispach_clients.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 07:16:52 by sbres             #+#    #+#             */
/*   Updated: 2014/06/26 03:11:04 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

static	void		new_player_d(t_env *env)
{
	int		fd;

	fd = accept(env->stream_socket, NULL, NULL);
	FD_SET(fd, &(env->master));
	if (fd > env->fd_max)
		env->fd_max = fd;
	ft_create_user(env, fd);
}

void				dispach_clients(t_env *env, int ret)
{
	int		i;

	i = 0;
	if (ret == 0)
		return ;
	while (i <= env->fd_max && ret > 0)
	{
		if (FD_ISSET(i, &(env->working_in)))
		{
			if (i == env->stream_socket)
			{
				new_player_d(env);
			}
			else
				ft_handle_input(env, i);
			ret--;
		}
		else if (FD_ISSET(i, &(env->working_out)))
		{
			send_message(env, i);
			ret--;
		}
		i++;
	}
}
