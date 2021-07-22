# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fd-agnes <fd-agnes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/22 16:57:44 by fd-agnes          #+#    #+#              #
#    Updated: 2021/07/22 17:12:44 by fd-agnes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOR_OFF	= "\033[0m"       # Text Reset
RED			= "\033[0;31m"    # Red
YELLOW		= "\033[0;33m"    # Yellow

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
	@ echo ""
	@ echo $(YELLOW)" _____ _   _ _                 _           " $(COLOR_OFF)
	@ echo $(YELLOW)"|  _  | |_|_| |___ ___ ___ ___| |_ ___ ___" $(COLOR_OFF)
	@ echo $(YELLOW)"|   __|   | | | . |_ -| . | . |   | -_|  _|" $(COLOR_OFF)
	@ echo $(YELLOW)"|__|  |_|_|_|_|___|___|___|  _|_|_|___|_|  " $(COLOR_OFF)
	@ echo $(YELLOW)"                          |_|              " $(COLOR_OFF)
	@ echo "" 
	@ ar -rcs $(NAME) $(OBJS)
	@ ranlib $(NAME)
	@ $(CC) $(FLAGS) -o $(PROG) $(NAME)
	@ echo "has been compiled succesfully"
	
.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

clean:
	@ $(RM) $(OBJS)
	
fclean: clean
	@ $(RM) $(NAME)
	@ $(RM) $(PROG)
	@ $(RMDIR) $(PROG).dSYM
	@ echo "Trash removed"

re: fclean all

debug: 
	$(CC) -g $(SRCS) -o $(PROG)

.PHONY: all clean flcean re debug
