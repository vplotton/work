/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia_mlp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 20:57:44 by vplotton          #+#    #+#             */
/*   Updated: 2014/06/09 20:08:43 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IA_MLP_H
# define IA_MLP_H

# ifdef __gnu_linux__
#  include "libft.h"
# else
#  include <libft.h>
# endif

# include <math.h>
# include <time.h>
# include <stdlib.h>

# define LEARN_RATE	0.5
# define N_OUTPOUT	3
# define N_LAYER	3
# define N_INPUT	8
# define MAX_MOV	100
# define PERC_UNT	50
# define PERC_ST	30
# define PERC_AT	10
# define PERC_RST	10
# define ALPHA		0.05
# define ETA		0.1
# define TOP		(*gen)->ranking[0]
# define MAX(X,Y)	(X > Y ? X : Y)

typedef struct	s_info
{
	int			n_in;
	int			n_hid;
	int			n_out;
}				t_info;

typedef struct	s_neuron
{
	double		in;
	double		out;
	double		error;
	double		*weight;
	double		*d_weight;
}				t_neuron;

typedef struct	s_layer
{
	int			n_in;
	int			n_out;
	double		threshold;
	double		*delta;
	t_neuron	*neuron;
}				t_layer;

typedef struct  s_net
{
	int			n_hid;
	int			n_tot;
	t_layer		*layer;
}				t_net;

typedef struct	s_gen
{
	int			n_nets;
	int			*ranking;
	double		*fitness;
	double		*moy_fitness;
	double		*error;
	double		**delta;
	t_net		*net;
}				t_gen;

/*
**	GENETIC
*/
void			mute_nets(t_gen **gen);

/*
**	CREATE
*/
void			create_layer(t_layer *layer, int n_in, int n_out, int n_lay);
void			create_gen(t_gen **gen, int n_nets, t_info info);
void			create_net(t_net *net, t_info info);
void			gen_input_weight(t_layer *layer, int n_lay);
void			reset_net(t_net *net);

/*
**	UPDATE
*/
void			set_delta(t_gen **gen);
void			back_propagate(t_net *net, double *delta);
void			update_weight(t_layer *layer, double *delta, int l, int j);

/*
**	FEED
*/
void			feed_layer(t_layer *new, t_layer *prec);

#endif
