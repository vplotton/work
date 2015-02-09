/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fth_prendre.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obengelo <obengelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 19:41:54 by obengelo          #+#    #+#             */
/*   Updated: 2014/06/27 02:14:37 by obengelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

extern char	g_rsrc[7][12];

static int			ft_get_rsrcs(char *message)
{
	int		rsrc;
	char	*msg;

	rsrc = 0;
	msg = ft_strsub(message, 6, ft_strlen(message) - 7);
	while (rsrc < 7)
	{
		if (ft_strcmp(msg, g_rsrc[rsrc]) == 0)
			return (rsrc);
		rsrc++;
	}
	return (-1);
}

char				*tell_graphic_machin(int fd, int rsrc)
{
	char			*buff;

	buff = (char *)malloc(sizeof(char) * 1024);
	if (buff == NULL)
		ft_puterror("malloc");
	buff[0] = '\0';
	ft_strcat(buff, "pgt ");
	ft_strcat(buff, ft_itoa(fd));
	ft_strcat(buff, " ");
	ft_strcat(buff, ft_itoa(rsrc));
	ft_strcat(buff, "\n");
	return (buff);
}

void				prend(t_env *env, char *message, int fd)
{
	int		rsrc;
	char	*buff;

	rsrc = ft_get_rsrcs(message);
	buff = tell_graphic_machin(fd, rsrc);
	if (rsrc == -1 || !env->map[PL(y)][PL(x)].rsrc[rsrc])
	{
		create_message(env, "ko\n", fd, env->what_time_is_it + 7);
		return ;
	}
	env->map[PL(y)][PL(x)].rsrc[rsrc]--;
	if (rsrc == 0)
	{
		srand(time(NULL));
		env->map[rand() % env->world->mapy][RANX].rsrc[rsrc]++;
		env->pl[fd]->live += 126;
	}
	env->pl[fd]->rsrc[rsrc] += 1;
	create_message(env, "ok\n", fd, env->what_time_is_it + 7);
	tell_graphic(env, buff, 0);
}
