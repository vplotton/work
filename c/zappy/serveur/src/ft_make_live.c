/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_live.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obengelo <obengelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/19 15:36:07 by sbres             #+#    #+#             */
/*   Updated: 2014/06/27 01:40:02 by obengelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

void	make_peaple_starve(t_env *env)
{
	int		i;
	char	buff[1024];

	i = 0;
	while (i < MAX_PLAYER)
	{
		if (env->pl[i] != NULL)
		{
			env->pl[i]->live--;
			if (env->pl[i]->live <= 0)
			{
				buff[0] = '\0';
				ft_strcat(buff, "pdi ");
				ft_strcat(buff, ft_itoa(i));
				ft_strcat(buff, "\n");
				tell_graphic(env, buff, env->what_time_is_it);
				create_message(env, "mort\n", i, 0);
				env->pl[i] = NULL;
			}
		}
		i++;
	}
}

void	check_todo(t_env *env)
{
	t_to_do		*tmp;

	tmp = env->todo;
	while (tmp != NULL)
	{
		if (env->what_time_is_it >= tmp->time_to_do)
		{
			(*env->to_do[tmp->action])(env, tmp);
			tmp->time_to_do += 1000000000;
		}
		tmp = tmp->next;
	}
}

void	check_eggs(t_env *env)
{
	t_eggs		*tmp;
	char		buff[1024];

	tmp = env->egg;
	while (tmp != NULL)
	{
		if (tmp->fdpl == -1)
		{
			if (tmp->time <= env->what_time_is_it)
			{
				buff[0] = '\0';
				ft_strcat(buff, "edi ");
				ft_strcat(buff, ft_itoa(tmp->egg_nb));
				ft_strcat(buff, "\n");
				tell_graphic(env, buff, 0);
				tmp->time += 1000000000;
			}
		}
		tmp = tmp->next;
	}
}

void	party_is_over(t_env *env)
{
	int		i;
	char	buff[1024];

	i = 0;
	while (i < MAX_PLAYER)
	{
		if (env->pl[i] != NULL)
		{
			if (env->pl[i]->lvl == 8)
			{
				buff[0] = '\0';
				ft_strcat(buff, "seg ");
				ft_strcat(buff, ft_itoa(get_pio(env, env->pl[i]->team)));
				ft_strcat(buff, "\n");
				tell_graphic(env, buff, 0);
				addtodo(env, env->what_time_is_it + 30, 4, 0);
				break ;
			}
		}
		i++;
	}
}

void	ft_make_live(t_env *env)
{
	make_peaple_starve(env);
	check_todo(env);
	check_eggs(env);
	party_is_over(env);
}
