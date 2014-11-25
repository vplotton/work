/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lists.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarquet <qmarquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 13:20:21 by qmarquet          #+#    #+#             */
/*   Updated: 2014/03/26 18:40:17 by qmarquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_LISTS_H
# define MY_LISTS_H
# include <stddef.h>
# include <stdlib.h>

typedef struct			s_elem_dll
{
	void				*data;
	struct s_elem_dll	*prev;
	struct s_elem_dll	*next;
}						t_elem_dll;

typedef struct			s_meta_dll
{
	t_elem_dll			*start;
	t_elem_dll			*end;
	int					len;
	char				error;
}						t_meta_dll;

# define NUM_OF_DLL		100
# define ERR_MALLOC		-1
# define ERR_NBR_LIST	-2
# define ERR_NOT_FOUND	-3
# define ERR_NULL_PTR	-4
# define VAR(var)		sizeof(var), &var

int						dll_new_at_first(int dt_sz, void *data, int nbr_list);
int						dll_new_at_last(int dt_sz, void *data, int nbr_list);
int						dll_new_before(int d, void *t, int index, int nbr_list);
int						dll_remv_pos(int index, int nbr_list);
int						dll_remv_link(t_elem_dll *link, int nbr_list);
int						dll_remv_first(int nbr_list);
int						dll_remv_end(int nbr_list);
int						dll_remv_list(int nbr_list);
t_elem_dll				*dll_find_index(int index, int nbr_list);
t_elem_dll				*dll_find_data(int dt_sz, void *to_find, int nbr_list);
t_meta_dll				*dll_sg_meta(int nbr_list);
int						dll_error(int nbr_list, int error);
t_elem_dll				*dll_error_p(int nbr_list, int error);
int						dll_new_in_empty(int d, void *data, int nbr_list);
t_elem_dll				*dll_new_node(int data_size, void *data);
void					*my_memcpy(void *copy_data, const void *data, int d);
int						my_memcmp(const void *s1, const void *s2, size_t n);
void					dll_free_node(t_elem_dll *node_to_rm, t_meta_dll *info);

#endif
