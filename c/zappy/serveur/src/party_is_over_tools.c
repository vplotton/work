/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   party_is_over_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 13:20:54 by sbres             #+#    #+#             */
/*   Updated: 2014/06/26 13:37:12 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

int		get_pio(t_env *env, char *team)
{
	int		i;

	i = 0;
	team = ft_strtrim(team);
	while (env->world->teams[i] != NULL)
	{
		if (ft_strcmp(team, env->world->teams[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

void	burn_everything_in_fire(t_env *env, t_to_do *todo)
{
	exit(0);
	(void)env;
	(void)todo;
}
