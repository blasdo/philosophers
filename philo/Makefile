NAME	=	philo
SRCS	=	philo.c \
			forks.c \
			utils.c \
			log.c \
			main.c
OBJS	=	${SRCS:.c=.o}
CC		=	gcc
CFLAGS	=	-g3 -Wall -Wextra -Werror -fsanitize=thread

all:	$(NAME)
clean:
	rm -f $(OBJS)
fclean:	clean
	rm -f $(NAME)
re:		fclean all

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)