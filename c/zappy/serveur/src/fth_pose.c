/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fth_pose.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 19:42:04 by obengelo          #+#    #+#             */
/*   Updated: 2014/06/26 12:39:00 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

extern char	g_rsrc[7][12];

static int			ft_get_rsrcs(char *message)
{
	int				rsrc;
	char			*msg;

	rsrc = 0;
	msg = ft_strsub(message, 5, ft_strlen(message) - 6);
	while (rsrc < 7)
	{
		if (ft_strcmp(msg, g_rsrc[rsrc]) == 0)
			return (rsrc);
		rsrc++;
	}
	return (-1);
}

void				pose(t_env *env, char *message, int fd)
{
	int			rsrc;
	char		buff[1024];

	rsrc = ft_get_rsrcs(message);
	buff[0] = '\0';
	ft_strcat(buff, "pdr ");
	ft_strcat(buff, ft_itoa(fd));
	ft_strcat(buff, " ");
	ft_strcat(buff, ft_itoa(rsrc));
	ft_strcat(buff, "\n");
	if (rsrc == -1 || !env->pl[fd]->rsrc[rsrc])
		create_message(env, "ko\n", fd, env->what_time_is_it + 7);
	else
	{
		env->map[PL(y)][PL(x)].rsrc[rsrc] += 1;
		env->pl[fd]->rsrc[rsrc]--;
		create_message(env, "ok\n", fd, env->what_time_is_it + 7);
	}
	tell_graphic(env, buff, 0);
}
