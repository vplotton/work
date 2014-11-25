/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 18:20:38 by vplotton          #+#    #+#             */
/*   Updated: 2014/03/27 12:25:44 by qmarquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"lexer.h"

int		ft_skip_chr(char *s)
{
	int		i;

	i = 0;
	while (s[i] && ft_strchr(ALL_C, s[i]) == NULL)
		i++;
	return (i);
}

char	*ft_get_line(char *s, int *j)
{
	t_bool	is_quote[2];
	int		i;
	char	*output;

	i = 0;
	output = NULL;
	is_quote[0] = FALSE;
	is_quote[1] = FALSE;
	if (s[i] == '\"')
	{
		is_quote[0] = TRUE;
		i++;
		while (s[i] && s[i] != '\"')
			i++;
		if (s[i])
			is_quote[1] = TRUE;
	}
	else
		i = ft_skip_chr(s);
	if (i != 0)
		output = ft_strsub(s, is_quote[0], i - is_quote[0]);
	*j = *j + i + is_quote[1];
	return (output);
}

t_bool	ft_get_gramchar(t_llist **list, char *arg, int *i)
{
	int		arg_type;
	t_bool	(*ft[6])(t_llist **list, char *arg, int arg_type, int *i);

	arg_type = -1;
	ft[0] = &ft_comma;
	ft[1] = &ft_and;
	ft[2] = ft_comma;
	ft[3] = &ft_pipes;
	ft[4] = &ft_rft_r;
	ft[5] = &ft_rft_l;
	while (ALL_C[++arg_type] && ALL_C[arg_type] != arg[0])
		;
	return ((*ft[arg_type])(list, arg, arg_type, i));
}

t_llist	*ft_lexer(char *s)
{
	int		i;
	char	*arg;
	t_llist	*list;

	i = 0;
	list = NULL;
	while (s[i])
	{
		arg = NULL;
		if (s[i] == ' ' || s[i] == '\t')
			i++;
		else if ((arg = ft_get_line(s + i, &i)) != NULL)
			ft_add_list(&list, arg, T_CMD);
		else if (ft_get_gramchar(&list, s + i, &i) == FALSE)
			return (FALSE);
	}
	if (!list)
		return (FALSE);
	list = list->first;
	return (list);
}
