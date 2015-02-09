/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fth_player_lvl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obengelo <obengelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 19:14:47 by sbres             #+#    #+#             */
/*   Updated: 2014/06/26 02:35:43 by obengelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

void	ft_player_lvl(char *buffer, t_env *env, int fd)
{
	char	buff[1024];
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
	buff[0] = '\0';
	ft_strcat(buff, "plv ");
	ft_strcat(buff, split[1]);
	ft_strcat(buff, " ");
	ft_strcat(buff, ft_itoa(env->pl[playernb]->lvl));
	ft_strcat(buff, "\n");
	create_message(env, buff, fd, 0);
}
