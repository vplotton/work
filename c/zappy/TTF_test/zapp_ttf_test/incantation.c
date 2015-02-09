/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incantation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 22:34:25 by jbernabe          #+#    #+#             */
/*   Updated: 2014/06/08 23:33:00 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy_graph.h"

ft_get_for_incatation(int x, int y, t_env *env, t_player *orig_player)
{
    int     i;

    i = 0;
    while (i < MAX_PLAYER)
    {
        /*verifier les resources par rapport son level
        *lancer l'invocation au serveur
        *augente de niveau le jouer en vours et tous le jouers present sur la case
        env->map[y][x].ids[i]
        *** si le player a un niveau superieur il ne augmente pas
        le reste oui*****/
        if (env->map[orig_player->pos.y][orig_player->pos.x].ids[i] == TRUE
        	&& ft_cmp_level(env->pl[i], orig_player))
        {           
            ft_get_team_info(env->pl[i], &(env->itf->team[j]));
        }
        i++;
    }
}
