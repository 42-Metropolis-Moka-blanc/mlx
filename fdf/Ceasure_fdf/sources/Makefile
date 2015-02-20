# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/16 14:40:47 by cglavieu          #+#    #+#              #
#    Updated: 2015/02/16 18:51:38 by cglavieu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean, fclean, re

CC = gcc

CFLAG = -Wall -Wextra -Werror

NAME = ./fdf

SRC=		main.c        \
			hook.c   	   \
			coord.c 		\
			draw.c 		     \
			calc_dist_ab.c	\
			vect_ab.c        \
			vect_crux.c       \
			vect_octant_1_4.c  \
			vect_octant_5_8.c   \
			mlx_pixel_wput.c      \

OBJ = $(SRC:.c=.o)

LIBFT = libft/

LIBFTEXE = $(LIBFT)libft.a

MLX = -L/usr/x11/lib -lmlx -lXext -lX11 
XLIB = -I /opt/X11/include/X11 

all:    $(NAME)

$(NAME): $(OBJ) $(LIBFTEXE)

		@$(CC) $(CFLAG) -L $(LIBFT) -lft -o $(NAME)  $(OBJ) $(MLX)

$(OBJ): $(SRC)
		@$(CC) $(CFLAG) -I ./ -I  $(LIBFT)  -c $(SRC) $(XLIB)

$(LIBFTEXE): $(LIBFT)
		@make -k -s -C $(LIBFT)	

clean:	
		@rm -f  $(OBJ)
		@make -C $(LIBFT) clean

fclean: 
		@rm -f  $(OBJ)	
		@rm -f $(NAME)
		@make -C $(LIBFT) fclean

re:		fclean all

