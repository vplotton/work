/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fth_expulse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 16:26:28 by sbres             #+#    #+#             */
/*   Updated: 2014/06/26 11:46:01 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

static char		*get_coordination_point(t_player **player)
{
	if (V(x) == 0 && V(y) == 1)
		return ("1");
	else if (V(x) == 1 && V(y) == 0)
		return ("4");
	else if (V(x) == -1 && V(y) == 0)
		return ("2");
	else if (V(x) == 0 && V(y) == -1)
		return ("3");
	return ("3");
}

static void		translate(t_player **player, t_env *env)
{
	if (!V(x))
	{
		P(y) = (P(y) + V(y) * -1);
		P(y) = (P(y) < 0 ? P(y) + env->world->mapy : P(y) % env->world->mapy);
	}
	else
	{
		P(x) = (P(x) + V(x) * -1);
		P(x) = (P(x) < 0 ? P(x) + env->world->mapy : P(x) % env->world->mapx);
	}
}

void			expulse_tg(t_env *env, int fd, char *message)
{
	char	buff[1024];

	buff[0] = '\0';
	ft_strcat(buff, "pex ");
	ft_strcat(buff, ft_itoa(fd));
	ft_strcat(buff, "\n");
	tell_graphic(env, buff, 0);
	(void)message;
}

void			expulse(t_env *env, char *message, int fd)
{
	int		i;
	char	buff[1024];

	expulse_tg(env, fd, message);
	i = 0;
	while (i < MAX_PLAYER)
	{
		if (env->pl[i] != NULL)
		{
			if (i != fd)
			{
				if (IFEXP env->pl[i]->pos.y == env->pl[fd]->pos.y)
				{
					buff[0] = '\0';
					ft_strcat(buff, "deplacement <");
					ft_strcat(buff, get_coordination_point(&env->pl[i]));
					ft_strcat(buff, ">\n");
					create_message(env, buff, i, 0);
					translate(&env->pl[i], env);
					player_moved(env, i);
				}
			}
		}
		i++;
	}
}
