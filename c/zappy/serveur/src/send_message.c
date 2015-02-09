/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_message.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obengelo <obengelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 18:59:10 by sbres             #+#    #+#             */
/*   Updated: 2014/06/26 15:20:20 by obengelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

void	send_and_erase(t_env *env, int fd, t_to_send *tmp_g, t_to_send *tmp_b)
{
	if (env->what_time_is_it >= tmp_g->time_to_send)
	{
		send(tmp_g->fd, tmp_g->message, 1024, 0);
		if (tmp_b == NULL)
			env->message_queu = tmp_g->next;
		else
			tmp_b->next = tmp_g->next;
		if (env->pl[fd] == NULL && !is_grapich(env->graphic, fd)
			&& !is_new_user(env, fd))
		{
			FD_CLR(fd, &(env->master));
			printf("closing %d \n", fd);
			close(fd);
		}
		if (env->pl[fd] != NULL)
			env->pl[fd]->queu_request--;
		free(tmp_g->message);
		free(tmp_g);
	}
}

void	send_message(t_env *env, int fd)
{
	t_to_send	*tmp_g;
	t_to_send	*tmp_b;

	tmp_g = env->message_queu;
	tmp_b = NULL;
	while (tmp_g != NULL)
	{
		if (tmp_g->fd == fd)
		{
			send_and_erase(env, fd, tmp_g, tmp_b);
			return ;
		}
		if (env->what_time_is_it > tmp_g->time_to_send)
			return ;
		tmp_b = tmp_g;
		tmp_g = tmp_g->next;
	}
}
