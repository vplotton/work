/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_pl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 19:43:31 by cycharbo          #+#    #+#             */
/*   Updated: 2014/06/26 20:47:00 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy_graph.h"

void		ft_t_nb(t_env *env)
{
	char	msg[1024];

	send(env->sock, "ndeg\n", 5, 0);
	recv(env->sock, msg, 1024, 0);
	env->t_nb = ft_atoi(msg);
}

void		ft_get_tna(t_env *env)
{
	int		i;
	char	msg[1024];

	i = 0;
	ft_bzero(msg, 1024);
	send(env->sock, "tna\n", 5, 0);
	usleep(500);
	while (i < env->t_nb)
	{
		ft_recv(env, 0);
		i++;
	}
}
