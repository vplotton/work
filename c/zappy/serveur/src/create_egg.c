/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_egg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/21 20:05:20 by sbres             #+#    #+#             */
/*   Updated: 2014/06/26 16:49:21 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

int		ft_group_of_player(char **team, char *str)
{
	int		i;

	i = 0;
	while (team[i] != NULL)
	{
		if (ft_strcmp(ft_strtrim(team[i]), ft_strtrim(str)) == 0)
		{
			return (i);
		}
		i++;
	}
	return (0);
}

void	create_egg(t_env *env, t_to_do *todo)
{
	int		team_nb;
	char	buff[1024];
	int		egg_nb;

	team_nb = ft_group_of_player(env->world->teams,
		env->pl[todo->player]->team);
	egg_nb = create_egg_env(env, team_nb,
		env->pl[todo->player]->pos.x, env->pl[todo->player]->pos.y);
	buff[0] = '\0';
	ft_strcat(buff, "enw ");
	ft_strcat(buff, ft_itoa(egg_nb));
	ft_strcat(buff, " ");
	ft_strcat(buff, ft_itoa(todo->player));
	ft_strcat(buff, " ");
	ft_strcat(buff, ft_itoa(env->pl[todo->player]->pos.x));
	ft_strcat(buff, " ");
	ft_strcat(buff, ft_itoa(env->pl[todo->player]->pos.y));
	ft_strcat(buff, "\n");
	tell_graphic(env, buff, 0);
}
