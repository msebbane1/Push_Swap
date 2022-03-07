# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 10:48:12 by msebbane          #+#    #+#              #
#    Updated: 2022/03/07 13:15:51 by msebbane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

OBJECTS	= ./bin
 
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

SRCS = srcs/main.c srcs/list.c libft/ft_putstr_fd.c libft/ft_atoi.c \
libft/ft_isdigit.c

RM = rm -f

ifndef BONUS
SOURCES	= ./srcs
OBJS	= $(SRCS:.c=.o)
else
SOURCES	= ./srcs_bonus
OBJS	= $(SRCS_BONUS:.c=.o)
endif

all: ${NAME}

bonus:
	@echo "\033[1;32m""Compilation de ${NAME}..."
	@make BONUS=1 ${NAME}

${NAME}: ${OBJS}
		@echo "\033[1;36m""Compilation de ${NAME}..."
		$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

${OBJECTS}/%.o: ${SOURCES}/%.c
	@echo "Compilation de ${notdir $<}."
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
		@echo "\033[1;32m""Supression des fichiers binaires (.o)..."
		${RM} ${OBJS}

fclean: clean
		@echo "\033[1;32m""Supression des executables et librairies..."
		${RM} ${NAME}
		${RM} *.out
		
re: fclean all
	@echo "\033[0m"

.PHONY: all clean fclean re