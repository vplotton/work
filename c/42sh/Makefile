# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/02 15:49:02 by vplotton          #+#    #+#              #
#    Updated: 2014/03/27 22:32:00 by qmarquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
RM			=	rm -rf
LDIR		=	./libft/
LLST		=	./lib_lists/
HEADER		=	./inc/
TERMCAP		=	/usr/lib/
NAME		=	42sh
L_MAKE		=	make -C $(LDIR)
LLST_MAKE	=	make -C $(LLST)
L_CLEAN		=	make clean -C $(LDIR)
LLST_CLEAN	=	make clean -C $(LLST)
L_FCLEAN	=	make fclean -C $(LDIR)
LLST_FCLEAN	=	make fclean -C $(LLST)
CFLAGS		=	-Wall -Werror -Wextra -I$(LDIR) -I$(LLST) -I$(HEADER) -g3
LDFLAGS		=	-L$(LDIR) -lft -L$(TERMCAP) -ltermcap
OBJ			=	$(SRC:.c=.o)

SRC			=			src/main.c						\
						src/builtin/cd.c                \
						src/builtin/echo.c				\
						src/builtin/ft_echo.c			\
						src/builtin/exit.c				\
						src/builtin/ft_strmlcmp.c       \
						src/builtin/ft_strnvcmp.c       \
						src/builtin/ft_strclone.c       \
						src/builtin/ft_strsclone.c      \
						src/builtin/ft_strxcpy.c        \
						src/builtin/ft_super_path_builder.c \
						src/builtin/ft_lstclean.c       \
						src/builtin/ft_lstbuild.c       \
						src/builtin/ft_xcheck.c         \
						src/builtin/ft_lstrem.c         \
						src/builtin/ft_mesure.c         \
						src/builtin/ft_isvalid.c        \
						src/builtin/ft_lststrstore.c    \
						src/builtin/get.c               \
						src/builtin/initialyze.c        \
						src/builtin/islower.c           \
						src/builtin/launcher_catch.c    \
						src/builtin/mild.c              \
						src/builtin/ft_path_builder.c	\
						src/builtin/poda.c				\
						src/builtin/set_and_unset.c     \
						src/builtin/spicy.c				\
						src/builtin/strs.c              \
						src/builtin/wordlen.c           \
						src/itk/itk_clear.c				\
						src/itk/itk_clipboard.c			\
						src/itk/itk_cpy.c				\
						src/itk/itk_ini.c				\
						src/itk/itk_delete.c			\
						src/itk/itk_help.c				\
						src/itk/itk_hist.c				\
						src/itk/itk_move_curs.c			\
						src/itk/itk_new_char.c			\
						src/itk/itk_print.c				\
						src/itk/itk_putstr.c			\
						src/itk/itk_read.c				\
						src/itk/itk_return.c			\
						src/itk/itk_start_end.c			\
						src/itk/itk_string_cmd.c		\
						src/itk/itk_strlen.c			\
						src/lexer/ft_list.c				\
						src/lexer/ft_lexer.c			\
						src/lexer/ft_get_sep.c			\
						src/parser/ft_ast.c				\
						src/parser/ft_parse.c			\
						src/parser/ft_check_parse.c		\
						src/process/ft_tmp.c			\
						src/process/ft_process.c		\
						src/process/ft_handle_cmd.c		\
						src/process/ft_handle_file.c	\
						src/process/ft_handle_redir.c	\
						src/process/ft_process_ast.c	\
						src/utils/ft_print.c

all:		$(NAME)

$(NAME):	$(OBJ)
	$(L_MAKE)
	$(LLST_MAKE)
	$(CC) -o $(NAME) $(CFLAGS) $(SRC) $(LDFLAGS) $(LLST)/my_lists.a

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

l_re:
	$(L_FCLEAN)
	$(L_MAKE)

llst_re:
	$(LLST_FCLEAN)
	$(LLST_MAKE)

fcleanall:	fclean
	$(L_FCLEAN)
	$(LLST_FCLEAN)
	$(RM) 42sh.dSYM
	$(RM) .DS_Store
	$(RM) .swo
	$(RM) .swp
	$(RM) file

help:
	@echo "commands: make all | clean | fclean | re | l_re | llst_re | fcleanall"

.PHONY:		all clean fclean make re
