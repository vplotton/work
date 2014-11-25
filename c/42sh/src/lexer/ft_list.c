/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 21:15:38 by vplotton          #+#    #+#             */
/*   Updated: 2014/03/27 12:22:49 by qmarquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"lexer.h"

void	ft_add_list(t_llist **list, char *s, int arg_type)
{
	t_llist	*new;

	new = (t_llist *)ft_memalloc(sizeof(t_llist));
	new->arg = s;
	new->arg_type = arg_type;
	new->next = NULL;
	new->prev = *list;
	new->first = (*list ? (*list)->first : new);
	if (*list)
		(*list)->next = new;
	*list = new;
}

char	**ft_convert(t_llist *list)
{
	t_llist	*tmp;
	char	**output;
	int		i;
	int		size;

	i = -1;
	size = 1;
	output = NULL;
	if (!list)
		return (output);
	tmp = list;
	while ((tmp = tmp->next) != NULL && tmp->arg_type == T_CMD)
		size++;
	output = (char**)ft_memalloc((size + 1) * sizeof(char *));
	while (++i < size)
	{
		output[i] = ft_strsub(list->arg, 0, ft_strlen(list->arg));
		list = list->next;
	}
	return (output);
}

void	ft_delete_list(t_llist **list)
{
	t_llist	*tmp;

	if (list && *list)
	{
		*list = (*list)->first;
		while (*list)
		{
			tmp = (*list)->next;
			if ((*list)->arg)
				ft_strdel(&(*list)->arg);
			free(*list);
			*list = NULL;
			*list = tmp;
		}
	}
}
