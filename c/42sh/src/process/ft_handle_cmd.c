/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 15:29:14 by vplotton          #+#    #+#             */
/*   Updated: 2014/03/27 16:58:33 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>
#include	"lexer.h"

char	**ft_parse_path(char **env)
{
	int		i;
	char	**output;

	output = NULL;
	i = -1;
	while (env[++i])
	{
		if (ft_strnequ("PATH=", env[i], 5))
			output = ft_strsplit(env[i], ':');
	}
	return (output);
}

char	*ft_check_path(char **dirs, char *cmd)
{
	int		i;
	char	*output;
	char	*tmp;

	i = -1;
	output = NULL;
	while (++i < 80 && dirs[i])
	{
		tmp = output;
		output = ft_strjoin(dirs[i], "/");
		if (tmp)
			ft_strdel(&tmp);
		tmp = output;
		output = ft_strjoin(output, cmd);
		if (tmp)
			ft_strdel(&tmp);
		if (access(output, X_OK) == 0)
			return (output);
	}
	if (output)
		ft_strdel(&output);
	ft_putstr_fd("42sh: ", 2);
	ft_putstr_fd("command not found: ", 2);
	ft_putendl_fd(cmd, 2);
	return (NULL);
}

char	**ft_seek_cmd(t_ast *ast)
{
	char	**cmd;

	while (ast && ast->type != T_CMD)
		ast = ast->next;
	if (!ast)
	{
		cmd = (char**)ft_memalloc(sizeof(char*) * 2);
		cmd[0] = ft_strsub("cat", 0, 3);
	}
	else
		cmd = ast->cmd;
	return (cmd);
}

t_bool	ft_create_cmd_info(char ***dirs, char **path, char **env, char *cmd)
{
	if (env == NULL || (env && env[0] == NULL))
	{
		ft_putendl_fd("42sh: please set environment", 2);
		return (FALSE);
	}
	if ((*dirs = ft_parse_path(env)) == NULL)
	{
		ft_putendl_fd("42sh: please set PATH in environment", 2);
		return (FALSE);
	}
	if (dirs && (*path = ft_check_path(*dirs, cmd)) == NULL)
		return (FALSE);
	return (TRUE);
}

void	ft_free_cmd_info(char ***dirs, char **path)
{
	int		i;

	i = -1;
	if (*path)
		ft_strdel(path);
	if (*dirs)
	{
		while ((*dirs)[++i])
			ft_strdel(&((*dirs)[i]));
		free(*dirs);
	}
}
