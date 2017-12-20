# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: labrown <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/28 22:18:55 by labrown           #+#    #+#              #
#    Updated: 2017/12/15 22:29:18 by labrown          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= gnltest
SRC		= main.c \
		  get_next_line.c 

FLAGS	= -g -Wall -Werror -Wextra
OBJ		= $(SRC:.c=.o)
MAKE	= -C libft/

.PHONY	= all clean fclean re

all: $(NAME)

$(NAME) :
	@gcc $(FLAGS) -c $(SRC)
	@echo "\033[36mCompiled Objects\033[0m"
	@make $(MAKE) all
	@gcc $(FLAGS) $(OBJ) libft/libft.a -o $(NAME)
	@echo "\033[36mCompiled Executable\033[0m"

clean:
	@/bin/rm -f $(OBJ)
	@make $(MAKE) clean
	@/bin/rm -f $(OBJ)
	@echo "\033[31mRemoved Object Files\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@make $(MAKE) fclean
	@echo "\033[31mRemoved Executable\033[0m"

re: fclean all
