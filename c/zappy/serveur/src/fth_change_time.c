/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fth_change_time.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 19:14:47 by sbres             #+#    #+#             */
/*   Updated: 2014/06/26 20:30:52 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

static void	ft_get_time_of_server_l(t_env *env)
{
	char	buff[1024];
	char	*tmp;

	buff[0] = '\0';
	ft_strcat(buff, "sgt ");
	tmp = ft_itoa(env->world->t_time);
	ft_strcat(buff, tmp);
	free(tmp);
	ft_strcat(buff, "\n");
	tell_graphic(env, buff, 0);
}

void		ft_change_time(char *buffer, t_env *env, int fd)
{
	char	buff[1024];
	char	**tmp;
	int		new_int;

	buff[0] = '\0';
	ft_strcat(buff, "sgt ");
	tmp = ft_strsplit(buffer, ' ');
	if (tmp[1] == NULL)
	{
		create_message(env, "sbp\n", fd, 0);
		return ;
	}
	new_int = ft_atoi(tmp[1]);
	if (new_int <= 0)
	{
		create_message(env, "sbp\n", fd, 0);
		return ;
	}
	env->world->t_time = new_int;
	env->world->t_time_m = ((double)1 / env->world->t_time) * 1000000;
	ft_get_time_of_server_l(env);
}
