/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obengelo <obengelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/10 21:12:14 by obengelo          #+#    #+#             */
/*   Updated: 2014/06/10 23:24:09 by obengelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/client.h"

void			ft_puterror(char *msg)
{
	printf("%s\n", msg);
	exit(0);
}

t_param			*ft_init_args(t_param *e)
{
	ft_strcpy((e->args[0]).name, "-n");
	(e->args[0]).fct = &get_team;
	ft_strcpy(e->args[1].name, "-p");
	(e->args[1]).fct = &get_port;
	ft_strcpy(e->args[2].name, "-h");
	(e->args[2]).fct = &get_hostname;
	e->flag = 0;
	return (e);
}

t_param			*default_word(t_param *tmp)
{
	tmp->port = 4242;
	tmp->team = NULL;
	tmp->hostname = ft_strdup("127.0.0.1");
	return (tmp);
}

t_param			*ft_parse_av(char **av, t_param *param)
{
	int			i;

	i = 1;
	while (av[i])
		param = get_info(av, &i, param);
	if (param->flag == 0)
	{
		printf("You should enter the name of the team\n");
		exit(0);
	}
	return (param);
}

t_param			*ft_parse_args(char **av)
{
	t_param	*e;

	e = (t_param *)malloc(sizeof(t_param));
	if (e == NULL)
		ft_puterror("Malloc error");
	e = ft_init_args(e);
	e = default_word(e);
	e = ft_parse_av(av, e);
	return (e);
}
