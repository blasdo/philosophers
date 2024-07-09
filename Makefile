NAME	=	philo
SRCS	=	philo.c \
			utils.c \
			log.c \
			main.c
OBJS	=	${SRCS:.c=.o}
CC		=	gcc
CFLAGS	=	-Wall -Wextra

all:	$(NAME)
clean:
	rm -f $(OBJS)
fclean:	clean
	rm -f $(NAME)
re:		fclean all

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)