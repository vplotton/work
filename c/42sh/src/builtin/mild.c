/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mild.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-goug <ele-goug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 13:13:15 by ele-goug          #+#    #+#             */
/*   Updated: 2014/03/27 21:36:35 by ele-goug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <meh.h>
#include <tmp.h>

t_execstatus	ft_case_c(void)
{
	if (ft_strmlcmp(session.in[0], "cd"))
	{
		if (ft_cd(&session.path, session.in[1]))
		{
			ft_setenv(&session.env, "PWD", session.path.cdir);
			chdir(session.path.cdir);
			return (EXEC_SUCCESS);
		}
		return (EXEC_FAILURE);
	}
	return (ABSCENT);
}

t_execstatus	ft_case_e(void)
{
	if (ft_strmlcmp(session.in[0], "echo"))
	{
		ft_echo(session.in);
		return (EXEC_SUCCESS);
	}
	else if (ft_strmlcmp(session.in[0], "env"))
	{
		if (session.env)
		{
			if (session.has_pipe)
			{
				session.swap = ft_mk_tmp(TRUE);
				session.entry = session.swap;
			}
			else
				session.swap = 1;
			ft_putstrs_fd(session.env, session.swap);
		}
		else
			ft_putstr("EMPTY ENVIRONMENT\n");
		return (EXEC_SUCCESS);
	}
	return (ft_case_e_next());
}

t_execstatus	ft_case_p(void)
{
	if (ft_strmlcmp(session.in[0], "pwd"))
	{
		if (session.has_pipe)
		{
			session.swap = ft_mk_tmp(TRUE);
			session.entry = session.swap;
		}
		else
			session.swap = 1;
		ft_putendl_fd(session.path.cdir, session.swap);
		return (EXEC_SUCCESS);
	}
	return (ABSCENT);
}

t_execstatus	ft_case_s(void)
{
	if (ft_strmlcmp(session.in[0], "setenv"))
	{
		if (session.ac == 3)
		{
			ft_setenv(&session.env, session.in[1], session.in[2]);
			return (EXEC_SUCCESS);
		}
		else if (session.ac > 3)
			ft_putstr("TOO MANY ARGUMENTS\n");
		else
			ft_putstr("NOT ENOUGHT ARGUMENTS\n");
		return (EXEC_FAILURE);
	}
	return (ABSCENT);
}

t_execstatus	ft_case_u(void)
{
	if (ft_strmlcmp(session.in[0], "unsetenv"))
	{
		if (session.ac == 2)
		{
			if (ft_unsetenv(&session.env, session.in[1]))
				return (EXEC_SUCCESS);
			return (EXEC_FAILURE);
		}
		else if (session.ac > 2)
			ft_putstr("TOO MANY ARGUMENTS\n");
		else
			ft_putstr("NOT ENOUGHT ARGUMENTS\n");
		return (EXEC_FAILURE);
	}
	return (ABSCENT);
}
