/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-goug <ele-goug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 21:29:08 by ele-goug          #+#    #+#             */
/*   Updated: 2014/03/27 21:29:11 by ele-goug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <meh.h>

void	ft_exit(int code)
{
	session.exit = FALSE;
	session.return_code = code;
}
