/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 23:13:39 by cycharbo          #+#    #+#             */
/*   Updated: 2014/06/26 23:19:17 by cycharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy_graph.h"

int				create_client(char *addr, t_env	*env)
{
	if ((env->proto = getprotobyname("tcp")) == 0)
	{
		ft_putstr("error get proto");
		return (-1);
	}
	env->sock = socket(PF_INET, SOCK_STREAM, (env->proto)->p_proto);
	env->sin.sin_family = AF_INET;
	env->sin.sin_port = htons(env->port);
	env->sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(env->sock, (struct sockaddr *)(&(env->sin)),
				sizeof(env->sin)) == -1)
	{
		ft_putstr("Connect error ");
		exit(0);
		return (-1);
	}
	return (env->sock);
}
