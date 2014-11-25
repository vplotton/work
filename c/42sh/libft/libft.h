/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 15:30:45 by vplotton          #+#    #+#             */
/*   Updated: 2014/03/18 14:40:45 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIBFT_H__
# define __LIBFT_H__

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define ABS(X) (X < 0 ? -X : X)
# define BUFF_SIZE 32

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
**	String analyses
*/
size_t	ft_strlen(const char *s);
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *s1, const char *s2);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);

/*
**	String allocation
*/
char	*ft_strnew(size_t size);
char	*ft_strdup(const char *s);
char	*ft_strsub(char const *s, unsigned int start, size_t len);

/*
**	String deletion
*/
void	ft_strdel(char **as);
void	ft_strclr(char *s);

/*
**	String duplication
*/
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strncat(char *s1, const char *s2, size_t n);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strcpy(char *s1, const char *s2);
char	*ft_strncpy(char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);

/*
**	String manipulation
*/
char	*ft_strtrim(char const *s);
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	**ft_strsplit(char const *s, char c);


/*
**	Character manipulation
*/
int		ft_tolower(int c);
int		ft_toupper(int c);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));


/*
**	Memory analysis
*/
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);

/*
**	Memory manipulation
*/
void	ft_memdel(void **ap);
void	ft_bzero(void *s, size_t n);
void	*ft_memalloc(size_t size);
void	*ft_memmove(void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *s1, const void *s2, size_t n);
void	*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void	*ft_memset(void *b, int c, size_t len);


/*
**	List manipulation
*/
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list	*ft_lstnew(void const *content, size_t content_size);


/*
**	Print
*/
void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl(char const *s);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr(char const *s);
void	ft_putstr_fd(char const *s, int fd);


/*
**	Number from/to string
*/
int		ft_atoi(const char *str);
char	*ft_itoa(int n);


/*
**	Is
*/
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

#endif
