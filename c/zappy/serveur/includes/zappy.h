/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zappy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 20:32:42 by sbres             #+#    #+#             */
/*   Updated: 2014/06/26 20:39:01 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZAPPY_H
# define ZAPPY_H

# include "zappyfn.h"

t_arguments		*ft_parse_args(char **argv);
t_arguments		*ft_init_args(t_arguments *e);
t_arguments		*ft_parse_av(char **av, t_arguments *param);
t_arguments		*get_info(char **av, int *i, t_arguments *param);
t_arguments		*get_port(t_arguments *e, char **av, int *i);
t_arguments		*get_x(t_arguments *e, char **av, int *i);
t_arguments		*get_y(t_arguments *e, char **av, int *i);
int				ft_get_nb_team(char **av, int i);
t_arguments		*get_nb_player(t_arguments *e, char **av, int *i);
void			ft_puterror(char *msg);
t_arguments		*get_team(t_arguments *e, char **av, int *i);
t_arguments		*get_time(t_arguments *e, char **av, int *i);
void			ft_handle_input(t_env *env, int fd);
void			avance(t_env *env, char *message, int fd);
void			droite(t_env *env, char *message, int fd);
void			gauche(t_env *env, char *message, int fd);
void			voir(t_env *env, char *message, int fd);
void			prend(t_env *env, char *message, int fd);
void			pose(t_env *env, char *message, int fd);
void			create_message(t_env *env, char *message, int fd, double tt);
void			dispach_clients(t_env *env, int ret);
t_env			*ft_init_server(t_arguments *arguments);
void			ft_create_user(t_env *env, int fd);
void			send_message(t_env *env, int fd);
t_bool			init_map(t_env **env);
t_env			*ft_create_handelers(t_env *env);
void			ft_new_graphic(t_env *env, int fd);
void			no_found(t_env *env, char *message, int fd);
void			inventaire(t_env *env, char *message, int fd);
char			*ultime_buf(char **msg, char *add, char *alt);
void			tell_graphic(t_env *env, char *message, double ttsend);
int				is_grapich(t_graphic *grapic, int fd);
void			ft_init_cmd(t_env *env);
void			ft_get_cmd(char *buffer, t_env *env, int fd);
void			ft_get_map(char *buffer, t_env *env, int fd);
void			ft_allmap_rscr(char *buffer, t_env *env, int fd);
void			ft_change_time(char *buffer, t_env *env, int fd);
void			ft_get_team_name(char *buffer, t_env *env, int fd);
void			ft_get_time_of_server(char *buffer, t_env *env, int fd);
void			ft_map_rscr(char *buffer, t_env *env, int fd);
void			ft_player_inventory(char *buffer, t_env *env, int fd);
void			ft_player_lvl(char *buffer, t_env *env, int fd);
void			ft_player_pos(char *buffer, t_env *env, int fd);
void			ft_user_conected(t_env *env, t_player *pl, int fd);
void			ft_make_live(t_env *env);
void			connect_nbr(t_env *env, char *message, int fd);
void			expulse(t_env *env, char *message, int fd);
void			hfork(t_env *env, char *message, int fd);
void			addtodo(t_env *env, double time_to_do, int fontion, int pl);
t_env			*ft_create_handelers_to_do(t_env *env);
t_eggs			*egg_for_team(t_env *env, int team);
void			create_the_player(t_env *env, t_to_do *todo);
void			connect_by_egg(t_env *env, int fd, char *str);
void			create_egg(t_env *env, t_to_do *todo);
void			random_pos(t_arguments *world, t_player **player);
void			send_mapxy(t_env *env, int fd);
int				create_egg_env(t_env *env, int team, int x, int y);
void			incantation(t_env *env, char *message, int fd);
void			final_incantation(t_env *env, t_to_do *todo);
void			check_incatation(t_env *env, t_to_do *todo);
void			player_moved(t_env *env, int fd);
void			dell_new_user(t_env *env, int fd);
int				is_new_user(t_env *env, int fd);
void			new_user_conected(t_env *env, int fd);
void			handle_new_user(t_env *env, int fd, char *team);
void			ft_create_user_e(t_env *env, int fd, char *team);
void			ft_number_of_teams(char *buffer, t_env *env, int fd);
void			ft_del_graphique(t_env *env, int fd);
t_player		*new_player_e(t_env *env, char *team);
void			broadcast(t_env *env, char *message, int fd);
void			ft_join(char **msg, char *add, int nb, int opt);
void			burn_everything_in_fire(t_env *env, t_to_do *todo);
int				get_pio(t_env *env, char *team);
void			ft_get_player(t_env *env, int fd);

#endif