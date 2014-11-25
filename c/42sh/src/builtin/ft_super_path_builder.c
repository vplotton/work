/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_super_path_builder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-goug <ele-goug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 21:34:22 by ele-goug          #+#    #+#             */
/*   Updated: 2014/03/27 21:34:28 by ele-goug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <meh.h>

t_bool		ft_super_path(t_strlst *pp, struct s_path *path, int len)
{
	char	*xpath;

	xpath = malloc(len + 2);
	len = 0;
	if (!pp)
		xpath[len++] = SPRT;
	else
	{
		while (pp)
		{
			xpath[len++] = SPRT;
			ft_strxcpy(xpath, (*pp).x, &len);
			ft_lstrem(&pp);
		}
	}
	xpath[len] = '\0';
	if (ft_isdir(xpath))
	{
		free((*path).cdir);
		(*path).cdir = xpath;
		return (TRUE);
	}
	free(xpath);
	return (FALSE);
}
