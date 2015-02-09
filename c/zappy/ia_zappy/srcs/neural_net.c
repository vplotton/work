/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neural_net.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 19:34:47 by vplotton          #+#    #+#             */
/*   Updated: 2014/06/09 20:40:21 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ia_zappy.h"

int		move[5];

void	get_input(t_layer *layer, t_env *env, t_player *player, t_bool ret)
{
	double  val;

	val = 0.0;
	layer->neuron[0].out = (double)detect(FOOD, env, player);
	layer->neuron[1].out = 0.0;
	layer->neuron[2].out = 0.0;
	layer->neuron[3].out = 0.0;
	layer->neuron[4].out = detect_rtv_sq(0, FOOD, env, player);
	layer->neuron[5].out = detect_rtv_sq(1, FOOD, env, player);
	layer->neuron[6].out = detect_rtv_sq(2, FOOD, env, player);
	layer->neuron[7].out = detect_rtv_sq(3, FOOD, env, player);
	layer->neuron[8].out = (double)ret;
}

void	feed_net(t_net *net, t_env *env, t_player *player, t_bool ret)
{
	int		i;

	i = 1;
	get_input(&net->layer[0], env, player, ret);
	while (i < net->n_tot)
	{
		feed_layer(&net->layer[i], &net->layer[i - 1]);
	/*	printf("net->layer[%d].neuron[0].out: %f\n"
		, i, net->layer[i].neuron[0].out);*/
		i++;
	}
}

t_bool	process_ia(t_env *env, t_player *player)
{
	t_bool		ret;
	int			i;
	int			j;
	int			k;
	int			turn;
	t_gen		*gen;
	t_info		info;
	double		*fitness;
	double		*food;

	ret = TRUE;
	move[0] = 0;
	move[1] = 0;
	move[2] = 0;
	move[3] = 0;
	move[4] = 0;
	food = ft_memalloc(N_TEST * sizeof(double));
	fitness = ft_memalloc(N_TEST * sizeof(double));
	turn = 0;
	i = 0;
	info.n_in = N_IN;
	info.n_hid = N_HID;
	info.n_out = N_OUT;
	create_gen(&gen, N_NET, info);
	printf("N_NETS: %d | N_IN: %d | N_OUT: %d | N_TEST: %d | MAX_TURN: %d\n"
			, N_NET, N_IN, N_OUT, N_TEST, MAX_TURN);
	while (i < N_TEST)
	{
		j = 0;
		while (j < N_NET)
		{
			k = 0;
			reset_map(&env);
			player->rsrc[FOOD] = 0;
			while (k < MAX_TURN)
			{
				feed_net(&gen->net[j], env, player, ret);
				ret = live(&env, player, gen->net[j].layer[gen->net[j].n_tot - 1]
					, FALSE);
				k++;
				food[i] += (double)detect(FOOD, env, player);
			}
			gen->fitness[j] = (double)player->rsrc[FOOD];
			gen->moy_fitness[j] = gen->fitness[j];
			fitness[i] += gen->fitness[j];
			j++;
		}
		fitness[i] = fitness[i] / (double)N_NET;
		food[i] = food[i] / ((double)N_NET * (double)MAX_TURN); 
		if (i % (N_TEST / 10) == 0)
		{
			printf("=== === === === === === === === \n");
			printf("fitness[%d]: %f\n", i, fitness[i]);
			printf("food[%d]: %f\n", i, food[i]);
			k = move[0] + move[1] + move[2] + move[3];
			printf("move perc: %f%% | %f%% | %f%% | %f%% | %f%%\n\n"
					, 100 * (double)move[0]/k
					, 100 * (double)move[1]/k
					, 100 * (double)move[2]/k
					, 100 * (double)move[3]/k
					, 100 * (double)move[4]/k);
		}
		k = 0;
		while (k < N_NET)
		{
			gen->ranking[k] = -1;
			k++;
		}
		mute_nets(&gen);
		i++;
	}
	k = 0;
	i = -1;
	while (++i < N_TEST)
	{
		k += fitness[i];
		j = move[0] + move[1] + move[2] + move[3];
		if (i % (N_TEST / 10) == 0)
			printf("fitness test %d: %f\n", i, fitness[i]);
	}
	printf("Moy. fitness %f\n", (double)k / N_TEST);
	j = 0;
	printf("moves: %d | %d | %d | %d | %d\n"
			, move[0], move[1], move[2], move[3], move[4]);
	i = move[0] + move[1] + move[2] + move[3];
	printf("move perc: %f%% | %f%% | %f%% | %f%% | %f%%\n"
			, 100 * (double)move[0]/i
			, 100 * (double)move[1]/i
			, 100 * (double)move[2]/i
			, 100 * (double)move[3]/i
			, 100 * (double)move[4]/i);
	return (TRUE);
}
