/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itk_h.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarquet <qmarquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 12:30:05 by qmarquet          #+#    #+#             */
/*   Updated: 2014/03/27 22:44:10 by qmarquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITK_H_H
# define ITK_H_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <termios.h>
# include <termcap.h>
# include <sys/ioctl.h>
# include <my_lists.h>
# include <libft.h>

typedef struct			s_letter
{
	int					pos;
	char				l;
	char				is_c;
}						t_letter;

typedef struct			s_infos
{
	int					pos_curs;
	int					nl;
	int					ll;
	int					prompt;
	char				circle;
	char				*clip;
	char				*string;
	struct termios		term;
}						t_infos;

enum					e_enum
{
	E_CTRL = 2,
	E_ASCII,
	E_TAB,
	E_RETURN,
	E_ESCAPE,
	E_SPACE,
	E_DELETE,
	E_BACKSPACE,
	E_CTRL_C,
	E_CTRL_D,
	E_HOME,
	E_END,
	E_UP,
	E_DOWN,
	E_LEFT,
	E_RIGHT,
	E_SHIFT_LEFT,
	E_SHIFT_RIGHT,
	E_A_HOME,
	E_A_END,
	E_X,
	E_C,
	E_V,
	E_F1,
	E_F2,
	E_F3,
	E_CTRL_L,
	E_CR_UP,
	E_CR_DN
};

# define FT_READ		(*(long *)s_read)

# define IS_CTRL		((FT_READ >= 1 && FT_READ <= 31) ? E_CTRL : 0)
# define IS_ASCII		((FT_READ >= 32 && FT_READ <= 126) ? E_ASCII : 0)
# define FT_TAB			((FT_READ == 9) ? E_TAB : 0)
# define FT_RETURN		((FT_READ == 10) ? E_RETURN : 0)
# define FT_ESCAPE		((FT_READ == 27) ? E_ESCAPE : 0)
# define FT_SPACE		((FT_READ == 32) ? E_SPACE : 0)
# define FT_DELETE		((FT_READ == 127) ? E_DELETE : 0)
# define FT_BACKSPACE	((FT_READ == 2117294875) ? E_BACKSPACE : 0)
# define FT_CTRL_C		((FT_READ == 3) ? E_CTRL_C : 0)
# define FT_CTRL_D		((FT_READ == 4) ? E_CTRL_D : 0)
# define FT_X			((FT_READ == 8948194) ? E_X : 0)
# define FT_C			((FT_READ == 42947) ? E_C : 0)
# define FT_V			((FT_READ == 10127586) ? E_V : 0)

# define FT_HOME		((FT_READ == 4741915) ? E_HOME : 0)
# define FT_END			((FT_READ == 4610843) ? E_END : 0)
# define FT_UP			((FT_READ == 4283163) ? E_UP : 0)
# define FT_DOWN		((FT_READ == 4348699) ? E_DOWN : 0)
# define FT_S_LEFT		((FT_READ == 74982532143899) ? 1 : 0)
# define FT_S_RIGHT		((FT_READ == 73883020516123) ? 1 : 0)
# define FT_LEFT		((FT_READ == 4479771 || FT_S_LEFT) ? E_LEFT : 0)
# define FT_RIGHT		((FT_READ == 4414235 || FT_S_RIGHT) ? E_RIGHT : 0)
# define CR_UP			((FT_READ == 71683997260571) ? E_CR_UP: 0)
# define CR_DN			((FT_READ == 72783508888347) ? E_CR_DN: 0)
# define FT_SHIFT_LEFT	((FT_READ == 1146821403) ? E_SHIFT_LEFT : 0)
# define FT_SHIFT_RIGHT	((FT_READ == 1130044187) ? E_SHIFT_RIGHT : 0)
# define FT_A_HOME		((FT_READ == 79410643426075) ? E_A_HOME : 0)
# define FT_A_END		((FT_READ == 77211620170523) ? E_A_END : 0)
# define FT_F1			((FT_READ == 5263131) ? E_F1 : 0)
# define FT_F2			((FT_READ == 5328667) ? E_F3 : 0)
# define FT_F3			((FT_READ == 5394203) ? E_F2 : 0)
# define FT_CTRL_L		((FT_READ == 12) ? E_CTRL_L : 0)

# define TERM(str)		(tputs(tgetstr(str, NULL), 1, tputs_putchar))
# define NL				infos->nl
# define LL				infos->ll
# define LEN			(dll_sg_meta(infos->nl)->len)

void					itk_first(void);
void					itk_start(void);
void					itk_end(void);
void					itk_exit(t_infos *infos);
void					itk_prompt(t_infos *infos);
int						itk_read(t_infos *infos);
void					itk_del_all(t_infos *infos);
void					itk_print(t_infos *infos);
void					itk_new_char(char c, t_infos *infos, char refresh);
void					itk_delete(t_infos *infos);
void					itk_move_curs(char s_read[8], t_infos *infos, int i);
t_infos					*itk_select(char s_read[8], t_infos *infos);
t_infos					*itk_ini(void);
void					itk_hist(char s_read[8], t_infos *infos);
void					itk_cpy(int nw, int last);
void					itk_refresh(t_infos *infos);
int						itk_ret(t_infos *infos, int i);
char					*itk_string_cmd(t_infos *infos);
int						tputs_putchar(int c);
void					itk_clipboard(char s_read[8], t_infos *infos);
char					*itk_putstr(char *s);
char					*itk_c(t_infos *infos, char *clip);
int						itk_strlen(char *s);
void					itk_welcome(void);
void					itk_help(t_infos *infos);
void					itk_clear(t_infos *infos);
int						itk_ctrl_c(t_infos *infos);
void					itk_credits(t_infos *infos);

#endif
