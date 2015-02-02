NAME=		libmlx.a
SRCS=		vect.c        \
			ring.c   	   \
			calc_dist_AB.c	\
			vect_AB.c        \
			vect_crux.c       \
			vect_octant_1_4.c  \
			vect_octant_5_8.c   \
			ring2.c				 \



OBJS=		$(SRCS:.c=.o)
CFLAGS=		-Wall -Wextra -Werror
CC=			gcc
LIB=		ar rc
RM=			rm -f

$(NAME):	$(OBJS)
			$(LIB) $(NAME) $(OBJS)
			ranlib $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS) *~

fclean:		clean
			$(RM) $(NAME)

re:			fclean all