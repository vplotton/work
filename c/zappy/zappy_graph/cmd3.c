/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 23:15:58 by cycharbo          #+#    #+#             */
/*   Updated: 2014/06/26 23:15:59 by cycharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "zappy_graph.h"

void		ft_broadcast(char *buffer, t_env *env)
{
	char	**arg;
	int		id;
	char	*msg;

	arg = ft_strsplit(buffer, ' ');
	id = ft_atoi(arg[1]);
	msg = ft_strdup(arg[2]);
	env->pl[id].anim[2] = TRUE;
}

void		ft_incant(char *buffer, t_env *env)
{
	char	**arg;
	int		id;

	arg = ft_strsplit(buffer, ' ');
	id = ft_atoi(arg[1]);
	env->pl[id].anim[3] = TRUE;
	(void)env;
}

void		ft_incant_end(char *buffer, t_env *env)
{
	char	**arg;
	int		id;
	t_bool	sucess;

	arg = ft_strsplit(buffer, ' ');
	id = ft_atoi(arg[1]);
	sucess = arg[3][1];
	(void)env;
}

void		ft_egg(char *buffer, t_env *env)
{
	char	**arg;
	int		id;

	arg = ft_strsplit(buffer, ' ');
	id = ft_atoi(arg[1]);
	env->pl[id].anim[4] = TRUE;
	(void)env;
}
