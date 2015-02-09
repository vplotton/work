/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 20:00:34 by vplotton          #+#    #+#             */
/*   Updated: 2014/06/26 21:37:28 by cycharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy_graph.h"

t_bool			init_player(t_env **env)
{
	int			id;

	id = -1;
	while ((*env)->pl[++id].used == TRUE)
		;
	printf("dbut init pl\n");
	(*env)->pl[id].used = TRUE;
	(*env)->pl[id].lvl = 1;
	ft_bzero((*env)->pl[id].rsrc, sizeof((*env)->pl[id].rsrc));
	return (TRUE);
}

t_bool			init(t_env **env)
{
	if ((*env = ft_memalloc(sizeof(t_env))) == FALSE)
	{
		ft_putendl_fd("ERROR: Env not created", 2);
		return (FALSE);
	}
	(*env)->nb = 0;
	return (TRUE);
}
