/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 15:58:34 by vplotton          #+#    #+#             */
/*   Updated: 2014/01/21 18:46:44 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	int		len;
	char	*output;

	i = 0;
	j = 0;
	k = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while ((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t'))
		i++;
	while ((i < len) && ((s[len - j - 1] == ' ') || (s[len - j - 1] == '\n')
				|| (s[len - j - 1] == '\t')))
		j++;
	output = (char *)ft_memalloc(len - i - j + 1);
	while (i < len - j)
		output[k++] = s[i++];
	output[k] = '\0';
	return (output);
}
