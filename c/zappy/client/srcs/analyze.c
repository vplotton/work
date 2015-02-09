/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 19:02:06 by vplotton          #+#    #+#             */
/*   Updated: 2014/06/26 06:14:29 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"client.h"

char	**get_broadcast(int *pos, char **msg)
{
	char	**split;
	char	**output;

	if ((split = ft_strsplit(*msg, ',')) == NULL)
		return (NULL);
	*pos = ft_atoi(split[0]);
	output = ft_strsplit(split[1], ' ');
	if (split[0])
		ft_strdel(&split[0]);
	if (split[1])
		ft_strdel(&split[1]);
	free(split);
	ft_strdel(msg);
	return (output);
}
