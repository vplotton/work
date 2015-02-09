/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 22:42:07 by cycharbo          #+#    #+#             */
/*   Updated: 2014/06/26 22:48:13 by cycharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "zappy_graph.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static void		ft_main(t_env *env, char **argv)
{
	create_client(argv[1], env);
	ft_send(env->sock, "GRAPHIC\n", env);
	ft_t_nb(env);
	ft_init_cmd(env);
	ft_send(env->sock, "msz\n", env);
	ft_recv_map(env);
	if (ft_init_video(env) < 0)
		exit (-1);
	ft_init_itf(env);
	ft_load_numbers(&env);
	ft_get_tna(env);
	ft_load_ground(env);
}

static void		ft_usage(int argc)
{
	if (argc != 3)
		exit(0);
}

int				main(int argc, char **argv)
{
	t_env		*env;

	if (init(&env) == FALSE)
		return (-1);
	ft_usage(argc);
	env->port = ft_atoi(argv[2]);
	ft_main(env, argv);
	ft_make_level(env);
	ft_interface(env);
	ft_display_ground(env);
	ft_draw_grid(env);
	ft_init_ressource_img(&env);
	scan_map(env, 1, 1);
	SDL_BlitSurface(env->display->backg, NULL, env->display->windows, NULL);
	SDL_Flip(env->display->windows);
	ft_load_ft_anim(env);
	ft_pause(env);
	SDL_FreeSurface(env->display->ground);
	SDL_FreeSurface(env->display->level);
	SDL_FreeSurface(env->display->backg);
	SDL_Quit();
	return (0);
}
