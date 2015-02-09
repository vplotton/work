/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 03:26:13 by vplotton          #+#    #+#             */
/*   Updated: 2014/06/26 03:50:34 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"client.h"

t_bool			ft_recv_fork(t_env *env, t_player *player, char *r_msg)
{
	(void)env;
	(void)player;
	if (ft_strcmp(r_msg, "ok") == 0)
		return (TRUE);
	return (FALSE);
}

t_bool			ft_fork(t_env *env)
{
	int			pid;
	t_player	new;
	t_env		*new_env;

	new_env = ft_memalloc(sizeof(t_env));
	ft_memcpy(new_env, env, sizeof(t_env));
	if ((pid = fork()) < 0)
		return (FALSE);
	if (pid == 0)
	{
		if ((new_env->s_sock = create_client(env->hostname, env->e)) == -1)
			return (FALSE);
		if (init_player(&new, env->e->mapx, env->e->mapy) == TRUE)
			live(new_env, &new);
		else
			ft_putendl_fd("Couldn't create child", 2);
		free(new_env);
		exit(0);
	}
	return (TRUE);
}
