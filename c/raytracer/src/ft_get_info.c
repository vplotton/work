/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 16:07:15 by vplotton          #+#    #+#             */
/*   Updated: 2014/03/11 20:51:21 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"raytracer.h"

void	ft_add_cam(t_cams **cam, t_cam *data_cam)
{
	t_cams	*new;

	new = (t_cams*)ft_memalloc(sizeof(t_cams));
	new->first = (*cam ? (*cam)->first : new);
	new->next = NULL;
	new->data = (t_cam*)ft_memalloc(sizeof(t_cam));
	ft_memcpy(new->data, data_cam, sizeof(t_cam));
	if (*cam)
		(*cam)->next = new;
	*cam = new;
}

void	ft_add_obj(t_objs **obj, t_obj *data_obj)
{
	t_objs	*new;

	new = (t_objs*)ft_memalloc(sizeof(t_objs));
	new->first = (*obj ? (*obj)->first : new);
	new->next = NULL;
	new->data = (t_obj*)ft_memalloc(sizeof(t_obj));
	ft_memcpy(new->data, data_obj, sizeof(t_obj));
	if (*obj)
		(*obj)->next = new;
	*obj = new;
}

void	ft_add_lgt(t_lgts **lgt, t_lgt *data_lgt)
{
	t_lgts	*new;

	new = (t_lgts*)ft_memalloc(sizeof(t_lgts));
	new->first = (*lgt ? (*lgt)->first : new);
	new->next = NULL;
	new->data = (t_lgt*)ft_memalloc(sizeof(t_lgt));
	ft_memcpy(new->data, data_lgt, sizeof(t_lgt));
	if (*lgt)
		(*lgt)->next = new;
	*lgt = new;
}

void	ft_get_info(t_info *info, t_data **data)
{
	*data = (*data)->first;
	info->cam = NULL;
	info->obj = NULL;
	info->lgt = NULL;
	while (42)
	{
		if ((*data)->type == SCN)
		{
			info->winsz = (*data)->scn->winsz;
			info->name = ft_strsub((*data)->name, 0, ft_strlen((*data)->name));
		}
		if ((*data)->type == CAM)
			ft_add_cam(&info->cam, (*data)->cam);
		if ((*data)->type == OBJ)
			ft_add_obj(&info->obj, (*data)->obj);
		if ((*data)->type == LGT)
			ft_add_lgt(&info->lgt, (*data)->lgt);
		if (!(*data)->next)
			break ;
		*data = (*data)->next;
	}
	info->pitch.x = 0.5;
	info->pitch.y = info->pitch.x;// * (info->winsz.x / info->winsz.y);
	ft_delete_data(data);
}
