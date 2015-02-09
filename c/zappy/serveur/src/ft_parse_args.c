/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 20:14:24 by sbres             #+#    #+#             */
/*   Updated: 2014/06/26 11:38:20 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"
#include <stdlib.h>

t_arguments		*default_word(t_arguments *tmp)
{
	tmp->port = 4242;
	tmp->mapx = 24;
	tmp->mapy = 24;
	tmp->teams = NULL;
	tmp->player_max = 4;
	tmp->t_time = 100;
	return (tmp);
}

t_arguments		*ft_parse_args(char **argv)
{
	t_arguments		*word;

	word = (t_arguments *)malloc(sizeof(t_arguments));
	if (word == NULL)
	{
		printf("Can not allocated memory\n");
		exit(-1);
	}
	word = ft_init_args(word);
	word = default_word(word);
	word = ft_parse_av(argv, word);
	return (word);
}
