/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fth_get_team_name.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obengelo <obengelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 19:14:47 by sbres             #+#    #+#             */
/*   Updated: 2014/06/26 14:59:52 by obengelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

void	ft_get_team_name(char *buffer, t_env *env, int fd)
{
	char	*buff;
	int		counter;

	counter = 0;
	buff = NULL;
	while (env->world->teams[counter] != NULL)
	{
		ft_join(&buff, "tna ", -1, 0);
		ft_join(&buff, env->world->teams[counter], -1, '\n');
		create_message(env, buff, fd, 0);
		ft_bzero(buff, ft_strlen(buff));
		counter++;
	}
	(void)buffer;
}
