/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 18:06:31 by vplotton          #+#    #+#             */
/*   Updated: 2014/06/09 15:44:18 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ia_mlp.h"
#include <stdio.h>

void	feed_layer(t_layer *new, t_layer *prec)
{
	int		i;
	int		j;

	i = 0;
/*	printf("\n=== New layer ===\n");*/
	while (i < new->n_in)
	{
		j = 0;
		new->neuron[i].in = 0.0;
		while (j < prec->n_in)
		{
			new->neuron[i].in += prec->neuron[j].out
				* prec->neuron[j].weight[i];
/*			printf("weight[%d][%d] = %f\n", j, i, prec->neuron[j].weight[i]);
			printf("prec->neuron[j].out: %f\n", prec->neuron[j].out);*/
			j++;
		}
/*		printf("new->neuron[i].in: %f\n", new->neuron[i].in);*/
		new->neuron[i].out = 1.0 / (1.0 + exp(-new->neuron[i].in));
/*		printf("new->neuron[i].out: %f\n", new->neuron[i].out);*/
		i++;
	}
}
/*
void	feed_input(int n_in, double *in, double *weight, t_layer *layer)
{
	int		i;
	int		j;

	i = -1;
	while (++i < layer->n_neuron)
	{
		j = -1;
		layer->neuron[i].in = weight[0];
		while (++j < n_in)
			layer->neuron[i].in += in[j] * weight[j][i];
		layer->neuron[i].out =  1.0 / (1.0 + exp(-layer->neuron[i].in));
	}
}

void	feed_output(int n_out, double *out, t_layer *layer)
{
	int		i;
	int		j;

	i = -1;
	while (++i < n_out)
	{
		j = -1;
		out[i] = layer->neuron[0].weight;
		while (++j < layer->n_neuron)
			out[i] += layer->neuron[j].in * layer->neuron[i].weight[j];
		out[i] = 1.0 / (1.0 + exp(-out[i]));
	}
}
void	feed_net(t_net *net, void (*get_input))
{
	int		i;

	i = 0;
	get_input(net->layer[0]);
	while (++i < net->n_tot)
		feed_layer(&net->layer[i], &net->layer[i - 1]);
}

void	feed_gen(t_gen **gen, void (*get_input))
{
	int		i;

	i = -1;
	while (++i < (*gen)->n_nets)
	{
		feed_net((*gen)->net[i], get_input);
	}
}
*/
