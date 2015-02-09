/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_incatation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 09:59:17 by sbres             #+#    #+#             */
/*   Updated: 2014/06/26 02:50:06 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

void	check_incatation(t_env *env, t_to_do *todo)
{
	t_to_do		*tmp;
	t_to_do		*tmp2;

	tmp2 = (t_to_do *)malloc(sizeof(t_to_do));
	tmp2->next = NULL;
	tmp2->time_to_do = env->what_time_is_it + 300;
	tmp2->action = 3;
	tmp2->player = todo->player;
	tmp2->x = env->pl[todo->player]->pos.x;
	tmp2->y = env->pl[todo->player]->pos.y;
	tmp = env->todo;
	if (tmp == NULL)
	{
		env->todo = tmp2;
		return ;
	}
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = tmp2;
}
