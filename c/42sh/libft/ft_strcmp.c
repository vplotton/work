/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 15:46:27 by vplotton          #+#    #+#             */
/*   Updated: 2014/01/10 15:46:27 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	while ((*s1++ == *s2++))
	{
		if (!(*(s1 - 1)))
			return (*(s1 - 1) - *(s2 - 1));
	}
	return (*(s1 - 1) - *(s2 - 1));
}
