/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_builder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-goug <ele-goug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 21:31:56 by ele-goug          #+#    #+#             */
/*   Updated: 2014/03/27 21:32:05 by ele-goug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <meh.h>

char	*ft_path_builder(char *curpath, char *extention)
{
	long		cp_len;
	long		ex_len;
	long long	i;
	char		*path;

	i = 0;
	cp_len = ft_strlen(curpath);
	ex_len = ft_strlen(extention);
	path = (char *)malloc(cp_len + ex_len + 2);
	while (*curpath)
	{
		path[i] = *curpath;
		i++;
		curpath++;
	}
	path[i] = SPRT;
	while (*extention)
	{
		i++;
		path[i] = *extention;
		extention++;
	}
	path[i + 1] = '\0';
	return (path);
}
