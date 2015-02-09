/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 17:49:33 by obengelo          #+#    #+#             */
/*   Updated: 2014/06/26 19:36:27 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

void		ft_join(char **msg, char *add, int nb, int opt)
{
	char	*tmp_nb;

	if (nb != -1)
	{
		tmp_nb = ft_itoa(nb);
		*msg = ft_strjoin(*msg, tmp_nb);
	}
	else
		*msg = ft_strjoin(*msg, add);
	if (opt > 0)
	{
		*msg = ft_strjoin(*msg, (char*)&opt);
	}
}

char		*ultime_buf(char **msg, char *add, char *alt)
{
	char	*tmp;

	if (*msg == NULL)
		return (add);
	tmp = ft_strdup(*msg);
	*msg = ft_strjoin(tmp, add);
	if (alt == NULL)
		return (*msg);
	tmp = ft_strdup(*msg);
	*msg = ft_strjoin(tmp, alt);
	return (*msg);
}

void		ft_get_player(t_env *env, int fd)
{
	char	buff[1024];

	buff[0] = '\0';
	ft_strcat(buff, "pdi ");
	ft_strcat(buff, ft_itoa(fd));
	ft_strcat(buff, "\n");
	tell_graphic(env, buff, 0);
}
