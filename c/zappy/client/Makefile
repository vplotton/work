# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obengelo <obengelo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/06/10 18:13:57 by obengelo          #+#    #+#              #
#    Updated: 2014/06/26 06:13:16 by vplotton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
RM			=	rm -rf
HEADER		=	./incs/
LIBDIR		=	./libft/
UNAME_S		=	$(shell uname -s)
L_MK		=	make -C $(LIBDIR)
NAME		=	client
CFLAGS		=	-Wall -Werror -Wextra -I$(HEADER) -I$(LIBDIR) -g3
ifeq ($(UNAME_S),Darwin)
	LDFLAGS	=	-L$(LIBDIR) -lft
else
	LDFLAGS	=	$(LIBDIR)/libft.a
endif
OBJ			=	$(SRC:.c=.o)
SRC			=	srcs/com.c					\
				srcs/fork.c					\
				srcs/init.c					\
				srcs/live.c					\
				srcs/main.c					\
				srcs/move.c					\
				srcs/recv.c					\
				srcs/tools.c				\
				srcs/detect.c				\
				srcs/ia_dumb.c				\
				srcs/analyze.c				\
				srcs/master_pl.c			\
				srcs/broadcast.c			\
				srcs/args_file.c			\
				srcs/handle_map.c			\
				srcs/handle_cmd.c			\
				srcs/create_client.c		\
				srcs/parsing_params.c

all:		$(NAME)

$(NAME):	$(OBJ)
			$(L_MK)
				$(CC) -o $(NAME) $(CFLAGS) $(SRC) $(LDFLAGS)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean make re
