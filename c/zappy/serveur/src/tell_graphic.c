/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tell_graphic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 10:48:58 by sbres             #+#    #+#             */
/*   Updated: 2014/06/26 11:23:50 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

void	tell_graphic(t_env *env, char *message, double ttsend)
{
	t_graphic		*tmp;

	tmp = env->graphic;
	while (tmp)
	{
		create_message(env, message, tmp->fd, ttsend);
		tmp = tmp->next;
	}
}
