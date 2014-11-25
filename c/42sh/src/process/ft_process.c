/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 16:43:54 by vplotton          #+#    #+#             */
/*   Updated: 2014/03/27 23:01:02 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"lexer.h"
#include	<errno.h>
#include	<meh.h>

t_execstatus	(*g_magiclauncher[26])(void) =
{
	&ft_case_blank,
	&ft_case_blank,
	&ft_case_c,
	&ft_case_blank,
	&ft_case_e,
	&ft_case_blank,
	&ft_case_blank,
	&ft_case_blank,
	&ft_case_blank,
	&ft_case_blank,
	&ft_case_blank,
	&ft_case_blank,
	&ft_case_blank,
	&ft_case_blank,
	&ft_case_blank,
	&ft_case_p,
	&ft_case_q,
	&ft_case_blank,
	&ft_case_s,
	&ft_case_blank,
	&ft_case_u,
	&ft_case_blank,
	&ft_case_blank,
	&ft_case_blank,
	&ft_case_blank,
	&ft_case_blank
};

t_bool	ft_process_pipe(char **cmd, char *path, int *entry, int has_pipe)
{
	int			pfd[2];
	int			child_pid;

	if ((has_pipe == TRUE && pipe(pfd) == -1) || (child_pid = fork()) == -1)
		return (FALSE);
	if (child_pid == 0)
	{
		if (*entry)
			dup2(*entry, 0);
		if (has_pipe == TRUE)
		{
			dup2(pfd[1], 1);
			close(pfd[0]);
		}
		if (execve(path, cmd, session.env) == -1 && session.return_code == 10)
			return (FALSE);
	}
	if (has_pipe == TRUE)
	{
		if (*entry)
			close(*entry);
		close(pfd[1]);
		*entry = pfd[0];
	}
	return (TRUE);
}

t_bool	ft_process_extern(char **cmd, int *entry, t_bool has_pipe)
{
	t_bool		is_valid;
	int			wait;
	char		*path;
	char		**dirs;

	wait = 0;
	path = NULL;
	dirs = NULL;
	is_valid = ft_create_cmd_info(&dirs, &path, session.env, cmd[0]);
	if (path && ft_process_pipe(cmd, path, entry, has_pipe) == FALSE)
		is_valid = FALSE;
	ft_free_cmd_info(&dirs, &path);
	ft_del_tmp(".tmp");
	if (has_pipe && is_valid == TRUE)
		ft_pipe_to_tmp(entry, has_pipe);
	else
	{
		while (wait != -1)
			wait = waitpid(-1, &session.return_code, 0);
		if (session.return_code != 0)
			return (FALSE);
	}
	return (is_valid);
}

t_bool	ft_process_builtin(char **cmd, int *entry, t_bool has_pipe)
{
	if (ft_islower(**cmd)
			&& (session.swap = g_magiclauncher[**cmd - 97]()) != ABSCENT)
	{
		if (has_pipe)
			*entry = session.entry;
		return (TRUE);
	}
	else if (ft_extern_call(entry))
	{
		if (has_pipe)
			*entry = session.entry;
		return (TRUE);
	}
	return (FALSE);
}

t_bool	ft_process_cmd(t_ast *ast, int *entry, t_bool has_pipe)
{
	t_bool		is_valid;
	char		**cmd;

	if (*entry)
		*entry = ft_mk_tmp(FALSE);
	ast = ast->first;
	cmd = ft_seek_cmd(ast);
	if (ft_has_redir(ast, 0))
		has_pipe = TRUE;
	session.has_pipe = has_pipe;
	if (ft_has_redir(ast, 1) == TRUE)
		ft_construct_entry_file(entry, ast->first);
	session.in = cmd;
	session.ac = ft_strslen(cmd);
	if (ft_process_builtin(cmd, entry, has_pipe) == TRUE)
		is_valid = session.swap;
	else
		is_valid = ft_process_extern(cmd, entry, has_pipe);
	if (ft_has_redir(ast, 0))
		ft_construct_output_file(ast);
	if (!has_pipe)
		ft_del_tmp(".tmp");
	return (is_valid);
}

t_bool	ft_process_ast(t_ast *ast)
{
	t_bool	(*ft[9])(t_ast *ast);

	if (ast)
	{
		ft[0] = &ft_process_com;
		ft[1] = &ft_process_and;
		ft[2] = &ft_process_or;
		ft[3] = &ft_process_pip;
		ft[4] = &ft_process_pip;
		ft[5] = &ft_process_pip;
		ft[6] = &ft_process_pip;
		ft[7] = &ft_process_pip;
		ft[8] = &ft_process_pip;
		if (ft[ast->type](ast) == FALSE)
			return (FALSE);
		return (TRUE);
	}
	return (TRUE);
}
