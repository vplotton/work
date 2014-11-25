/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poda.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-goug <ele-goug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 01:44:10 by ele-goug          #+#    #+#             */
/*   Updated: 2014/03/27 21:36:45 by ele-goug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <meh.h>
#include <main.h>

char	*ft_get_absolute_path(char *rpath)
{
	char	*apath;

	if (!rpath[0] && !rpath[1] && !rpath[2])
		return (NULL);
	if (*rpath == SPRT)
		apath = ft_strclone(rpath);
	else if (*rpath == '~')
		apath = ft_path_builder(session.path.home, rpath + 2);
	else if (*rpath == '.')
		apath = ft_path_builder(session.path.cdir, rpath + 2);
	else
		apath = ft_path_builder(session.path.cdir, rpath);
	return (apath);
}

t_bool	ft_extern_call(int *entry)
{
	char			*path;
	struct stat		dts;

	path = ft_get_absolute_path(session.in[0]);
	if (!path)
		return (FALSE);
	if (!stat(path, &dts))
	{
		if (!access(path, X_OK))
		{
			session.swap =
				ft_process_pipe(session.in, path, entry, session.has_pipe);
			free(path);
			return (TRUE);
		}
	}
	free(path);
	return (FALSE);
}
