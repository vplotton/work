/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_server.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 20:53:32 by sbres             #+#    #+#             */
/*   Updated: 2014/06/26 20:30:52 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"
#include <stdlib.h>

t_env	*ft_create_conexion(t_env *env)
{
	int		on;

	on = 1;
	if ((env->stream_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("socket : ");
		exit(-1);
	}
	printf("env->stream_socket = %d\n", env->stream_socket);
	if (setsockopt(SOKTFL sizeof(on)) < 0)
	{
		perror("setsockopt : ");
		exit(-1);
	}
	ft_memset(&(env->addr), 0, sizeof(env->addr));
	env->addr.sin_family = AF_INET;
	env->addr.sin_addr.s_addr = htonl(INADDR_ANY);
	env->addr.sin_port = htons(env->world->port);
	if (bind(BINDFL sizeof(env->addr)) < 0)
	{
		perror("bind : ");
		exit(-1);
	}
	return (env);
}

static t_player		**make_it_null(t_player **players, int size)
{
	int		i;

	i = 0;
	printf("null from %d to %d\n", i, size );
	while (i < size)
	{
		players[i] = NULL;
		i++;
	}
	return (players);
}

t_env	*ft_conect_conexion(t_env *env)
{
	if(listen(env->stream_socket, env->world->player_max) < 0)
	{
		perror("listen : ");
		exit(-1);
	}
	FD_ZERO(&(env->master));
	env->fd_max = env->stream_socket;
	env->pl = (t_player **)malloc(sizeof(t_player *) * MAX_PLAYER);
	env->pl = make_it_null(env->pl, MAX_PLAYER);
	FD_SET(env->stream_socket, &(env->master));
	return (env);
}

t_env	*ft_init_max_conections(t_env *env)
{
	int		i;
	int		b;

	b = 0;
	i = 0;
	while (env->world->teams[i] != NULL)
		i++;
	env->max_conections = (int *)malloc(sizeof(int) * i);
	env->conections = (int *)malloc(sizeof(int) * i);
	while (b < i)
	{
		env->max_conections[b] = env->world->player_max;
		b++;
	}
	b = 0;
	while (b < i)
	{
		env->conections[b] = 0;
		b++;
	}
	return (env);
}

t_env	*ft_init_server(t_arguments *arguments)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	env->world = arguments;
	env = ft_create_conexion(env);
	env = ft_conect_conexion(env);
	env = ft_create_handelers(env);
	env = ft_create_handelers_to_do(env);
	env = ft_init_max_conections(env);
	ft_init_cmd(env);
	env->world->t_time_m = ((double)1/env->world->t_time) * 1000000;
	env->timeout.tv_sec = 0;
	env->timeout.tv_usec = 0;
	init_map(&(env));
	env->what_time_is_it = 0;
	env->graphic = NULL;
	env->todo =  NULL;
	env->egg = NULL;
	env->new_users = NULL;
	return (env);
}
