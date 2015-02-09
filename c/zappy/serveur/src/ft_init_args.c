/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obengelo <obengelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/10 16:23:35 by obengelo          #+#    #+#             */
/*   Updated: 2014/06/17 17:46:20 by obengelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

t_arguments		*ft_init_args(t_arguments *e)
{
	ft_strcpy(e->args[0].name, "-p");
	(e->args[0]).fct = &get_port;
	ft_strcpy((e->args[1]).name, "-x");
	(e->args[1]).fct = &get_x;
	ft_strcpy((e->args[2]).name, "-y");
	(e->args[2]).fct = &get_y;
	ft_strcpy((e->args[3]).name, "-n");
	(e->args[3]).fct = &get_team;
	ft_strcpy((e->args[4]).name, "-c");
	(e->args[4]).fct = &get_nb_player;
	ft_strcpy((e->args[5]).name, "-t");
	(e->args[5]).fct = &get_time;
	e->flag = 0;
	return (e);
}

t_arguments		*get_info(char **av, int *i, t_arguments *param)
{
	int			j;

	j = 0;
	while (j < AC)
	{
		if (ft_strcmp(param->args[j].name, av[*i]) == 0)
			return (param->args[j].fct(param, av, i));
		j++;
	}
	*i = *i + 1;
	return (param);
}

t_arguments		*ft_parse_av(char **av, t_arguments *param)
{
	int			i;

	i = 1;
	while (av[i])
		param = get_info(av, &i, param);
	if (param->flag == 0)
	{
		printf("you must give at least a name of team\n");
		exit(0);
	}
	return (param);
}
