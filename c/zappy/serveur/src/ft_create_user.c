/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_user.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 08:41:48 by sbres             #+#    #+#             */
/*   Updated: 2014/06/26 11:28:17 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

char	*ft_create_message(t_player *pl)
{
	char	*tmp;
	char	*tmp2;
	char	*final;

	tmp = ft_itoa(pl->pos.x);
	tmp2 = ft_itoa(pl->pos.y);
	final = ft_strjoin(tmp, " ");
	free(tmp);
	tmp = ft_strjoin(final, tmp2);
	free(final);
	free(tmp2);
	final = ft_strjoin(tmp, "\n");
	return (final);
}

int		nbegg_for_team(t_env *env, int team)
{
	t_eggs		*tmp;

	tmp = env->egg;
	while (tmp != NULL)
	{
		if (tmp->team == team)
		{
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int		can_t_conect(t_env *env, char *team)
{
	int		i;

	i = 0;
	while (env->world->teams[i] != NULL)
	{
		team = ft_strtrim(team);
		if (ft_strcmp(team, env->world->teams[i]) == 0)
			break ;
		i++;
	}
	if (env->world->teams[i] == NULL)
		return (1);
	if (env->conections[i] >= env->max_conections[i])
	{
		if (nbegg_for_team(env, i))
			return (2);
		return (1);
	}
	env->conections[i]++;
	return (0);
}

void	ft_create_user_e(t_env *env, int fd, char *team)
{
	int		i;

	if (team == NULL)
	{
		ft_new_graphic(env, fd);
		return ;
	}
	if ((i = can_t_conect(env, team)) > 0)
	{
		if (i == 2)
		{
			connect_by_egg(env, fd, team);
			return ;
		}
		create_message(env, "ko\n", fd, env->what_time_is_it + 1);
		dell_new_user(env, fd);
		env->pl[fd] = NULL;
		return ;
	}
	env->pl[fd] = new_player_e(env, team);
	send_mapxy(env, fd);
	ft_user_conected(env, env->pl[fd], fd);
	env->map[env->pl[fd]->pos.y][env->pl[fd]->pos.x].nb_pl++;
}
