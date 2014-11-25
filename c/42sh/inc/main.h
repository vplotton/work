/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 21:02:06 by vplotton          #+#    #+#             */
/*   Updated: 2014/03/27 21:39:21 by ele-goug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <libft.h>
# include <session.h>

typedef struct		s_infos
{
	int				pos_curs;
	int				nl;
	int				ll;
	int				prompt;
	char			circle;
	char			*clip;
	char			*string;
}					t_infos;

typedef struct		s_llist
{
	int				arg_type;
	char			*arg;
	struct s_llist	*next;
	struct s_llist	*prev;
	struct s_llist	*first;
}					t_llist;

typedef struct		s_ast
{
	int				type;
	char			*file;
	char			**cmd;
	struct s_ast	*down;
	struct s_ast	*first;
	struct s_ast	*next;
}					t_ast;

void				itk_exit(t_infos *infos);
int					itk_read(t_infos *infos);
void				itk_delete(t_infos *infos);
void				ft_delete_ast(t_ast **ast, int side);
t_bool				ft_get_ast(t_llist **list, t_ast **ast);
t_bool				ft_process_ast(t_ast *ast);
t_bool				ft_process_pipe(char **c, char *p, int *e, int has_pipe);
t_llist				*ft_lexer(char *s);
t_infos				*itk_ini(void);

#endif
