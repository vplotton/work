# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/07 20:12:10 by jbernabe          #+#    #+#              #
#    Updated: 2014/06/12 04:52:44 by jbernabe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

NAME = inter_face

CFLAGS = -Wall -Wextra -Werror `SDL-1.2.15/bin/sdl-config --cflags --libs` \
				SDL-1.2.15/lib/*.dylib -I libft/libft.a

LIB = -L libft -lft

SRC = menu_test2.c
#main.c cmd.c ft_display_ground.c ft_init.c init.c interface.c map.c ressource.c

OBJ = $(@SRC:.c=.o)

all:	$(NAME)


$(NAME):  $(OBJ)
		@$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIB)

%o.:%.c
		@$(CC) $(SRC) $(CFLAGS) -c $<
		@echo  Compiling object : $<

clean:	
		@rm -f $(OBJ)

fclean : clean
		@rm -f $(NAME)

re :  fclean all

.PHONY: all
