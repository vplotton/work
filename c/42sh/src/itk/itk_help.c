/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itk_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarquet <qmarquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 12:19:15 by qmarquet          #+#    #+#             */
/*   Updated: 2014/03/24 20:57:11 by qmarquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "itk_h.h"
#include <fcntl.h>
#include <time.h>

void				itk_welcome(void)
{
	itk_putstr("\033[30;43m");
	write(1, "\n", 1);
	itk_putstr("                  42sh                      \n");
	itk_putstr("  Press (fn) F1 to display the help window  \n");
	itk_putstr("  Press (fn) F2 to display credits          ");
	itk_putstr("\033[0m");
	write(1, "\n", 1);
}

void				itk_help(t_infos *infos)
{
	itk_del_all(infos);
	itk_putstr("\033[30;47m");
	write(1, "\n", 1);
	itk_putstr(" Move left                        <-   \n");
	itk_putstr(" Move right                       ->   \n");
	itk_putstr(" Move up                  Shift + UP   \n");
	itk_putstr(" Move Down                Shift + Down \n");
	itk_putstr(" Beginning of the line            Home \n");
	itk_putstr(" End of the line                  End  \n");
	itk_putstr(" Cut                        Alt + X    \n");
	itk_putstr(" Copy                       Alt + C    \n");
	itk_putstr(" Paste                      Alt + V    \n");
	itk_putstr(" Select                     Alt + <-   \n");
	itk_putstr("                            Alt + ->   \n");
	itk_putstr("                            Alt + Home \n");
	itk_putstr("                            Alt + End  \n");
	itk_putstr(" Historic before                  UP   \n");
	itk_putstr(" Historic after                   DOWN \n");
	itk_putstr(" Clear screen              Ctrl + L    \n");
	itk_putstr(" Exit                      Ctrl + D    \n");
	itk_putstr(" Credits                          F2   \n");
	itk_putstr("\033[0m");
	write(1, "\n", 1);
	itk_prompt(infos);
}

void				itk_open_read(char *pic)
{
	int				ret;
	char			c[8];

	*(long *)c = 0;
	if ((ret = open(pic, O_RDONLY)) == -1)
		return ;
	while (read(ret, c, 1))
		write(1, &c, 1);
	read(0, c, 8);
}

void				itk_print_name(char *name, char *path)
{
	TERM("cl");
	itk_putstr("                                 ");
	itk_putstr("\033[30;47m");
	itk_putstr(name);
	itk_putstr("\033[0m");
	itk_open_read(path);
}

void				itk_credits(t_infos *infos)
{
	itk_del_all(infos);
	TERM("ti");
	itk_print_name("Vianney Plotton\n\n", "src/itk/pics/v");
	itk_print_name("Cyril Charbonnier\n\n", "src/itk/pics/c");
	itk_print_name("Ewen Le-Gouguec\n\n", "src/itk/pics/e");
	itk_print_name("Karim Duchesne\n\n", "src/itk/pics/k");
	itk_print_name("Quentin Marquet\n\n", "src/itk/pics/q");
	TERM("te");
	itk_prompt(infos);
}
