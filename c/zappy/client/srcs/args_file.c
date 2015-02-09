/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obengelo <obengelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/10 21:27:18 by obengelo          #+#    #+#             */
/*   Updated: 2014/06/26 19:49:22 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/client.h"

t_param		*get_port(t_param *e, char **av, int *i)
{
	*i = *i + 1;
	if (av[*i] && ft_strncmp(av[*i], "-", 1) != 0)
	{
		e->port = ft_atoi(ft_strtrim(av[*i]));
		*i = *i + 1;
	}
	else
		ft_puterror("you write -p but you don't specify the port number");
	return (e);
}

t_param		*get_team(t_param *e, char **av, int *i)
{
	*i = *i + 1;
	if (av[*i] && ft_strncmp(av[*i], "-", 1) != 0)
	{
		e->flag = 1;
		e->team = ft_strdup(ft_strtrim(av[*i]));
		*i = *i + 1;
	}
	else
		ft_puterror("you write -n but you don't specify a name of team");
	return (e);
}

t_param		*get_hostname(t_param *e, char **av, int *i)
{
	*i = *i + 1;
	if (av[*i] && ft_strncmp(av[*i], "-", 1) != 0)
	{
		e->hostname = ft_strdup(ft_strtrim(av[*i]));
		*i = *i + 1;
	}
	else
		ft_puterror("you write -n but you don't specify a name of team");
	return (e);
}

t_param		*get_info(char **av, int *i, t_param *param)
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
