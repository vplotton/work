/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/27 01:24:55 by cycharbo          #+#    #+#             */
/*   Updated: 2014/06/27 01:25:08 by cycharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy_graph.h"

void	ft_load_anim_name(t_env *env)
{
	char			**cmd;
	int				i;
	char			*txt;
	char			msg[1024];

	i = 0;
	ft_strcat(msg, "img/msg_up.bmp,img/msg_xpulse.bmp,img/msg_broad.bmp");
	ft_strcat(msg, ",img/msg_incant.bmp,img/msg_egg.bmp");
	txt = ft_strtrim(msg);
	cmd = ft_strsplit(txt, ',');
	env->anim->msg_name = (char**)ft_memalloc(sizeof(char*) * 5);
	while (i < 5)
	{
		env->anim->msg_name[i] = ft_strdup(cmd[i]);
		i++;
	}
}

void	ft_load_ft_anim(t_env *env)
{
	env->anim = (t_anim*)ft_memalloc(sizeof(t_anim));
	env->anim->ft[0] = &(ft_msg_anim);
	env->anim->ft[1] = &(ft_msg_anim);
	env->anim->ft[2] = &(ft_msg_anim);
	env->anim->ft[3] = &(ft_msg_anim);
	env->anim->ft[4] = &(ft_msg_anim);
	ft_load_anim_name(env);
}

int		ft_fade_out(SDL_Surface *lvl_up, t_player *player)
{
	unsigned int	time;

	time = SDL_GetTicks();
	if (player->cur_anim == FALSE)
	{
		player->str_anim = SDL_GetTicks();
		time = SDL_GetTicks();
		player->img_frame = 0;
		player->cur_anim = TRUE;
	}
	if (player->img_frame == 0)
	{
		player->img_frame++;
		return (255);
	}
	else if (time - player->str_anim > 1200 && player->img_frame == 1)
	{
		SDL_SetAlpha(lvl_up, SDL_SRCALPHA, 0);
		player->cur_anim = FALSE;
		player->img_frame = 0;
		return (0);
	}
	return (1);
}

void	ft_msg_anim(int id, t_env *env, int j)
{
	SDL_Surface		*lvl_up;
	SDL_Surface		*plvl_up;
	SDL_Rect		pos;
	int				alpha;

	lvl_up = SDL_LoadBMP(env->anim->msg_name[j]);
	pos = ft_pos_player(env, env->pl[id].pos.x, env->pl[id].pos.y);
	pos.y -= 30;
	SDL_SetColorKey(lvl_up, SDL_SRCCOLORKEY, SDL_MapRGB(lvl_up->format,
				255, 255, 0));
	plvl_up = SDL_DisplayFormatAlpha(lvl_up);
	SDL_FreeSurface(lvl_up);
	if ((alpha = ft_fade_out(plvl_up, &(env->pl[id]))) == 0)
		env->pl[id].anim[j] = FALSE;
	SDL_SetAlpha(plvl_up, SDL_SRCALPHA, alpha);
	SDL_BlitSurface(plvl_up, NULL, env->display->anim_event, &pos);
	SDL_FreeSurface(plvl_up);
}

void	ft_check_anim(t_env *env)
{
	int			i;
	int			j;

	j = 0;
	i = 0;
	while (i < MAX_PLAYER)
	{
		j = 0;
		while (j < 6)
		{
			if (env->pl[i].anim[j] && env->pl[i].anim[j] == TRUE)
			{
				(env->anim->ft[j])(i, env, j);
				break ;
			}
			j++;
		}
		i++;
	}
}
