/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 17:57:36 by vplotton          #+#    #+#             */
/*   Updated: 2014/06/09 20:30:08 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ia_zappy.h"

extern int	 move[5];

t_bool	live(t_env **env, t_player *player, t_layer layer, t_bool opt)
{
	int			i;
	t_ipos		pos;
	double		*out;
	static int	prec = 1;

	(void)opt;
	i = -1;
	out = ft_memalloc(layer.n_out * sizeof(double));
/*	printf("layer.n_out: %d\n", layer.n_out);*/
	while (++i < layer.n_out)
	{
/*		if (opt == TRUE)
			printf("out[%d] = %f\n", i, layer.neuron[i].out);*/
		out[i] = layer.neuron[i].out;
	}
	if (out[0] > out[1])
	{
		move[0]++;
		if (get_rsrc(FOOD, player, env) == TRUE)
		{
			move[4]++;
			srand(prec * time(NULL));
			prec = rand();
			pos.x = prec % WIDTH;
			srand(prec * time(NULL));
			prec = rand();
			pos.y = prec % WIDTH;
			(*env)->map[pos.y][pos.x].rsrc[FOOD]++;
			return (TRUE);
		}
		else
			return (FALSE);
	}
	else if (out[1] > out[2])
	{
		move[1]++;
		translate(UP, player, env);
	}
	else if ((int)(out[2] * 10000) % 2 == 1)
	{
		move[2]++;
		rotate(LEFT, player);
	}
	else
	{
		move[3]++;
		rotate(RIGHT, player);
	}
	return (TRUE);
}
