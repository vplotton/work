# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/06/26 09:38:44 by jbernabe          #+#    #+#              #
#    Updated: 2014/06/26 09:45:37 by jbernabe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
#		make -C libft
		make -C ia_zappy
		make -C client
		make -C serveur

clean:
#		make clean -C libft
		make -C ia_zappy
		make clean -C client
		make clean -C serveur


fclean:
#		make fclean -C libft
		make -C ia_zappy
		make clean -C client
		make fclean -C client
		make fclean -C serveur

re: fclean all
