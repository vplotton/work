# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/11 17:05:13 by vplotton          #+#    #+#              #
#    Updated: 2014/03/24 22:46:33 by vplotton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	llvm-gcc
RM			=	rm -rf
NAME		=	raytracer
L_RE		=	make re -C $(LIBDIR)
L_CL		=	make clean -C $(LIBDIR)
L_MAKE		=	make -C $(LIBDIR)
HEADER		=	./inc/
LIBDIR		=	./libft/
MLXDIR		=	/usr/X11/lib
CFLAGS		=	-Wall -Wextra -Werror -I$(LIBDIR) -I$(HEADER) -g3
LDFLAGS		=	-L$(MLXDIR) -lXext -lX11 -lmlx -L$(LIBDIR) -lft
OBJ			=	$(SRC:.c=.o)
SRC			=	src/main.c				\
				src/ft_draw.c			\
				src/ft_read.c			\
				src/ft_math.c			\
				src/ft_check.c			\
				src/ft_parse.c			\
				src/ft_rotate.c			\
				src/ft_compute.c		\
				src/ft_texture.c		\
				src/ft_get_info.c		\
				src/ft_intersect.c		\
				src/ft_get_scene.c		\
				src/ft_check_file.c		\
				src/ft_check_scene.c	\
				src/ft_print_error.c	\
				src/ft_handle_data.c	\
				src/ft_handle_cone.c	\
				src/ft_handle_plane.c	\
				src/ft_handle_sphere.c	\
				src/ft_handle_cylinder.c

all:		$(NAME)

$(NAME):	$(OBJ) $(HEADER)raytracer.h
			$(L_MAKE)
			$(CC) -o $(NAME) $(CFLAGS) $(LDFLAGS) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

l_re:
		$(L_RE)

l_cl:
		$(L_CL)

l_make:
		$(L_MAKE)

.PHONY:		all clean fclean re l_re l_cl l_make
