/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 18:29:56 by vplotton          #+#    #+#             */
/*   Updated: 2014/03/27 23:01:07 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<session.h>
#include	"main.h"
#include	<meh.h>
#include	<sys/ioctl.h>

struct s_session	session;

static void			ft_hand_ign(int sig)
{
	char			c;

	if (sig == SIGTRAP)
		session.return_code = 10;
	c = -1;
	if (sig == SIGINT)
		ioctl(0, TIOCSTI, &c);
}

static void			ft_hand_exit(int sig)
{
	char			*s;

	(void)sig;
	write(2, "\nTermination signal\nBye-bye!\n", 29);
	s = ft_itoa(sig);
	ft_putstr_fd(s, 2);
	free(s);
	write(2, "\n", 1);
	itk_exit(itk_ini());
}

static void			ft_signal(void)
{
	int				i;

	i = 0;
	while (i < NSIG)
	{
		if (i == SIGINT || i == SIGTSTP || i == SIGCONT || i == 20 || i == 23)
			signal(i, ft_hand_ign);
		else if (i == SIGTRAP)
			signal(i, ft_hand_ign);
		else if (i != SIGWINCH)
			signal(i, ft_hand_exit);
		i++;
	}
}

int					main(void)
{
	t_infos			*infos;
	t_llist			*list;
	t_ast			*ast;

	ft_signal();
	ft_session_init();
	list = NULL;
	ast = NULL;
	infos = itk_ini();
	while (session.exit == FALSE && itk_read(infos))
	{
		if ((list = ft_lexer(infos->string)) == NULL)
			continue ;
		if (ft_get_ast(&list, &ast) == FALSE)
			continue ;
		ft_process_ast(ast);
		ft_delete_ast(&ast, 1);
		if (infos->string)
			ft_strdel(&infos->string);
	}
	itk_exit(infos);
	ft_session_clear();
	return (session.return_code);
}
