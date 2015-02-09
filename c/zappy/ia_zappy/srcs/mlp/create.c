/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 17:16:21 by vplotton          #+#    #+#             */
/*   Updated: 2014/06/09 17:30:56 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ia_mlp.h"

void		gen_input_weight(t_layer *layer, int n_lay)
{
	int			i;
	int			j;
	static int	prec = 1;

	i = 0;
	while (i < layer->n_in)
	{
		j = 0;
		while (j < layer->n_out)
		{
			srand(prec * time(NULL));
			prec = rand() % 100;
			if (prec == 0.0)
				prec += 0.35;
			if (prec % 2)
				prec = -prec;
			layer->neuron[i].weight[j] = ((double)(prec) - 0.1 * n_lay) / 100;
			j++;
		}
		i++;
	}
}

void		create_layer(t_layer *layer, int n_in, int n_out, int n_lay)
{
	int		i;

	i = 0;
	layer->n_in = n_in;
	layer->n_out = n_out;
	layer->threshold = 0.5;
	layer->neuron = ft_memalloc(MAX(n_in, n_out) * sizeof(t_neuron));
	layer->delta = ft_memalloc(MAX(n_in, n_out) * sizeof(double));
	while (i < n_in)
	{
		layer->neuron[i].weight = ft_memalloc(n_out * sizeof(double));
		layer->neuron[i].d_weight = ft_memalloc(n_out * sizeof(double));
		layer->neuron[i].error = 0.5;
		i++;
	}
	gen_input_weight(layer, n_lay);
}

void		create_net(t_net *net, t_info info)
{
	int     i;
	int		n_neuron;

	i = 1;
	n_neuron = (info.n_in + info.n_out) / 2;
	net->n_hid = info.n_hid;
	net->n_tot = info.n_hid + 1;
	net->layer = ft_memalloc((info.n_hid + 1) * sizeof(t_layer));
	create_layer(&net->layer[0], info.n_in, n_neuron, 0);
	while (i < net->n_hid)
	{
		create_layer(&net->layer[i], n_neuron, n_neuron, i);
		i++;
	}
	create_layer(&net->layer[i], n_neuron, info.n_out, i);
}

void		create_gen(t_gen **gen, int n_nets, t_info info)
{
	int		i;

	i = 0;
	*gen = (t_gen*)ft_memalloc(sizeof(t_gen));
	(*gen)->n_nets = n_nets;
	(*gen)->net = ft_memalloc(n_nets * sizeof(t_net));
	(*gen)->ranking = ft_memalloc(n_nets * sizeof(int));
	(*gen)->error = ft_memalloc(n_nets * sizeof(double));
	(*gen)->fitness = ft_memalloc(n_nets * sizeof(double));
	(*gen)->moy_fitness = ft_memalloc(n_nets * sizeof(double));
	(*gen)->delta = ft_memalloc(n_nets * sizeof(double *));
	while (i < n_nets)
	{
		(*gen)->ranking[i] = -1;
		i++;
	}
	i = 0;
	while (i < n_nets)
	{
		create_net(&(*gen)->net[i], info);
		(*gen)->delta[i] = ft_memalloc(info.n_out * sizeof(double));
		i++;
	}
}

void		reset_net(t_net *net)
{
	int		i;

	i = -1;
	while (++i < net->n_tot + 1)
		gen_input_weight(&net->layer[i], i);
}
