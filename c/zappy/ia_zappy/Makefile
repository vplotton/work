# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/29 12:22:40 by vplotton          #+#    #+#              #
#    Updated: 2014/06/08 15:29:41 by vplotton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
RM			=	rm -rf
HEADER		=	./incs/
LIBDIR		=	./libft/
L_MK		=	make -C $(LIBDIR)
NAME		=	ia_zappy
UNAME_S		=	$(shell uname -s)
CFLAGS		=	-Wall -Werror -Wextra -I$(HEADER) -I$(LIBDIR) -g3
ifeq ($(UNAME_S),Darwin)
	LDFLAGS		=	-L$(LIBDIR) -lft
else
	LDFLAGS		=	$(LIBDIR)/libft.a
endif
OBJ			=	$(SRC:.c=.o)
SRC			=	srcs/map.c			\
				srcs/init.c			\
				srcs/live.c			\
				srcs/main.c			\
				srcs/math.c			\
				srcs/move.c			\
				srcs/action.c		\
				srcs/detect.c		\
				srcs/__debug.c		\
				srcs/ressource.c	\
				srcs/neural_net.c	\
				srcs/mlp/feed.c		\
				srcs/mlp/create.c	\
				srcs/mlp/update.c	\
				srcs/mlp/genetic.c

all:		$(NAME)

$(NAME):	$(OBJ)
			$(L_MK)
				$(CC) -o $(NAME) $(CFLAGS) $(LDFLAGS) $(SRC)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean make re
