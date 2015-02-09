/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/10 16:34:25 by obengelo          #+#    #+#             */
/*   Updated: 2014/06/26 11:26:18 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

t_arguments		*get_port(t_arguments *e, char **av, int *i)
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

t_arguments		*get_x(t_arguments *e, char **av, int *i)
{
	*i = *i + 1;
	if (av[*i] && ft_strncmp(av[*i], "-", 1) != 0)
	{
		e->mapx = ft_atoi(ft_strtrim(av[*i]));
		if (e->mapx <= 0)
			ft_puterror("ARE YOU KINDING ME ??? WRONG X VALUE");
		*i = *i + 1;
	}
	else
		ft_puterror("you write -x but you don't specify the x value");
	return (e);
}

t_arguments		*get_y(t_arguments *e, char **av, int *i)
{
	*i = *i + 1;
	if (av[*i] && ft_strncmp(av[*i], "-", 1) != 0)
	{
		e->mapy = ft_atoi(ft_strtrim(av[*i]));
		if (e->mapy <= 0)
			ft_puterror("ARE YOU KINDING ME ??? WRONG y VALUE");
		*i = *i + 1;
	}
	else
		ft_puterror("you write -y but you don't specify the x value");
	return (e);
}

int				ft_get_nb_team(char **av, int i)
{
	int			nb;
	char		*new_str;

	nb = 0;
	new_str = ft_strtrim(av[i]);
	while (av[i] && ft_strncmp(new_str, "-", 1) != 0)
	{
		nb++;
		i++;
		new_str = ft_strtrim(av[i]);
	}
	return (nb);
}

t_arguments		*get_nb_player(t_arguments *e, char **av, int *i)
{
	*i = *i + 1;
	if (av[*i] && ft_strncmp(av[*i], "-", 1) != 0)
	{
		e->player_max = ft_atoi(ft_strtrim(av[*i]));
		*i = *i + 1;
	}
	else
		ft_puterror("you write -c but no value after it");
	return (e);
}
