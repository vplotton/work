/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 22:56:48 by sbres             #+#    #+#             */
/*   Updated: 2014/06/26 20:26:33 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

int		ft_analyse(char *str)
{
	static char		**comands = NULL;
	int				counter;

	counter = 0;
	if (comands == NULL)
		comands = ft_strsplit(ft_strjoin(COMAND_D, COMAND_E), '|');
	while (comands[counter] != NULL)
	{
		if (!ft_strncmp_tf(str, comands[counter],
			(ft_strlen(comands[counter]) - 1)))
			return (counter);
		counter++;
	}
	return (counter);
}

int		is_grapich(t_graphic *grapic, int fd)
{
	t_graphic	*tmp;

	tmp = grapic;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	del_player(t_env *env, int fd)
{
	char			*team;
	int				i;

	FD_CLR(fd, &(env->master));
	if (env->pl[fd] != NULL)
	{
		env->map[env->pl[fd]->pos.y][env->pl[fd]->pos.x].nb_pl--;
		i = 0;
		while (env->world->teams[i] != NULL)
		{
			ft_get_player(env, fd);
			team = ft_strtrim(env->pl[fd]->team);
			if (ft_strcmp(team, env->world->teams[i]) == 0)
				break ;
			i++;
		}
		env->conections[i]--;
	}
	else
		ft_del_graphique(env, fd);
	env->pl[fd] = NULL;
	close(fd);
	return ;
}

void	handle_it_fd(t_env *env, int fd, char *buff)
{
	if (is_new_user(env, fd))
	{
		handle_new_user(env, fd, buff);
		return ;
	}
	if (is_grapich(env->graphic, fd))
	{
		ft_get_cmd(buff, env, fd);
		return ;
	}
	FD_CLR(fd, &(env->master));
	close(fd);
	return ;
}

void	ft_handle_input(t_env *env, int fd)
{
	char			buff[1024];
	int				rc;

	rc = recv(fd, buff, sizeof(buff), 0);
	buff[rc] = '\0';
	if (rc == 0)
	{
		del_player(env, fd);
		return ;
	}
	if (env->pl[fd] == NULL)
	{
		handle_it_fd(env, fd, buff);
		return ;
	}
	if (env->pl[fd]->queu_request >= 10)
	{
		create_message(env, "ko\n", fd, 0);
		return ;
	}
	else
		env->pl[fd]->queu_request++;
	rc = ft_analyse(buff);
	(*env->handelers[rc])(env, buff, fd);
}
