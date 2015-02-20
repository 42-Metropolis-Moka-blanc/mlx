# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbeaujar <bbeaujar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/09 16:17:36 by bbeaujar          #+#    #+#              #
#    Updated: 2015/02/17 14:30:47 by bbeaujar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:  clean, fclean, re, all, libft

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = fdf

SRC_PATH = ./srcs/

OBJ_PATH = ./objs/

LIBFT_PATH = ./libft/

LIBMLX_PATH = /usr/x11/lib/

SRC_NAME =	ft_draw.c		\
			ft_coord.c		\
			ft_put_pixel.c	\
			main.c			\

LIBFT_NAME = libft.a

OBJ_NAME = 	$(SRC_NAME:.c=.o)

SRC =		$(addprefix ($SRC_PATH),$(SRC_NAME))

OBJ =		$(addprefix $(OBJ_PATH),$(OBJ_NAME))

LIBFT =		$(addprefix $(LIBFT_PATH),$(LIBFT_NAME))

LIBMLX_FLAGS = -lmlx -lXext -lX11

LIBMLX_INC = /opt/X11/include/X11

COLOR_G= \033[32m
COLOR_W= \033[37m

all: libft $(NAME)

$(NAME): $(OBJ)
			@$(CC) -L $(LIBFT_PATH) -lft -L $(LIBMLX_PATH) $(LIBMLX_FLAGS) -o $(NAME) $(OBJ)
			@echo  "$(COLOR_G)Compilation of $(NAME) done !$(COLOR_W)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
			@mkdir -p $(OBJ_PATH)
			@$(CC) $(CFLAGS) -I . -I $(LIBFT_PATH) -I $(LIBMLX_INC) -o $@ -c $<

libft:	$(LIBFT)

$(LIBFT):
			@make -C $(LIBFT_PATH)

clean:
			@rm -f $(OBJ)
			@make -C $(LIBFT_PATH) clean
			@echo "Clean to OBJS $(NAME) done !"

fclean:
			@make -C $(LIBFT_PATH) fclean
			@rm -f $(NAME)
			@rm -f $(OBJ)
			@echo "Clean $(NAME) done !"

re:			fclean all
