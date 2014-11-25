/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itk_clipboard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarquet <qmarquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 17:51:29 by qmarquet          #+#    #+#             */
/*   Updated: 2014/03/24 21:05:41 by qmarquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "itk_h.h"

static char		*itk_x(t_infos *infos, char *clip)
{
	t_elem_dll		*current;
	t_elem_dll		*next;
	t_letter		*letter;
	int				i;

	clip = itk_c(infos, clip);
	current = dll_sg_meta(NL)->start;
	i = 1;
	while (current)
	{
		next = current->next;
		letter = (t_letter *)(current->data);
		if (letter->is_c || infos->pos_curs == i)
		{
			itk_del_all(infos);
			dll_remv_link(current, NL);
			infos->pos_curs = dll_sg_meta(NL)->len + 1;
		}
		current = next;
		i++;
	}
	itk_refresh(infos);
	return (clip);
}

char			*itk_c(t_infos *infos, char *clip)
{
	int				i;
	int				j;
	t_elem_dll		*current;
	t_letter		*letter;

	if (clip)
		free(clip);
	clip = (char *)malloc(sizeof(char) * (1 + dll_sg_meta(NL)->len));
	current = dll_sg_meta(NL)->start;
	i = 0;
	j = 1;
	while (current)
	{
		letter = (t_letter *)(current->data);
		if (letter->is_c || infos->pos_curs == j)
		{
			clip[i] = letter->l;
			i++;
		}
		current = current->next;
		j++;
	}
	clip[i] = '\0';
	return (clip);
}

static void		itk_v(t_infos *infos, char *clip)
{
	int				i;

	if (clip == NULL)
		return ;
	i = 0;
	while (clip[i])
	{
		itk_new_char(clip[i], infos, 0);
		i++;
	}
	itk_refresh(infos);
}

void			itk_clipboard(char s_read[8], t_infos *infos)
{
	static char		*clip = NULL;

	if (FT_X)
		clip = itk_x(infos, clip);
	else if (FT_C)
		clip = itk_c(infos, clip);
	else if (FT_V)
		itk_v(infos, clip);
	infos->clip = (clip) ? clip : NULL;
}
