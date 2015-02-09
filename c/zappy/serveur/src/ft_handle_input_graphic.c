/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_input_graphic.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 17:17:33 by sbres             #+#    #+#             */
/*   Updated: 2014/06/26 11:32:45 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"

static void		ft_load_function(t_env *env)
{
	env->parse->f[0] = &(ft_get_map);
	env->parse->f[1] = &(ft_map_rscr);
	env->parse->f[2] = &(ft_allmap_rscr);
	env->parse->f[3] = &(ft_get_team_name);
	env->parse->f[4] = &(ft_player_pos);
	env->parse->f[5] = &(ft_player_lvl);
	env->parse->f[6] = &(ft_player_inventory);
	env->parse->f[7] = &(ft_get_time_of_server);
	env->parse->f[8] = &(ft_change_time);
	env->parse->f[9] = &(ft_number_of_teams);
	return ;
	(void)env;
}

void			ft_init_cmd(t_env *env)
{
	char	**cmd;
	int		i;

	i = 0;
	env->parse = (t_parse*)ft_memalloc(sizeof(t_parse));
	cmd = ft_strsplit("msz,bct,mct,tna,ppo,plv,pin,sgt,sst,ndeg", ',');
	env->parse->cmd = (char**)ft_memalloc(sizeof(char*) * 24);
	while (i < NBCMD)
	{
		env->parse->cmd[i] = ft_strdup(cmd[i]);
		i++;
	}
	ft_load_function(env);
}

void			ft_get_cmd(char *buffer, t_env *env, int fd)
{
	int	i;

	i = 0;
	buffer = ft_strtrim(buffer);
	while (i < NBCMD)
	{
		if (ft_strncmp(buffer, env->parse->cmd[i], 3) == 0)
		{
			printf("%s\n", env->parse->cmd[i]);
			(env->parse->f[i])(buffer, env, fd);
			return ;
		}
		i++;
	}
	create_message(env, "suc\n", fd, 0);
}
