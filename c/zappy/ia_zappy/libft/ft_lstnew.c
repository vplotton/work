/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 15:44:24 by vplotton          #+#    #+#             */
/*   Updated: 2014/01/10 15:44:24 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*n_elt;

	n_elt = (t_list *)malloc(sizeof(t_list));
	if (n_elt == NULL)
		return (NULL);
	if (content == NULL)
	{
		n_elt->content = NULL;
		n_elt->content_size = 0;
	}
	else
	{
		n_elt->content = (void *)malloc(content_size);
		n_elt->content =
			ft_memcpy(n_elt->content, content, content_size);
		n_elt->content_size = content_size;
		n_elt->next = NULL;
	}
	return (n_elt);
}
