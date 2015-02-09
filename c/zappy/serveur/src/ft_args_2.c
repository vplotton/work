/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obengelo <obengelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/10 16:34:37 by obengelo          #+#    #+#             */
/*   Updated: 2014/06/25 23:16:29 by obengelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

void			ft_puterror(char *msg)
{
	printf("%s\n", msg);
	exit(0);
}

t_arguments		*get_team(t_arguments *e, char **av, int *i)
{
	int			nb_team;
	int			j;

	j = 0;
	*i = *i + 1;
	if (av[*i] && ft_strncmp(av[*i], "-", 1) != 0)
	{
		e->flag = 1;
		nb_team = ft_get_nb_team(av, *i);
		e->teams = (char **)malloc(sizeof(char *) * (nb_team + 1));
		if (e->teams == NULL)
			ft_puterror("Malloc error");
		e->teams[nb_team] = NULL;
		while (j < nb_team)
		{
			e->teams[j] = ft_strtrim(av[*i]);
			if (ft_strcmp(e->teams[j], "Graphic") == 0)
				ft_puterror("the name Graphic is reserved choose another one.");
			j++;
			*i = *i + 1;
		}
	}
	else
		ft_puterror("you write -n but you don't specify a name of  one team");
	return (e);
}

t_arguments		*get_time(t_arguments *e, char **av, int *i)
{
	*i = *i + 1;
	if (av[*i] && ft_strncmp(av[*i], "-", 1) != 0)
	{
		e->t_time = ft_atoi(ft_strtrim(av[*i]));
		*i = *i + 1;
	}
	else
	{
		printf("you write -t but you don't specify the value of t\n");
		exit(0);
	}
	return (e);
}
