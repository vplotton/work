/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 15:39:56 by vplotton          #+#    #+#             */
/*   Updated: 2014/01/10 15:39:56 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int		output;
	int		sign;

	output = 0;
	sign = 1;
	while ((*str == '\t') || (*str == '\n') || (*str == '\v')
			|| (*str == '\f') || (*str == '\r') || (*str == ' '))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while ((*str) && (*str >= '0') && (*str <= '9'))
	{
		output = (10 * output) + *str - '0';
		str++;
	}
	return (output * sign);
}
