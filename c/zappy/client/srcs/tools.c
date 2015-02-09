/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 19:09:19 by vplotton          #+#    #+#             */
/*   Updated: 2014/06/26 06:31:41 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"client.h"

void	ft_join(char **msg, char *add, int nb, t_bool opt)
{
	char	*tmp_nb;
	char	*tmp;

	tmp = *msg;
	if (nb != -1)
	{
		tmp_nb = ft_itoa(nb);
		*msg = ft_strjoin(*msg, tmp_nb);
		ft_strdel(&tmp_nb);
	}
	else if (add)
		*msg = ft_strjoin(*msg, add);
	if (tmp)
		ft_strdel(&tmp);
	if (opt > FALSE)
	{
		tmp = *msg;
		*msg = (opt == TRUE ? ft_strjoin(*msg, " ") : ft_strjoin(*msg, "\n"));
		if (tmp)
			ft_strdel(&tmp);
	}
}

int		get_rand(int mod)
{
	static int	prev = 1;

	srand(prev * time(NULL));
	prev = rand();
	return (prev % mod);
}
