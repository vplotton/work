/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_and_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-goug <ele-goug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 21:39:28 by ele-goug          #+#    #+#             */
/*   Updated: 2014/03/27 21:41:38 by ele-goug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <meh.h>

char	*ft_setentry(char *ref, char *value)
{
	char	*entry;
	int		mark;

	entry = malloc(ft_strlen(ref) + ft_strlen(value) + 2);
	mark = 0;
	ft_strxcpy(entry, ref, &mark);
	entry[mark++] = '=';
	ft_strxcpy(entry, value, &mark);
	entry[mark] = '\0';
	return (entry);
}

char	**ft_addentry(char **env, char *ref, char *value, size_t size)
{
	char	**nenv;
	char	**out;

	if (size == 0)
	{
		out = malloc(2 * sizeof(char *));
		*out = ft_setentry(ref, value);
		out[1] = NULL;
		return (out);
	}
	nenv = malloc((size + 2) * sizeof(char *));
	out = nenv;
	while (*env)
		*nenv++ = *env++;
	*nenv++ = ft_setentry(ref, value);
	*nenv = NULL;
	return (out);
}

t_bool	ft_setenv(char ***env, char *ref, char *value)
{
	char	**cenv;

	if (!(*env))
	{
		*env = ft_addentry(*env, ref, value, 0);
		return (TRUE);
	}
	cenv = *env;
	while (*cenv)
	{
		if (ft_strnvcmp(*cenv, ref))
		{
			free(*cenv);
			*cenv = ft_setentry(ref, value);
			return (TRUE);
		}
		cenv++;
	}
	cenv = ft_addentry(*env, ref, value, ft_strslen(*env));
	free(*env);
	*env = cenv;
	return (TRUE);
}

char	**ft_rementry(char **env, char *rem, size_t size)
{
	char	**nenv;
	char	**out;

	if (size == 1)
	{
		free(*env);
		return (NULL);
	}
	nenv = malloc(size * sizeof(char *));
	out = nenv;
	while (*env)
	{
		if (*env != rem)
			*nenv++ = *env++;
		else
			free(*env++);
	}
	*nenv = NULL;
	return (out);
}

t_bool	ft_unsetenv(char ***env, char *ref)
{
	char	**cenv;

	if (!(*env))
		return (FALSE);
	cenv = *env;
	while (*cenv)
	{
		if (ft_strnvcmp(*cenv, ref))
		{
			cenv = ft_rementry(*env, *cenv, ft_strslen(*env));
			free(*env);
			*env = cenv;
			return (TRUE);
		}
		cenv++;
	}
	return (FALSE);
}
