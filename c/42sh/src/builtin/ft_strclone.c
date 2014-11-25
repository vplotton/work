/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-goug <ele-goug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 21:32:21 by ele-goug          #+#    #+#             */
/*   Updated: 2014/03/27 21:32:23 by ele-goug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<meh.h>

char	*ft_strclone(char *name)
{
	long		cn_len;
	long long	i;
	char		*cname;

	i = 0;
	cn_len = ft_strlen(name);
	cname = (char *)malloc(cn_len + 1);
	while (*name)
	{
		cname[i] = *name;
		i++;
		name++;
	}
	cname[i] = '\0';
	return (cname);
}
