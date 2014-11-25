/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   session.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarquet <qmarquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 18:11:50 by qmarquet          #+#    #+#             */
/*   Updated: 2014/03/27 22:54:30 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SESSION_H
# define SESSION_H

# define TRUE		1
# define FALSE		0

typedef char		t_bool;

struct				s_path
{
	char			*home;
	char			*cdir;
};

struct				s_session
{
	struct s_path	path;
	char			**in;
	char			**env;
	int				ac;
	int				entry;
	int				return_code;
	int				sigtrap;
	int				swap;
	t_bool			exit;
	t_bool			has_pipe;
};

#endif
