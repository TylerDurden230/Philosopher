
PROG =	philo

NAME =	philo.a

CC = 	gcc

FLAGS = -Wall -Wextra -Werror

SRCS =	main.c \
	initializer.c \
	utils.c \
	check.c \

OBJS =	$(SRCS:.c=.o)

RM =	rm -f
RMDIR = rm -dir -f

all:	$(NAME)

$(NAME):	$(OBJS)
	ar -rcs $(NAME) $(OBJS)
	ranlib $(NAME)
	$(CC) -o $(PROG) $(NAME)
	
.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(PROG)
	$(RMDIR) $(PROG).dSYM

re: fclean all

norme:
	norminette *.c *.h

debug: 
	$(CC) -g $(SRCS) -o $(PROG)

.PHONY: all clean flcean re debug norme
