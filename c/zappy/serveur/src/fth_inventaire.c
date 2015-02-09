/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fth_inventaire.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 10:38:15 by sbres             #+#    #+#             */
/*   Updated: 2014/06/26 11:49:40 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

extern char	g_rsrc[7][12];

char			*prtintinventaire(t_player *player)
{
	int		i;
	char	buff[2024];

	i = 0;
	buff[0] = '{';
	buff[1] = '\0';
	ft_strcat(buff, g_rsrc[0]);
	ft_strcat(buff, " ");
	ft_strcat(buff, ft_itoa((player->live / 126)));
	while (++i < 7)
	{
		if (player->rsrc[i])
		{
			ft_strcat(buff, ", ");
			ft_strcat(buff, g_rsrc[i]);
			ft_strcat(buff, " ");
			ft_strcat(buff, ft_itoa(player->rsrc[i]));
		}
	}
	ft_strcat(buff, "}\n");
	return (ft_strdup(buff));
}

void			inventaire(t_env *env, char *message, int fd)
{
	char	*str;

	str = prtintinventaire(env->pl[fd]);
	create_message(env, str, fd, env->what_time_is_it + 1);
	free(str);
	return ;
	(void)message;
}
