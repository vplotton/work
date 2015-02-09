/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 19:56:42 by cycharbo          #+#    #+#             */
/*   Updated: 2014/06/26 20:39:07 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy_graph.h"

void		ft_egg_is_dead(char *buffer, t_env *env)
{
	char	**arg;
	int		id;

	arg = ft_strsplit(buffer, ' ');
	id = ft_atoi(arg[1]);
	(void)env;
}

void		ft_egg_go(char *buffer, t_env *env)
{
	char	**arg;
	int		id;

	arg = ft_strsplit(buffer, ' ');
	id = ft_atoi(arg[1]);
	(void)env;
}

void		ft_connect_for_egg(char *buffer, t_env *env)
{
	char	**arg;
	int		id;

	arg = ft_strsplit(buffer, ' ');
	id = ft_atoi(arg[1]);
	(void)env;
}

void		ft_egg_is_starving(char *buffer, t_env *env)
{
	char	**arg;
	int		id;

	arg = ft_strsplit(buffer, ' ');
	id = ft_atoi(arg[1]);
	(void)env;
}
