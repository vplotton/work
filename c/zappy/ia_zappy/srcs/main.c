/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/30 16:08:41 by vplotton          #+#    #+#             */
/*   Updated: 2014/06/04 22:28:39 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ia_zappy.h"

t_rsrc	g_rsrc[7] =
{
	{FOOD, "nourriture"}
	, {SIBUR, "sibur"}
	, {PHIRAS, "phiras"}
	, {LINEMATE, "linemate"}
	, {MENDIANE, "mendiane"}
	, {THYSTAME, "thystame"}
	, {DERAUMERE, "deraumere"}
};

static void		usage(char *name)
{
	ft_putstr_fd(name, 2);
	ft_putendl_fd(": no arguments available", 2);
	_exit(-1);
}

int				main(int ac, char **av)
{
	t_env		*env;

	if (ac != 1)
		usage(av[0]);
	if (init(&env) == FALSE)
		return (-1);
	if (process_ia(env, &env->pl[0]) == FALSE)
		return (-1);
	return (0);
}
