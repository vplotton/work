/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:15:28 by sbres             #+#    #+#             */
/*   Updated: 2014/05/12 23:55:37 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isascii(int cha)
{
	if (cha >= 0 && cha <= 127)
		return (1);
	return (0);
}
