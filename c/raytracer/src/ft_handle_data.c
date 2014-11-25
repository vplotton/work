/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 14:58:12 by vplotton          #+#    #+#             */
/*   Updated: 2014/03/19 13:59:16 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"raytracer.h"

void	ft_add_data(t_data **data, int type)
{
	t_data	*new;

	new = (t_data*)ft_memalloc(sizeof(t_data));
	new->type = type;
	new->scn = (type == SCN ? (t_scn*)ft_memalloc(sizeof(t_scn)) : NULL);
	new->cam = (type == CAM ? (t_cam*)ft_memalloc(sizeof(t_cam)) : NULL);
	new->obj = (type == OBJ ? (t_obj*)ft_memalloc(sizeof(t_obj)) : NULL);
	new->lgt = (type == LGT ? (t_lgt*)ft_memalloc(sizeof(t_lgt)) : NULL);
	new->first = (*data ? (*data)->first : new);
	new->next = NULL;
	new->name = NULL;
	if (*data)
		(*data)->next = new;
	*data = new;
}

void	ft_get_data_2(t_data **data, char *compound, char *input, t_posd posd)
{
	if (compound == T_SCN)
	{
		if (ft_strcmp(input, "winsz") == 0)
			(*data)->scn->winsz = posd;
	}
	if (compound == T_OBJ)
	{
		if (ft_strcmp(input, "type") == 0)
			(*data)->obj->type = posd.x;
		if (ft_strcmp(input, "radius") == 0)
			(*data)->obj->radius = posd.x;
		if (ft_strcmp(input, "height") == 0)
			(*data)->obj->height = posd.x;
		if (ft_strcmp(input, "color") == 0)
			(*data)->obj->color = posd;
		if (ft_strcmp(input, "coeff") == 0)
			(*data)->obj->coeff = posd;
		if (ft_strcmp(input, "coord") == 0)
			(*data)->obj->coord = posd;
		if (ft_strcmp(input, "d_vec") == 0)
			(*data)->obj->d_vec = posd;
	}
}

void	ft_get_data(t_data **data, char *compound, char *input, t_posd posd)
{
	if (ft_strcmp(input, "name") == 0)
	{
		input = input + 6;
		(*data)->name = ft_strsub(input, 0, ft_strlen(input));
	}
	if (compound == T_CAM)
	{
		if (ft_strcmp(input, "coord") == 0)
			(*data)->cam->coord = posd;
		if (ft_strcmp(input, "d_vec") == 0)
			(*data)->cam->d_vec = posd;
	}
	if (compound == T_LGT)
	{
		if (ft_strcmp(input, "radius") == 0)
			(*data)->lgt->radius = posd.x;
		if (ft_strcmp(input, "color") == 0)
			(*data)->lgt->color = posd;
		if (ft_strcmp(input, "coord") == 0)
			(*data)->lgt->coord = posd;
	}
	else
		ft_get_data_2(data, compound, input, posd);
}

void	ft_delete_data(t_data **data)
{
	t_data	*tmp;
	if (data && *data)
	{
		*data = (*data)->first;
		while (*data)
		{
			tmp = (*data)->next;
			if ((*data)->name)
				ft_strdel(&((*data)->name));
			if ((*data)->type == SCN)
				free((*data)->scn);
			if ((*data)->type == CAM)
				free((*data)->cam);
			if ((*data)->type == OBJ)
				free((*data)->obj);
			if ((*data)->type == LGT)
				free((*data)->lgt);
			free(*data);
			*data = tmp;
		}
	}
}

t_bool	ft_check_order(t_data *data)
{
	t_bool	order[4];
	t_bool	is_valid;

	order[0] = FALSE;
	order[1] = FALSE;
	order[2] = FALSE;
	order[3] = FALSE;
	is_valid = TRUE;
	data = data->first;
	while (42)
	{
		order[data->type] = TRUE;
		if (order[data->type - 1] == FALSE || order[data->type + 1] == TRUE)
		{
			is_valid = FALSE;
			break ;
		}
		if (!data->next)
			break ;
		data = data->next;
	}
	return (is_valid);
}
