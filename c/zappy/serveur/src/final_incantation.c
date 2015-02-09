/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_incantation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 10:14:45 by sbres             #+#    #+#             */
/*   Updated: 2014/06/26 15:28:31 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

extern int g_incant[8][7];

static	void	graphic_incantation_t(t_env *env, t_to_do *todo, int ok)
{
	char	bufff[1024];

	bufff[0] = '\0';
	ft_strcat(bufff, "pie ");
	ft_strcat(bufff, ft_itoa(todo->x));
	ft_strcat(bufff, " ");
	ft_strcat(bufff, ft_itoa(todo->y));
	if (ok == 0)
		ft_strcat(bufff, " 1");
	else
		ft_strcat(bufff, " 0");
	tell_graphic(env, bufff, 0);
}

static void		tell_players_t(t_env *env, t_to_do *todo, int ok)
{
	int		i;
	char	buff[1024];

	i = 0;
	while (i < MAX_PLAYER)
	{
		if (env->pl[i] != NULL)
		{
			if (env->pl[todo->player]->pos.x == env->pl[i]->pos.x
				&& env->pl[todo->player]->pos.y == env->pl[i]->pos.y)
			{
				if (ok == 0)
					env->pl[i]->lvl++;
				buff[0] = '\0';
				ft_strcat(buff, "niveau actuel : ");
				ft_strcat(buff, ft_itoa(env->pl[i]->lvl));
				ft_strcat(buff, "\n");
				create_message(env, buff, i, 0);
			}
		}
		i++;
	}
}

void			final_incantation(t_env *env, t_to_do *todo)
{
	int		ok;
	int		i;

	ok = 0;
	i = 1;
	if (env->pl[todo->player] == NULL)
		return ;
	if (env->pl[todo->player]->pos.x != todo->x)
		ok = 1;
	if (env->pl[todo->player]->pos.y != todo->y)
		ok = 2;
	if (g_incant[env->pl[todo->player]->lvl][0] <
		env->map[todo->y][todo->x].nb_pl)
		ok = 3;
	while (i < 7)
	{
		if (g_incant[env->pl[todo->player]->lvl][i] >
			env->map[todo->y][todo->x].rsrc[i])
			ok = i + 3;
		i++;
	}
	i = 0;
	graphic_incantation_t(env, todo, ok);
	tell_players_t(env, todo, ok);
}
