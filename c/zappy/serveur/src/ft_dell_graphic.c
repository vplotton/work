/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dell_graphic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obengelo <obengelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 23:21:35 by sbres             #+#    #+#             */
/*   Updated: 2014/06/27 03:00:48 by obengelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

void	that_if_lol(t_env *env, t_graphic *tmp, t_graphic *tmp_b)
{
	if (tmp_b == NULL)
	{
		if (tmp != NULL)
			env->graphic = tmp->next;
		else
			env->graphic = NULL;
		return ;
	}
	else
	{
		if (tmp != NULL)
			tmp_b->next = tmp->next;
		else
			tmp_b->next = NULL;
	}
}

void	ft_del_graphique(t_env *env, int fd)
{
	t_graphic	*tmp;
	t_graphic	*tmp_b;

	tmp = env->graphic;
	tmp_b = NULL;
	if (tmp == NULL)
		return ;
	while (tmp != NULL)
	{
		if (tmp->fd == fd)
			break ;
		tmp_b = tmp;
		tmp = tmp->next;
	}
	that_if_lol(env, tmp, tmp_b);
}
