/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 23:04:53 by vplotton          #+#    #+#             */
/*   Updated: 2014/06/07 23:22:56 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ia_zappy.h"

extern t_rsrc	g_rsrc[7];

t_bool	get_rsrc(int rsrc, t_player *player, t_env **env)
{
	if (!(*env)->map[P(y)][P(x)].rsrc[rsrc])
		return (FALSE);
	(*env)->map[P(y)][P(x)].rsrc[rsrc]--;
	player->rsrc[rsrc] += 1;
	return (TRUE);
}

t_bool	drop_rsrc(int rsrc, t_player *player, t_env **env)
{
	if (!player->rsrc[rsrc])
		return (FALSE);
	(*env)->map[P(y)][P(x)].rsrc[rsrc] += 1;
	return (TRUE);
}

t_bool	see(t_player *player, t_env *env)
{
	if (player->blind == TRUE)
		return (FALSE);
	detect(ALL, env, player);
	return (TRUE);
}

t_bool	inventory(t_player *player)
{
	int		i;
	t_bool	print;

	i = -1;
	printf("{");
	print = FALSE;
	while (++i < 7)
	{
		if (player->rsrc[i])
		{
			if (print == TRUE)
				printf(", ");
			print = TRUE;
			printf("%s", g_rsrc[i].name);
			printf(" %d", player->rsrc[i]);
		}
	}
	printf("}\n");
	return (TRUE);
}

t_bool	send_broadcast(t_player *player, t_env *env, char *msg)
{
	int		i;
	int		pos;
	double	scal;

	i = -1;
	while (++i < MAX_PLAYER)
	{
		if (i != player->id && env->pl[i].used == TRUE)
		{
			env->pl[i].dvec = get_vec(env->pl[i].pos, player->pos);
			scal = dot_prod(player->ivec, env->pl[i].dvec);
			scal = (scal < 0 ? scal + 2 * PI : scal);
			pos = (int)(scal * 4.0 / PI);
			pos = 1 + pos + (pos % 2) - 8 * (pos / 7);
			printf("%d %s\n", pos, msg);
		}
	}
	return (TRUE);
}
