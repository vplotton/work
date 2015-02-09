#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obengelo <obengelo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/06/27 03:24:43 by obengelo          #+#    #+#              #
#    Updated: 2014/06/27 03:24:49 by obengelo         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = clang

NAME = gfx

CFLAGS = -Wall -Wextra -Werror -g --debug \
		 `SDL-1.2.15/bin/sdl-config --cflags --libs` \
		 SDL-1.2.15/lib/*.dylib -I libft/libft.a

LIB = -L libft -lft -lSDLmain -lSDL

SRC = anim_event.c \
		ft_pause.c \
		background.c \
		cam.c \
		client.c \
		cmd.c \
		cmd2.c \
		cmd3.c \
		cmd4.c \
		cmd5.c \
		com.c \
		convert.c \
		display_itf.c \
		draw.c \
		ft_display_ground.c \
		ft_init.c \
		ft_max_pl.c \
		get_cmd.c \
		grid.c \
		ground_detail.c \
		init.c \
		interface.c \
		level.c \
		main.c \
		map.c \
		player.c \
		ressource.c \
		rscr.c \
		tools.c \


OBJ = $(@SRC:.c=.o)

lib_graph:
	sh test.sh

all:$(NAME)

$(NAME):	$(OBJ)
			Make -C libft
			@$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIB)

%o.:%.c
			@$(CC) $(SRC) $(CFLAGS) -c $<
			@echo  Compiling object : $<

clean:
			@rm -f $(OBJ)

fclean : clean
			@rm -f $(NAME)

re :  fclean all

sdl: lib_graph

.PHONY: all
