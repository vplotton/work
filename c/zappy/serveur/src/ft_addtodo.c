/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addtodo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/21 18:50:23 by sbres             #+#    #+#             */
/*   Updated: 2014/06/26 20:30:51 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

void	addtodo(t_env *env, double time_to_do, int fontion, int pl)
{
	t_to_do		*tmp;
	t_to_do		*tmp2;

	tmp2 = (t_to_do *)malloc(sizeof(t_to_do));
	tmp2->next = NULL;
	tmp2->time_to_do = time_to_do;
	tmp2->action = fontion;
	tmp2->player = pl;
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

t_eggs	*get_xy(t_eggs *tmp, int x, int y, int team)
{
	tmp->next = NULL;
	tmp->team = team;
	tmp->x = x;
	tmp->y = y;
	return (tmp);
}

int		create_egg_env(t_env *env, int team, int x, int y)
{
	t_eggs	*tmp;
	t_eggs	*tmp_n;
	int		i;

	tmp = env->egg;
	tmp_n = (t_eggs *)malloc(sizeof(t_eggs));
	tmp_n = get_xy(tmp_n, x, y, team);
	tmp_n->fdpl = -1;
	tmp_n->time = env->what_time_is_it + 600;
	i = 0;
	if (tmp == NULL)
	{
		tmp_n->egg_nb = 0;
		env->egg = tmp_n;
		return (0);
	}
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	tmp_n->egg_nb = i;
	tmp->next = tmp_n;
	return (i);
}
