# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juochen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/22 14:22:31 by juochen           #+#    #+#              #
#    Updated: 2018/04/19 21:23:21 by juochen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = -I /includes

#FLAG = -Wall -Werror -Wextra

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@gcc $(FLAG) -c $(SRC) $(HEADER)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[33mlibft File \"libft.a\" Created\033[0m"

clean:
	@rm -rf $(OBJ)
	@rm -rf *.o
	@echo "\033[31mlibft Object Files Removed\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf *.a
	@echo "\033[31mlibft File \"libft.a\" Removed\033[0m"

re: fclean all
