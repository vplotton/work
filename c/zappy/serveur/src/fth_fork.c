/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fth_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obengelo <obengelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/21 19:05:50 by sbres             #+#    #+#             */
/*   Updated: 2014/06/27 03:07:11 by obengelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

void			hfork(t_env *env, char *message, int fd)
{
	char	buff[1024];

	buff[0] = '\0';
	create_message(env, "ok\n", fd, env->what_time_is_it + 42);
	addtodo(env, env->what_time_is_it + 42, 0, fd);
	ft_strcat(buff, "pfk ");
	ft_strcat(buff, ft_itoa(fd));
	ft_strcat(buff, "\n");
	tell_graphic(env, buff, 0);
	(void)message;
}

t_eggs			*egg_for_team(t_env *env, int team)
{
	t_eggs		*tmp;

	tmp = env->egg;
	while (tmp != NULL)
	{
		if (tmp->team == team)
		{
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

void			connect_by_egg(t_env *env, int fd, char *team_name)
{
	char		buff[1024];
	t_eggs		*team;
	int			i;

	i = 0;
	while (env->world->teams[i] != NULL)
	{
		if (ft_strcmp(ft_strtrim(env->world->teams[i]),
			ft_strtrim(team_name)) == 0)
			break ;
		i++;
	}
	team = egg_for_team(env, i);
	team->fdpl = fd;
	buff[0] = '\0';
	ft_strcat(buff, "ebo ");
	ft_strcat(buff, ft_itoa(team->egg_nb));
	ft_strcat(buff, "\n");
	tell_graphic(env, buff, 0);
	addtodo(env, team->time, 1, fd);
}
