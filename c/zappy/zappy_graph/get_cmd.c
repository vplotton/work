/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 19:36:55 by cycharbo          #+#    #+#             */
/*   Updated: 2014/06/27 01:12:52 by cycharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy_graph.h"

static void	ft_load_function(t_env *env)
{
	env->parse->f[0] = &(ft_get_map);
	env->parse->f[1] = &(ft_map_rscr);
	env->parse->f[2] = &(ft_get_team_name);
	env->parse->f[3] = &(ft_new_player);
	env->parse->f[4] = &(ft_change_player_pos);
	env->parse->f[5] = &(ft_change_player_level);
	env->parse->f[6] = &(ft_change_inventory);
	env->parse->f[7] = &(ft_expulse);
	env->parse->f[8] = &(ft_broadcast);
	env->parse->f[9] = &(ft_incant);
	env->parse->f[10] = &(ft_incant_end);
	env->parse->f[11] = &(ft_egg);
	env->parse->f[12] = &(ft_drop_rscr);
	env->parse->f[13] = &(ft_get_rscr);
	env->parse->f[14] = &(ft_player_die);
	env->parse->f[15] = &(ft_egg_is_ok);
	env->parse->f[16] = &(ft_egg_is_dead);
	env->parse->f[17] = &(ft_egg_go);
}

void		ft_init_cmd(t_env *env)
{
	char	**cmd;
	int		i;
	char	txt[1024];
	char	*msg;

	i = 0;
	env->parse = (t_parse*)ft_memalloc(sizeof(t_parse));
	ft_strcat(txt, "msz,bct,tna,pnw,ppo,plv,pin,pex,pbc,pic,pie,pfk,pdr,pgt");
	ft_strcat(txt, ",pdi,enw,eht,ebo,edi,sgt,seg,smg,suc,sbp");
	msg = ft_strtrim(txt);
	cmd = ft_strsplit(msg, ',');
	env->parse->cmd = (char**)ft_memalloc(sizeof(char*) * 24);
	while (i < NBCMD)
	{
		env->parse->cmd[i] = ft_strdup(cmd[i]);
		i++;
	}
	ft_load_function(env);
}

void		ft_get_cmd(char *buffer, t_env *env)
{
	int		i;

	i = 0;
	while (i < NBCMD)
	{
		if (buffer && env->parse->cmd[i] &&
				ft_strncmp(buffer, env->parse->cmd[i], 3) == 0)
		{
			(env->parse->f[i])(buffer, env);
			break ;
		}
		i++;
	}
}
