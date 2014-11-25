/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-goug <ele-goug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 21:28:43 by ele-goug          #+#    #+#             */
/*   Updated: 2014/03/27 22:13:28 by ele-goug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <meh.h>

t_bool		ft_thisistheend(char **s)
{
	while (**s == SPRT)
		s[0]++;
	if (**s)
		return (FALSE);
	return (TRUE);
}

t_bool		ft_isdir(char *s)
{
	struct stat	dts;

	if (!stat(s, &dts))
	{
		if (S_ISDIR(dts.st_mode))
		{
			if (access(s, R_OK))
			{
				ft_putstr("I'M AFFRAID I CAN'T LET YOU DO THAT\n");
				return (FALSE);
			}
			return (TRUE);
		}
		ft_putstr("PATH IS NOT A DIRECTORY\n");
		return (FALSE);
	}
	ft_putstr("PATH MISMATCH\n");
	return (FALSE);
}

t_strlst	*ft_lstset(struct s_path *path, char *extend, int *len)
{
	if (*extend == SPRT)
	{
		*len = ft_strlen(extend);
		return (ft_lstbuild(NULL, extend));
	}
	else if (*extend == '~')
	{
		*len = ft_strlen((*path).home) + ft_strlen(extend);
		return (ft_lstbuild((*path).home, (extend + 1)));
	}
	else
	{
		*len = ft_strlen((*path).cdir) + ft_strlen(extend);
		return (ft_lstbuild((*path).cdir, extend));
	}
}

t_bool		ft_cd(struct s_path *path, char *extend)
{
	t_strlst	*pp;
	int			len;

	if (extend)
	{
		pp = ft_lstset(path, extend, &len);
		pp = ft_lstclean(pp);
		return (ft_super_path(pp, path, len));
	}
	else
	{
		free((*path).cdir);
		(*path).cdir = ft_strclone((*path).home);
	}
	return (TRUE);
}
