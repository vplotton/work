/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-goug <ele-goug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/21 17:55:56 by ele-goug          #+#    #+#             */
/*   Updated: 2014/03/27 22:12:24 by ele-goug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEH_H
# define MEH_H

# include <libft.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>
# include <fcntl.h>
# include <session.h>
# include <echo.h>

# define ABSCENT		-1
# define EXEC_FAILURE	0
# define EXEC_SUCCESS	1

# define PATH_SIZE		1024
# define SPRT			'/'

extern struct s_session	session;

typedef char			t_execstatus;

typedef struct			s_strlst
{
	char				*x;
	struct s_strlst		*prev;
	struct s_strlst		*next;
}						t_strlst;

char					*ft_strclone(char *name);
t_bool					ft_strmlcmp(const char *s1, const char *s2);
char					*ft_sethome(void);
char					*ft_path_builder(char *curpath, char *extention);
t_strlst				*ft_lststrst(t_strlst *pp, const char *s, t_bool end);
t_bool					ft_thisistheend(char **s);
t_bool					ft_lstrem(t_strlst **pp);
t_bool					ft_isvalid(const char *s);
t_strlst				*ft_lstbuild(const char *s1, const char *s2);
t_strlst				*ft_lstclean(t_strlst *pp);
char					*ft_strxcpy(char *s1, const char *s2, int *j);
t_bool					ft_super_path(t_strlst *s, struct s_path *p, int l);
t_bool					ft_isdir(char *s);
t_bool					ft_cd(struct s_path *path, char *extend);
t_bool					ft_strnvcmp(const char *s1, const char *s2);
size_t					ft_strslen(char **sa);
char					*ft_setentry(char *ref, char *value);
char					**ft_addentry(char **e, char *r, char *v, size_t size);
t_bool					ft_setenv(char ***env, char *ref, char *value);
char					**ft_rementry(char **env, char *rem, size_t size);
t_bool					ft_unsetenv(char ***env, char *ref);
char					**ft_strsclone(char **sa);
void					ft_putstrs(char **sa);
int						ft_wordlen(char **s, char c);
int						ft_countwords(const char *s, char c);
t_bool					ft_islower(int c);
char					*ft_getenv(char **env, char *ref);
void					ft_session_init(void);
void					ft_session_clear(void);
void					ft_rem(char **in);
void					ft_exit(int code);
char					*ft_get_absolute_path(char *rpath);
t_bool					ft_extern_call(int *entry);
void					ft_putstrs_fd(char **sa, int fd);
t_strlst				*ft_lstset(struct s_path *path, char *extend, int *len);
void					ft_set_first(t_strlst **pp, t_strlst **first);
void					ft_gen_next_element(t_strlst **pp);

t_execstatus			ft_case_blank(void);
t_execstatus			ft_case_c(void);
t_execstatus			ft_case_e(void);
t_execstatus			ft_case_e_next(void);
t_execstatus			ft_case_l(void);
t_execstatus			ft_case_p(void);
t_execstatus			ft_case_q(void);
t_execstatus			ft_case_s(void);
t_execstatus			ft_case_u(void);

#endif
