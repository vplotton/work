/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itk_start_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarquet <qmarquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/15 16:12:21 by qmarquet          #+#    #+#             */
/*   Updated: 2014/03/27 23:03:29 by qmarquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "itk_h.h"
#include <session.h>
#include <meh.h>

void					itk_prompt(t_infos *infos)
{
	char				*env;

	if (!isatty(0))
	{
		write(1, "\033[36m", 5);
		write(1, "file-42sh>", 10);
		infos->prompt = 10;
	}
	else
	{
		env = getenv("USER");
		write(1, "\033[33m", 5);
		if (env != NULL)
			infos->prompt = 6 + itk_strlen(itk_putstr(getenv("USER")));
		else
			infos->prompt = 6;
		write(1, "-42sh>", 6);
	}
	write(1, "\033[0m", 5);
}

void					itk_first(void)
{
	char				*env;
	char				buffer[2048];

	env = getenv("TERM");
	if (env == NULL)
		tgetent(buffer, "xterm-256color");
	else
		tgetent(buffer, env);
}

void					itk_start(void)
{
	struct termios		term;

	tcgetattr(0, &term);
	term.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(0, TCSANOW, &term);
}

void					itk_end(void)
{
	struct termios		term;

	TERM("ve");
	tcgetattr(0, &term);
	term.c_lflag |= (ECHO | ICANON);
	tcsetattr(0, TCSANOW, &term);
}

void					itk_exit(t_infos *infos)
{
	int					i;

	itk_end();
	i = -1;
	while (++i < NUM_OF_DLL)
		dll_remv_list(i);
	if (infos->clip != NULL)
		free(infos->clip);
	if (infos != NULL)
		free(infos);
	ft_session_clear();
	write(1, "\n", 1);
	exit(session.return_code);
}
