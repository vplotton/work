/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_message.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obengelo <obengelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 19:04:07 by sbres             #+#    #+#             */
/*   Updated: 2014/06/26 14:58:55 by obengelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zappy.h"
#include <libft.h>

char		*ft_strdupcm(const char *s1)
{
	char	*dest;
	int		i;

	dest = (char *)malloc(sizeof(char) * (1024));
	dest[0] = '\0';
	i = 0;
	if (dest != NULL)
	{
		dest = ft_strcat(dest, s1);
		while (dest[i] != '\0')
			i++;
		while (i < 1024)
		{
			dest[i] = '\0';
			i++;
		}
		return (dest);
	}
	return (NULL);
}

t_to_send	*generate_message(char *str, int fd, double ttsend)
{
	t_to_send	*tmp;

	tmp = (t_to_send *)malloc(sizeof(t_to_send));
	tmp->message = ft_strdupcm(str);
	tmp->fd = fd;
	tmp->time_to_send = ttsend;
	tmp->next = NULL;
	return (tmp);
}

void		create_message(t_env *env, char *message, int fd, double ttsend)
{
	t_to_send	*tmp;
	t_to_send	*tmp_g;

	tmp = generate_message(message, fd, ttsend);
	tmp_g = env->message_queu;
	if (env->message_queu == NULL)
	{
		env->message_queu = tmp;
		return ;
	}
	while (tmp_g->next != NULL && tmp_g->time_to_send > ttsend)
		tmp_g = tmp_g->next;
	tmp->next = tmp_g->next;
	tmp_g->next = tmp;
}
