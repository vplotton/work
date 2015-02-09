/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 18:26:30 by vplotton          #+#    #+#             */
/*   Updated: 2014/05/20 18:37:01 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int		ft_check_ir(int err, int res, char *ft_n)
{
	if (res == err)
	{
		ft_putstr("Error encountered");
		if (ft_n)
		{
			ft_putstr(" in ");
			ft_putendl(ft_n);
		}
	}
	return (res);
}

void	*ft_check_vr(void *err, void *res, char *ft_n)
{
	if (res == err)
	{
		ft_putstr("Error encountered");
		if (ft_n)
		{
			ft_putstr(" in ");
			ft_putendl(ft_n);
		}
	}
	return (res);
}
