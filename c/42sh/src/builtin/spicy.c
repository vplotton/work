/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spicy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-goug <ele-goug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 17:22:29 by ele-goug          #+#    #+#             */
/*   Updated: 2014/03/27 22:31:55 by ele-goug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <meh.h>

t_execstatus	ft_case_e_next(void)
{
	if (ft_strmlcmp(session.in[0], "exit"))
	{
		session.exit = TRUE;
		if (session.in[1])
			session.return_code = ft_atoi(session.in[1]);
		return (EXEC_SUCCESS);
	}
	return (ABSCENT);
}

t_execstatus	ft_case_q(void)
{
	if (ft_strmlcmp(session.in[0], "quit"))
	{
		session.exit = TRUE;
		if (session.in[1])
			session.return_code = ft_atoi(session.in[1]);
		return (EXEC_SUCCESS);
	}
	return (ABSCENT);
}
