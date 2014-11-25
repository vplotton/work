/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 16:42:34 by vplotton          #+#    #+#             */
/*   Updated: 2014/03/27 21:54:53 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <libft.h>
# include <fcntl.h>
# include <session.h>

# define LINE_LEN	1024

/*
**	!!    DEFINE    !!
*/
# define CONTINUE	2
# define STOP		-1

# define T_COM		0
# define T_AND		1
# define T_OR		2
# define T_PIP		3
# define T_RFR		4
# define T_RFL		5
# define T_RFRR		6
# define T_RFLL		7
# define T_CMD		8
# define T_OPT		9
# define T_FIL		10
# define COMMA		';'
# define AND		'&'
# define PIPES		'|'
# define RFT_R		'>'
# define RFT_L		'<'
# define RFT_RR		">>"
# define RFT_LL		"<<"
# define DASH		'-'
# define QUOTE		'"'
# define END		"\\n"
# define ALL_C		";& |><"
# define ERR_PARSE	"parse error near `"
/*
**	!!	TYPEDEF	!!
*/
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

/*
**	!!	FUNCTIONS	!!
**		Get functions
*/
t_bool				ft_comma(t_llist **list, char *arg, int arg_type, int *i);
t_bool				ft_and(t_llist **list, char *arg, int arg_type, int *i);
t_bool				ft_pipes(t_llist **list, char *arg, int arg_type, int *i);
t_bool				ft_rft_r(t_llist **list, char *arg, int arg_type, int *i);
t_bool				ft_rft_l(t_llist **list, char *arg, int arg_type, int *i);

/*
**					List functions
*/
void				ft_add_list(t_llist **list, char *arg, int arg_type);
void				ft_delete_list(t_llist **list);
char				**ft_convert(t_llist *list);

/*
**					Ast functions
*/
void				ft_add_ast(t_ast **ast, int type);
void				ft_add_file(t_ast **ast, t_llist *list);
void				ft_add_cmd(t_ast **ast, t_llist **list, t_bool *cmd);
void				ft_delete_ast(t_ast **ast, int side);

/*
**					Parse functions
*/
t_bool				ft_check_next(t_llist *l, t_llist *t, t_ast **a, int arg);
t_bool				ft_check_com(t_llist *list, t_llist *left, t_ast **ast);
t_bool				ft_check_and(t_llist *list, t_llist *left, t_ast **ast);
t_bool				ft_check_or(t_llist *list, t_llist *left, t_ast **ast);
t_bool				ft_check_pip(t_llist *list, t_llist *left, t_ast **ast);
t_bool				ft_check_cmd(t_llist *list, t_llist *left, t_ast **ast);
t_bool				ft_get_next(t_llist *list, t_ast **ast, int start);

/*
**					Print functions
*/
t_bool				ft_print_prserr(t_llist	*list);

/*
**					Process functions
*/
t_bool				ft_process_com(t_ast *ast);
t_bool				ft_process_and(t_ast *ast);
t_bool				ft_process_or(t_ast *ast);
t_bool				ft_process_pip(t_ast *ast);
t_bool				ft_process_ast(t_ast *ast);
t_bool				ft_process_cmd(t_ast *ast, int *entry, t_bool has_pipe);

/*
**					Command handling functions
*/
void				ft_free_cmd_info(char ***dirs, char **path);
t_bool				ft_create_cmd_info(char ***d, char **p, char **e, char *c);
char				*ft_check_path(char **dirs, char *cmd);
char				**ft_parse_path(char **env);
char				**ft_seek_cmd(t_ast *ast);

/*
**					File handling functions
*/
t_bool				ft_construct_entry_file(int *entry, t_ast *ast);
t_bool				ft_construct_output_file(t_ast *ast);
t_bool				ft_file_to_tmp(char *file);
t_bool				ft_tmp_to_file(char *file);
t_bool				ft_tmp_dr_to_file(char *file);
t_bool				ft_has_redir(t_ast *ast, t_bool mode);

/*
**					Tmp handling functions
*/
t_bool				ft_read_tmp(void);
t_bool				ft_pipe_to_tmp(int *pipe, t_bool has_pipe);
t_bool				ft_del_tmp(char *tmp_name);
int					ft_mk_tmp(t_bool append);

#endif
