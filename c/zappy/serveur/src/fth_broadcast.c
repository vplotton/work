/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fth_broadcast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obengelo <obengelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 03:06:21 by obengelo          #+#    #+#             */
/*   Updated: 2014/06/26 15:02:19 by obengelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

t_dpos			get_vec(t_ipos p1, t_ipos p2)
{
	double	norm;
	t_dpos	vec;

	vec.x = p2.x - p1.x;
	vec.y = p2.y - p1.y;
	norm = sqrt(vec.x * vec.x + vec.y * vec.y);
	vec.x = vec.x / norm;
	vec.y = vec.y / norm;
	return (vec);
}

double			dot_prod(t_ipos vec1, t_dpos vec2)
{
	double	scal;

	scal = (double)vec1.x * vec2.x + (double)vec1.y * vec2.y;
	return (scal);
}

int				send_broadcast(t_env *env, int i, int fd)
{
	int		pos;
	double	scal;

	if (i != fd && env->pl[i])
	{
		env->pl[i]->dvec = get_vec(env->pl[i]->pos, env->pl[fd]->pos);
		scal = dot_prod(env->pl[fd]->ivec, env->pl[i]->dvec);
		scal = (scal < 0 ? scal + 2 * PI : scal);
		pos = (int)(scal * 4.0 / PI);
		pos = 1 + pos + (pos % 2) - 8 * (pos / 7);
		return (pos);
	}
	return (-1);
}

static char		*get_msg(char *message, int pos)
{
	char	*msg;
	char	*f_msg;

	f_msg = NULL;
	msg = ft_strtrim(ft_strsub(message, 10, ft_strlen(message) - 10));
	ft_join(&f_msg, "message", -1, ' ');
	ft_join(&f_msg, NULL, pos, ',');
	ft_join(&f_msg, msg, -1, '\n');
	ft_strdel(&msg);
	return (f_msg);
}

void			broadcast(t_env *env, char *message, int fd)
{
	int		i;
	int		pos;
	char	*f_msg;

	i = -1;
	while (++i < MAX_PLAYER)
	{
		pos = send_broadcast(env, i, fd);
		if (pos != -1)
		{
			f_msg = get_msg(message, pos);
			create_message(env, f_msg, i, env->what_time_is_it + 7);
		}
	}
	create_message(env, "ok\n", fd, env->what_time_is_it + 7);
}
