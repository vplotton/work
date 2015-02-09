/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_graphic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 10:05:35 by sbres             #+#    #+#             */
/*   Updated: 2014/06/26 04:19:36 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

void	ft_new_graphic(t_env *env, int fd)
{
	t_graphic	*tmp;
	t_graphic	*tmp_g;

	tmp = (t_graphic *)malloc(sizeof(t_graphic));
	tmp->fd = fd;
	tmp->next = NULL;
	tmp_g = env->graphic;
	if (tmp_g == NULL)
	{
		env->graphic = tmp;
		return ;
	}
	while (tmp_g->next != NULL)
		tmp_g = tmp_g->next;
	tmp_g->next = tmp;
}
