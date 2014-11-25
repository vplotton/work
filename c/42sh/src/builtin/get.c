/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-goug <ele-goug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 21:37:50 by ele-goug          #+#    #+#             */
/*   Updated: 2014/03/27 21:35:11 by ele-goug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <meh.h>

char	*ft_getenv(char **env, char *ref)
{
	char	**cenv;
	char	*tmp;

	if (!env)
		return (NULL);
	cenv = env;
	while (*cenv)
	{
		if (ft_strnvcmp(*cenv, ref))
		{
			tmp = *cenv;
			while (*tmp)
				if (*tmp++ == '=')
					break ;
			return (ft_strclone(tmp));
		}
		cenv++;
	}
	return (NULL);
}
