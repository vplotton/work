/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_usertools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 03:51:27 by sbres             #+#    #+#             */
/*   Updated: 2014/06/26 11:29:18 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

void		random_pos(t_arguments *world, t_player **player)
{
	static int	val = 1;

	srand(val * time(NULL));
	val = rand();
	(*player)->pos.x = val % world->mapx;
	srand(val * time(NULL));
	val = rand();
	(*player)->pos.y = val % world->mapy;
	val = val % 100;
	if (val < 50)
		(*player)->ivec.x = (val < 25 ? 1 : -1);
	else
		(*player)->ivec.y = (val > 74 ? 1 : -1);
}

t_player	*new_player_e(t_env *env, char *team)
{
	t_player	*tmp;
	int			i;

	tmp = (t_player *)malloc(sizeof(t_player));
	tmp->lvl = 1;
	tmp->live = 1260;
	random_pos(env->world, &tmp);
	tmp->dvec.x = 0;
	tmp->dvec.y = 0;
	tmp->queu_request = 0;
	i = 0;
	while (i < 7)
	{
		tmp->rsrc[i] = 0;
		i++;
	}
	tmp->team = ft_strtrim(team);
	return (tmp);
}

void		ft_create_user(t_env *env, int fd)
{
	new_user_conected(env, fd);
	create_message(env, "BIENVENUE\n", fd, 0);
}

void		send_mapxy(t_env *env, int fd)
{
	char	*msg;
	char	*tmp;
	char	buf[1024];

	tmp = NULL;
	ft_join(&tmp, NULL, env->world->player_max, '\n');
	ft_bzero(buf, 1024);
	ft_memcpy(buf, tmp, ft_strlen(tmp));
	send(fd, buf, 1024, 0);
	msg = ft_itoa(env->world->mapx);
	tmp = ft_strjoin(msg, " ");
	free(msg);
	msg = ft_strjoin(tmp, ft_itoa(env->world->mapy));
	send(fd, ft_strjoin(msg, "\n"), ft_strlen(ft_strjoin(msg, "\n")), 0);
}
