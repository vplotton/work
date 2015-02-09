/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_handelers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 04:48:23 by obengelo          #+#    #+#             */
/*   Updated: 2014/06/26 12:37:16 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

void			no_found(t_env *env, char *message, int fd)
{
	printf("not found !\n");
	create_message(env, "ko\n", fd, env->what_time_is_it);
	printf("'%s' not found !\n", message);
	return ;
	(void)env;
	(void)message;
	(void)fd;
}

t_env			*ft_create_handelers(t_env *env)
{
	env->handelers[0] = avance;
	env->handelers[1] = droite;
	env->handelers[2] = gauche;
	env->handelers[3] = voir;
	env->handelers[4] = inventaire;
	env->handelers[5] = prend;
	env->handelers[6] = pose;
	env->handelers[7] = expulse;
	env->handelers[8] = broadcast;
	env->handelers[9] = incantation;
	env->handelers[10] = hfork;
	env->handelers[11] = connect_nbr;
	env->handelers[12] = no_found;
	return (env);
}

t_env			*ft_create_handelers_to_do(t_env *env)
{
	env->to_do[0] = create_egg;
	env->to_do[1] = create_the_player;
	env->to_do[2] = check_incatation;
	env->to_do[3] = final_incantation;
	return (env);
}
