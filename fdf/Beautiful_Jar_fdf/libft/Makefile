# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbeaujar <bbeaujar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/07 14:23:53 by bbeaujar          #+#    #+#              #
#    Updated: 2015/02/10 14:49:08 by bbeaujar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

HEAD = includes/

SRC =	ft_atoi.c		ft_bzero.c 		ft_isalnum.c 	ft_isalpha.c 	\
		ft_isascii.c 	ft_isdigit.c 	ft_isprint.c 	ft_itoa.c 		\
		ft_lstadd.c 	ft_lstdel.c 	ft_lstdelone.c 	ft_lstiter.c 	\
		ft_lstmap.c 	ft_lstnew.c 	ft_memalloc.c 	ft_memccpy.c 	\
		ft_memchr.c 	ft_memcmp.c 	ft_memcpy.c 	ft_memdel.c 	\
		ft_memset.c 	ft_memmove.c 	ft_putchar.c 	ft_putchar_fd.c \
		ft_putendl.c 	ft_putendl_fd.c ft_putnbr.c 	ft_putnbr_fd.c 	\
		ft_putstr.c 	ft_putstr_fd.c 	ft_strcat.c 	ft_strchr.c 	\
		ft_strcmp.c 	ft_strcpy.c 	ft_strclr.c 	ft_strdel.c 	\
		ft_strdup.c 	ft_strequ.c 	ft_striter.c	ft_striteri.c 	\
		ft_strjoin.c	ft_strlcat.c 	ft_strlen.c 	ft_strmap.c 	\
		ft_strmapi.c	ft_strncat.c 	ft_strncmp.c	ft_strncpy.c 	\
		ft_strndup.c	ft_strnequ.c 	ft_strnew.c 	ft_strnstr.c 	\
		ft_strrchr.c	ft_strsplit.c 	ft_strstr.c 	ft_strsub.c 	\
		ft_strtrim.c	ft_tolower.c 	ft_toupper.c	get_next_line.c \

OBJ = $(SRC:.c=.o)

COLOR_G= \033[32m
COLOR_W= \033[37m

all: $(NAME)

$(NAME): $(OBJ)
		@ar rcs $(NAME) $(OBJ)
		@ranlib $(NAME)
		@echo  "$(COLOR_G)Compilation of $(NAME) done !$(COLOR_W)"

%.o : %.c
		@$(CC) $(CFLAGS) -I $(HEAD) -c $<

clean:
		@rm -f $(OBJ)
		@echo "Clean to OBJS $(NAME) done !"

fclean: clean
		@rm -f $(NAME)
		@echo "Clean $(NAME) done !"

re: fclean all

.PHONY: clean fclean re
