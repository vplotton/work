/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fth_ndeg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 22:30:05 by sbres             #+#    #+#             */
/*   Updated: 2014/06/26 12:07:22 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

void		ft_number_of_teams(char *buffer, t_env *env, int fd)
{
	int		x;
	char	buff[1024];

	x = 0;
	while (env->world->teams[x] != NULL)
		x++;
	buff[0] = '\0';
	ft_strcat(buff, ft_itoa(x));
	ft_strcat(buff, "\n");
	create_message(env, buff, fd, 0);
	(void)buffer;
}
