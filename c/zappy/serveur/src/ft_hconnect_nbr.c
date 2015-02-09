/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hconnect_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/19 22:18:47 by sbres             #+#    #+#             */
/*   Updated: 2014/06/26 04:17:31 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

void		connect_nbr(t_env *env, char *message, int fd)
{
	int		i;
	char	buff[1024];
	char	*tmp;

	i = 0;
	tmp = ft_strtrim(env->pl[fd]->team);
	while (env->world->teams[i] != NULL)
	{
		if (ft_strcmp(env->world->teams[i], tmp) == 0)
			break ;
		i++;
	}
	if (env->world->teams[i] == NULL)
		return ;
	i = env->max_conections[i] - env->conections[i];
	buff[0] = '\0';
	ft_strcat(buff, ft_itoa(i));
	ft_strcat(buff, "\n");
	create_message(env, buff, fd, 0);
	(void)message;
}
