# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/10 15:30:01 by vplotton          #+#    #+#              #
#    Updated: 2014/03/17 20:36:58 by vplotton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
RM			=	rm -rf
NAME		=	my_lists.a
CFLAGS		=	-Wall -Wextra -Werror
OBJ			=	$(SRC:.c=.o)
SRC			=	dll_error.c			\
				dll_find.c			\
				dll_free_node.c		\
				dll_new.c			\
				dll_new_in_empty.c	\
				dll_new_node.c		\
				dll_remove.c		\
				dll_sg_meta.c		\
				my_memcmp.c			\
				my_memcpy.c

all:		$(NAME)

$(NAME):	$(OBJ) my_lists.h
			ar -q $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean re fclean
