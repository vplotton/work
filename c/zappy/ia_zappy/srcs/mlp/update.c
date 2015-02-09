/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 19:55:47 by vplotton          #+#    #+#             */
/*   Updated: 2014/06/09 15:45:54 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ia_mlp.h"
#include <stdio.h>

void	set_delta(t_gen **gen)
{
	int		i;
	int		j;
	t_layer	l_top;
	t_layer	l_cur;

	i = 0;
	l_top = (*gen)->net[TOP].layer[(*gen)->net[TOP].n_tot - 1];
	while (i < (*gen)->n_nets)
	{
		if (i != TOP)
		{
			l_cur = (*gen)->net[i].layer[(*gen)->net[i].n_tot - 1];
			j = 0;
			while (j < l_top.n_out)
			{
				(*gen)->error[i] += 0.5
					* (l_top.neuron[j].out - l_cur.neuron[j].out)
					* (l_top.neuron[j].out - l_cur.neuron[j].out);
				(*gen)->delta[i][j] =
					(l_top.neuron[j].out - l_cur.neuron[j].out)
					* l_cur.neuron[j].out * (1.0 - l_cur.neuron[j].out);
				j++;
			}
		}
		i++;
	}
}

void	back_propagate(t_net *net, double *delta)
{
	int		i;
	int		j;
	int		k;
	double	sum;
	t_layer	layer;

	i = net->n_tot - 1;
	while (i)
	{
		j = 0;
		layer = net->layer[i];
/*		printf("layer[%d] | n_in: %d | n_out: %d\n", i, layer.n_in, layer.n_out);*/
		delta = (i == net->n_tot - 1 ? delta : net->layer[i + 1].delta);
		while (j < layer.n_in)
		{
			k = 0;
			sum = 0.0;
			while (++k < layer.n_out)
			{
				sum += layer.neuron[j].weight[k] * delta[k];
/*				printf("sum: %f -- weight: %f -- delta: %f\n"
						, sum, layer.neuron[j].weight[k], delta[k]);*/
				k++;
			}
/*			printf("sum: %f -- neuron[%d].out: %f\n"
 				, sum, j, layer.neuron[j].out);*/
			layer.delta[j] = sum * layer.neuron[j].out
				* (1.0 - layer.neuron[j].out);
/*			printf("delta[%d] = %f\n", j, layer.delta[j])*/;
			k = 0;
			while (k < layer.n_out)
			{
				layer.neuron[j].d_weight[k] = ETA * layer.neuron[j].in
					* delta[j] + ALPHA * layer.neuron[j].d_weight[k];
/*				printf("Before: layer.neuron[%d].weight[%d]: %f\n"
						, j, k, layer.neuron[j].weight[k]);*/
				layer.neuron[j].weight[k] += layer.neuron[j].d_weight[k];
/*				printf("After: layer.neuron[%d].weight[%d]: %f\n"
						, j, k, layer.neuron[j].weight[k]);*/
				k++;
			}
			j++;
		}
		i--;
	}
}

/*
   void	update_weight(t_layer *layer, double *delta, int l, int j)
   {
   int		i;
   int		j;
   int		l;
   t_layer	layer;

   i = 0;
   while (++i < net->n_tot)
   {
   j = -1;
   layer = net->layer[i];
   while (++j < net->layer[i].n_out)
   {
   l = -1;
   while (++l < net->layer[i].n_in)
   {
   layer->neuron[j].d_weight[l] = ETA * layer->neuron[j].in
 * delta[l] + ALPHA * layer->neuron[j].d_weight[l];
 printf("Before: %f\n", layer->neuron[j].weight[l]);
 layer->neuron[j].weight[l] += layer->neuron[j].d_weight[l];
 printf("After: %f\n\n", layer->neuron[j].weight[l]);
 }
 }
 }
 }
 */
