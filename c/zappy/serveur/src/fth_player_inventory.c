/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fth_player_inventory.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 19:14:47 by sbres             #+#    #+#             */
/*   Updated: 2014/06/26 12:10:15 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

void	ft_plaimessage(t_env *env, int playernb, char **split, int fd)
{
	char	buff[1024];
	int		i;

	i = 0;
	buff[0] = '\0';
	ft_strcat(buff, "pin ");
	ft_strcat(buff, split[1]);
	while (++i < 7)
	{
		ft_strcat(buff, " ");
		ft_strcat(buff, ft_itoa(env->pl[playernb]->rsrc[i]));
	}
	ft_strcat(buff, "\n");
	create_message(env, buff, fd, 0);
}

void	ft_player_inventory(char *buffer, t_env *env, int fd)
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
	ft_plaimessage(env, playernb, split, fd);
}
