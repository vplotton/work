/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fth_allmap_rscr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 19:14:47 by sbres             #+#    #+#             */
/*   Updated: 2014/06/26 12:37:29 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

static char			*get_map_rsrc(t_env *env, int x, int y)
{
	int		i;
	char	buff[1024];

	i = -1;
	buff[0] = '\0';
	while (++i < 7)
	{
		ft_strcat(buff, " ");
		ft_strcat(buff, ft_itoa(env->map[y][x].rsrc[i]));
	}
	return (ft_strdup(buff));
}

void				ft_allmap_rscr(char *buffer, t_env *env, int fd)
{
	char	buff[1024];
	int		x;
	int		y;

	x = 0;
	while (x < env->world->mapx)
	{
		y = 0;
		while (y < env->world->mapy)
		{
			buff[0] = '\0';
			buff[1] = '\0';
			ft_strcat(buff, "bct ");
			ft_strcat(buff, ft_itoa(x));
			ft_strcat(buff, " ");
			ft_strcat(buff, ft_itoa(y));
			ft_strcat(buff, get_map_rsrc(env, x, y));
			ft_strcat(buff, "\n");
			create_message(env, buff, fd, 0);
			y++;
		}
		x++;
	}
	(void)buffer;
}
