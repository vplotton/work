/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 15:43:59 by vplotton          #+#    #+#             */
/*   Updated: 2014/01/10 15:43:59 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_itoa(int n)
{
	char		*output;
	long int	nb;
	int			sign;
	int			div;
	int			i;

	div = 1;
	sign = (n < 0 ? 1 : 0);
	nb = ABS((long)n);
	while ((n = n / 10) && ABS(n) > 0)
		div++;
	output = (char*)malloc((div + 1 + sign) * sizeof(char));
	output[0] = (sign == 1 ? '-' : '0');
	i = (sign == 1 || nb == 0 ? 1 : 0);
	n = (nb == 0 ? 0 : 1);
	while (--div)
		n = n * 10;
	while (n)
	{
		output[i++] = '0' + nb / n;
		nb = nb - (nb / n) * n;
		n = n / 10;
	}
	output[i] = '\0';
	return (output);
}
