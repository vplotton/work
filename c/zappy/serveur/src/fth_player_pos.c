/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fth_player_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 19:14:47 by sbres             #+#    #+#             */
/*   Updated: 2014/06/26 12:45:23 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

char		*get_coordination_point_ftw(t_player **player)
{
	if (V(x) == 0 && V(y) == 1)
		return ("1");
	else if (V(x) == 1 && V(y) == 0)
		return ("4");
	else if (V(x) == -1 && V(y) == 0)
		return ("2");
	else if (V(x) == 0 && V(y) == -1)
		return ("3");
	return ("3");
}

void		create_player_pos(char **split, t_env *env, int playernb, int fd)
{
	char	buff[1024];

	buff[0] = '\0';
	ft_strcat(buff, "ppo ");
	ft_strcat(buff, split[1]);
	ft_strcat(buff, " ");
	ft_strcat(buff, ft_itoa(env->pl[playernb]->pos.x));
	ft_strcat(buff, " ");
	ft_strcat(buff, ft_itoa(env->pl[playernb]->pos.y));
	ft_strcat(buff, " ");
	ft_strcat(buff, get_coordination_point_ftw(&env->pl[playernb]));
	ft_strcat(buff, "\n");
	create_message(env, buff, fd, 0);
}

void		ft_player_pos(char *buffer, t_env *env, int fd)
{
	char	**split;
	int		playernb;

	split = ft_strsplit(ft_strtrim(buffer), '#');
	if (split[1] == NULL)
	{
		create_message(env, "sbp\n", fd, 0);
		return ;
	}
	playernb = ft_atoi(split[1]);
	if (env->pl[playernb] == NULL)
	{
		create_message(env, "sbp\n", fd, 0);
		return ;
	}
	create_player_pos(split, env, playernb, fd);
}

void		player_moved(t_env *env, int fd)
{
	char	buff[1024];

	buff[0] = '\0';
	ft_strcat(buff, "ppo ");
	ft_strcat(buff, ft_itoa(fd));
	ft_strcat(buff, " ");
	ft_strcat(buff, ft_itoa(env->pl[fd]->pos.x));
	ft_strcat(buff, " ");
	ft_strcat(buff, ft_itoa(env->pl[fd]->pos.y));
	ft_strcat(buff, " ");
	ft_strcat(buff, get_coordination_point_ftw(&env->pl[fd]));
	ft_strcat(buff, "\n");
	tell_graphic(env, buff, 0);
}
