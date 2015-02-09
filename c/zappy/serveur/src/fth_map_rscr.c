/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fth_map_rscr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 19:14:47 by sbres             #+#    #+#             */
/*   Updated: 2014/06/26 14:26:34 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

static char	*get_map_rsrc(t_env *env, int x, int y)
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

char		*ft_get_msg(char **tmp, t_env *env, int *map)
{
	char	*buff;

	buff = (char *)malloc(sizeof(char) * 1024);
	if (buff == NULL)
		ft_puterror("malloc error");
	buff[0] = '\0';
	ft_strcat(buff, "bct ");
	ft_strcat(buff, tmp[1]);
	ft_strcat(buff, " ");
	ft_strcat(buff, tmp[2]);
	ft_strcat(buff, get_map_rsrc(env, map[0], map[1]));
	ft_strcat(buff, "\n");
	return (buff);
}

void		ft_map_rscr(char *buffer, t_env *env, int fd)
{
	char	*buff;
	char	**tmp;
	int		map[2];

	tmp = ft_strsplit(buffer, ' ');
	if (tmp[1] == NULL)
	{
		create_message(env, "sbp\n", fd, 0);
		return ;
	}
	if (tmp[2] == NULL)
	{
		create_message(env, "sbp\n", fd, 0);
		return ;
	}
	map[0] = ft_atoi(tmp[1]);
	map[1] = ft_atoi(tmp[2]);
	if (map[0] >= env->world->mapx || map[1] >= env->world->mapy)
	{
		create_message(env, "sbp\n", fd, 0);
		return ;
	}
	buff = ft_get_msg(tmp, env, map);
	create_message(env, buff, fd, 0);
	free(buff);
}
