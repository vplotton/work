/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genetic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 21:24:46 by vplotton          #+#    #+#             */
/*   Updated: 2014/06/09 20:10:22 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ia_mlp.h"
#include	<stdio.h>

static int	review_ranking(t_gen *gen, int j)
{
	int		i;

	i = 0;
	while (i < gen->n_nets)
	{
		if (gen->ranking[i] == j)
			break ;
		i++;
	}
	return (i);
}

static void	set_ranking(t_gen **gen)
{
	int		i;
	int		j;
	double	max;

	i = 0;
	while (i < (*gen)->n_nets)
	{
		j = 0;
		max = 0.0;
		while (j < (*gen)->n_nets)
		{
			if (review_ranking(*gen, j) == (*gen)->n_nets
					&& max < (*gen)->fitness[j])
				max = (*gen)->fitness[j];
			j++;
		}
		j = 0;
		while (j < (*gen)->n_nets)
		{
			if ((*gen)->fitness[j] == max)
				(*gen)->ranking[i++] = j;
			j++;
		}
	}
}
/*
static void	mutate(t_net *net, double *delta, int n_nets, int k)
{
	int		max;

	max = n_nets * (PERC_ST + PERC_UNT) / 100;
	back_propagate(net, delta);
	if (k > max)
		gen_input_weight(&net->layer[0], 0);
}
*/
void	mute_nets(t_gen **gen)
{
	int		i;
	int		k;
	int		range[2];

	set_ranking(gen);
/*	while (++i < (*gen)->n_nets)
		printf("rank[%d]: %d\n", (*gen)->ranking[i], i);*/
	set_delta(gen);
	range[0] = (*gen)->n_nets * PERC_UNT / 100;
	i = 0;
	while (i < (*gen)->n_nets)
	{
		k = (*gen)->ranking[i];
		if (k > range[1])
		{
			(*gen)->moy_fitness[k] = 0.0;
			reset_net(&(*gen)->net[k]);
		}
		i++;
	}
	i = 0;
}
