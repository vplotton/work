/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_new_users.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 17:44:16 by sbres             #+#    #+#             */
/*   Updated: 2014/06/26 12:19:50 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

void	new_user_conected(t_env *env, int fd)
{
	t_new_user	*tmp;
	t_new_user	*tmp_n;

	tmp_n = (t_new_user *)malloc(sizeof(tmp_n));
	tmp_n->next = NULL;
	tmp_n->fd = fd;
	tmp = env->new_users;
	if (tmp == NULL)
	{
		env->new_users = tmp_n;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = tmp_n;
}

int		is_new_user(t_env *env, int fd)
{
	t_new_user	*tmp;

	tmp = env->new_users;
	while (tmp != NULL)
	{
		if (tmp->fd == fd)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	handle_new_user(t_env *env, int fd, char *team)
{
	if (!ft_strncmp_tf(team, "GRAPHIC\n", 8))
		ft_create_user_e(env, fd, NULL);
	else
		ft_create_user_e(env, fd, team);
	dell_new_user(env, fd);
}

void	dell_new_user(t_env *env, int fd)
{
	t_new_user	*tmp;
	t_new_user	*tmp_b;

	tmp_b = NULL;
	tmp = env->new_users;
	while (tmp)
	{
		if (tmp->fd == fd)
			break ;
		tmp_b = tmp;
		tmp = tmp->next;
	}
	if (tmp_b == NULL)
	{
		env->new_users = (tmp ? tmp->next : NULL);
		free(tmp);
		return ;
	}
	if (tmp == NULL)
		return ;
	tmp_b->next = tmp->next;
	free(tmp);
	return ;
}
