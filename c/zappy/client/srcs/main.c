/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 07:11:34 by vplotton          #+#    #+#             */
/*   Updated: 2014/06/26 17:22:54 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

char	g_msg[12][12] =
{
	"avance"
	, "gauche"
	, "droite"
	, "voir"
	, "fork"
	, "incantation"
	, "expulse"
	, "inventaire"
	, "connect_nbr"
	, "prend "
	, "pose "
	, "broadcast "
};

char	g_rsrc[7][12] =
{
	"nourriture"
	, "sibur"
	, "phiras"
	, "linemate"
	, "mendiane"
	, "thystame"
	, "deraumere"
};

/*
**	nb player | sibur | phiras | linemate | mendiane | thystame | deraumere
*/
int		g_rsrc_lvl[7][7] =
{
	{1, 0, 0, 1, 0, 0, 0}
	, {2, 1, 0, 1, 0, 0, 1}
	, {2, 1, 2, 2, 0, 0, 0}
	, {4, 2, 1, 1, 0, 0, 1}
	, {4, 1, 0, 1, 3, 0, 2}
	, {6, 3, 1, 1, 0, 0, 2}
	, {6, 2, 2, 2, 2, 1, 2}
};

static void		usage(char *str)
{
	printf("usage: %s -n <team> -p <port> [-h <hostname>]\n", str);
	exit(0);
}

int				main(int ac, char **av)
{
	int			wait;
	t_param		*e;
	t_env		*env;
	t_player	player;

	wait = 0;
	if (ac < 2)
		usage(av[0]);
	e = ft_parse_args(av);
	if ((e->sock = create_client(e->hostname, e)) == -1)
	{
		ft_putstr("error");
		return (-1);
	}
	if (init_env(&env, e, e->sock) == FALSE)
	{
		ft_putendl_fd("Error while creating env.", 2);
		return (-1);
	}
	if (init_player(&player, e->mapx, e->mapy) == FALSE)
		return (FALSE);
	live(env, &player);
	while (wait != -1)
		wait = waitpid(-1, NULL, 0);
	return (0);
}
