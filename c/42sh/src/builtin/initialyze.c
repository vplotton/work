/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialyze.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-goug <ele-goug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 21:35:25 by ele-goug          #+#    #+#             */
/*   Updated: 2014/03/27 21:35:47 by ele-goug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <meh.h>

void	ft_session_init(void)
{
	extern char		**environ;

	if (environ && *environ)
		session.env = ft_strsclone(environ);
	else
		session.env = NULL;
	session.exit = FALSE;
	session.return_code = 0;
	if (!(session.path.home = ft_getenv(session.env, "HOME")))
		session.path.home = ft_strclone("/");
	if (!(session.path.cdir = ft_getenv(session.env, "PWD")))
		session.path.cdir = ft_strclone("/");
	session.in = NULL;
}

void	ft_session_clear(void)
{
	if (session.env)
		ft_rem(session.env);
	if (session.path.home)
		free(session.path.home);
	if (session.path.cdir)
		free(session.path.cdir);
}
