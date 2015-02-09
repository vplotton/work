/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_client.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obengelo <obengelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 18:28:18 by obengelo          #+#    #+#             */
/*   Updated: 2014/06/26 20:53:24 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/client.h"

t_param			*ft_get_mapxy(t_param *e)
{
	int			rb;
	char		buf[1024];
	char		**tab;

	rb = recv(e->sock, buf, sizeof(buf), 0);
	printf("size map: %s\n", buf);
	if (rb != -1 && rb)
	{
		buf[rb] = '\0';
		tab = ft_strsplit(buf, 32);
		e->mapx = ft_atoi(tab[0]);
		e->mapy = ft_atoi(tab[1]);
	}
	return (e);
}

t_param			*ft_get_nb_client(t_param *e)
{
	int			rb;
	char		buf[1024];

	rb = recv(e->sock, buf, sizeof(buf), 0);
	printf("nb client: %s\n", buf);
	if (rb != -1 && rb)
	{
		buf[rb] = '\0';
		e->nb_client = ft_atoi(buf);
	}
	return (e);
}

t_param			*ft_get_server_info(t_param *e)
{
	int				rb;
	char			buf[1024];
	char			*msg;

	rb = recv(e->sock, buf, sizeof(buf), 0);
	if (rb != -1 && rb)
	{
		buf[rb] = '\0';
		if (ft_strncmp(buf, "BIENVENUE", 9) == 0)
		{
			ft_putstr(buf);
			msg = ft_strjoin(e->team, "\n");
			send(e->sock, msg, ft_strlen(msg) + 1, 0);
			ft_strdel(&msg);
			e = ft_get_nb_client(e);
			e = ft_get_mapxy(e);
		}
	}
	return (e);
}

int				create_client(char *addr, t_param *e)
{
	if ((e->proto = getprotobyname("tcp")) == 0)
	{
		ft_putstr("error get proto");
		return (-1);
	}
	e->sock = socket(PF_INET, SOCK_STREAM, (e->proto)->p_proto);
	e->sin.sin_family = AF_INET;
	e->sin.sin_port = htons(e->port);
	e->sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(e->sock, (struct sockaddr *)(&(e->sin)), sizeof(e->sin)) == -1)
	{
		ft_putstr("Connect error ");
		return (-1);
	}
	e = ft_get_server_info(e);
	return (e->sock);
}
