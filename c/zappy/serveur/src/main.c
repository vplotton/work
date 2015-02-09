/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/03 20:03:14 by sbres             #+#    #+#             */
/*   Updated: 2014/06/26 20:30:54 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/zappy.h"
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

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

int		g_incant[8][7] =
{
	{0, 0, 0, 0, 0, 0, 0},
	{1, 0, 0, 1, 0, 0, 0},
	{2, 1, 0, 1, 0, 0, 1},
	{2, 1, 2, 2, 0, 0, 0},
	{4, 2, 1, 1, 0, 0, 1},
	{4, 1, 0, 1, 3, 0, 2},
	{6, 3, 1, 1, 0, 0, 2},
	{6, 2, 2, 2, 2, 1, 2}
};

void	usage(char *str)
{
	printf("ussage Usage: ./%s -p <port> -x <width> -y ", str);
	printf("<height> -n <team> [<team>] [<team>] ... -c <nb> -t <t>\n");
	exit(0);
}

void	ft_handle_server(t_env *env)
{
	int				ret;
	struct timeval	end;
	struct timeval	start;
	double			to_do;

	to_do = env->world->t_time_m;
	while (1)
	{
		memcpy(&(env->working_in), &(env->master), sizeof(env->master));
		memcpy(&(env->working_out), &(env->master), sizeof(env->master));
		gettimeofday(&start, NULL);
		ret = select(env->fd_max + 1, SELCFL, &(env->timeout));
		gettimeofday(&end, NULL);
		if ((TIMEMICRO - (start.tv_sec * 1000000 + start.tv_usec)) >= to_do)
		{
			to_do = env->world->t_time_m;
			env->what_time_is_it++;
			ft_make_live(env);
			printf("\033[KClock server time %lf \r", env->what_time_is_it);
			fflush(stdout);
		}
		else
			to_do -= (TIMEMICRO - (start.tv_sec * 1000000 + start.tv_usec));
		dispach_clients(env, ret);
	}
}

int		main(int argn, char **argv)
{
	t_env		*env;
	t_arguments	*arguments;

	if (argn < 2)
		usage(argv[0]);
	printf("Starting\n Parsing arguments...\n ");
	arguments = ft_parse_args(argv);
	printf("Starting server...");
	env = ft_init_server(arguments);
	printf("OK\n waiting for conections");
	ft_handle_server(env);
	return (0);
}
