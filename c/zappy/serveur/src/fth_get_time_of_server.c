/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fth_get_time_of_server.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 19:14:47 by sbres             #+#    #+#             */
/*   Updated: 2014/06/26 11:48:16 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

void	ft_get_time_of_server(char *buffer, t_env *env, int fd)
{
	char	buff[1024];
	char	*tmp;

	buff[0] = '\0';
	ft_strcat(buff, "sgt ");
	tmp = ft_itoa(env->world->t_time);
	ft_strcat(buff, tmp);
	free(tmp);
	ft_strcat(buff, "\n");
	create_message(env, buff, fd, 0);
	(void)buffer;
}
