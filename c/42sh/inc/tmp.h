/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 17:48:15 by vplotton          #+#    #+#             */
/*   Updated: 2014/03/27 21:41:21 by ele-goug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TMP_H
# define TMP_H

# include <fcntl.h>
# include <libft.h>
# include <sys/stat.h>
# include <session.h>

t_bool	ft_file_to_tmp(char *file);
t_bool	ft_tmp_to_file(char *file);
t_bool	ft_tmp_dr_to_file(char *file);
t_bool	ft_del_tmp(char *tmp_name);
int		ft_mk_tmp(t_bool append);

#endif
