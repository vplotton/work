/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incantation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 13:40:11 by sbres             #+#    #+#             */
/*   Updated: 2014/06/26 19:44:54 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

extern char	g_rsrc[7][12];
extern int g_incant[7][7];

int				incantation_posible(t_env *env, int fd)
{
	int			lvl;
	int			i;

	lvl = env->pl[fd]->lvl;
	if (g_incant[lvl][0] > env->map[PL(y)][PL(x)].nb_pl)
	{
		return (0);
	}
	i = 1;
	while (i < 7)
	{
		if (g_incant[lvl][i] > env->map[PL(y)][PL(x)].rsrc[i])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

char			*ft_get_buff(t_env *env, int fd)
{
	char		*buff;

	buff = (char *)malloc(sizeof(char) * 1024);
	if (buff == NULL)
		ft_puterror("malloc error");
	buff[0] = '\0';
	ft_strcat(buff, "pic ");
	ft_strcat(buff, ft_itoa(env->pl[fd]->pos.x));
	ft_strcat(buff, " ");
	ft_strcat(buff, ft_itoa(env->pl[fd]->pos.y));
	ft_strcat(buff, " ");
	ft_strcat(buff, ft_itoa(env->pl[fd]->lvl));
	return (buff);
}

char			*do_incantation(t_env *env, int fd)
{
	char		*buff;
	int			i;

	i = 0;
	addtodo(env, 0, 2, fd);
	buff = ft_get_buff(env, fd);
	while (i < MAX_PLAYER)
	{
		if (env->pl[i] != NULL)
		{
			if (env->pl[fd]->lvl >= env->pl[i]->lvl &&
				(env->pl[fd]->pos.x == env->pl[i]->pos.x
					&& env->pl[fd]->pos.y == env->pl[i]->pos.y))
			{
				ft_strcat(buff, " ");
				ft_strcat(buff, ft_itoa(i));
				create_message(env, "elevation en cours\n", i, 0);
			}
		}
		i++;
	}
	return (buff);
}

void			incantation(t_env *env, char *message, int fd)
{
	char	*buff;

	if (incantation_posible(env, fd) == 0)
	{
		create_message(env, "ko\n", fd, 0);
		return ;
	}
	buff = do_incantation(env, fd);
	(void)message;
	ft_strcat(buff, "\n");
	tell_graphic(env, buff, 0);
}
