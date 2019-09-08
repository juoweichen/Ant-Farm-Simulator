# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juochen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/13 14:33:37 by juochen           #+#    #+#              #
#    Updated: 2018/04/16 18:38:10 by juochen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftMy.a
D_NAME = dbgr

LIBFT= libft/libft.a
HEADER = -I /includes

#FLAG = -Wall -Werror -Wextra

SRC_DIR = srcs
SRC = 	ft_printf.c \
		parse_func.c \
		conversion.c \
		color.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))

HAN_DIR = $(addprefix $(SRC_DIR)/, handlers)
HAN = 	handle_int.c \
		handle_str.c \
		handle_helper.c \
		handle_helper_print.c \
		handle_helper_set_prefix.c \
		handle_helper_set.c \
		handle_char.c \
		handle_hex.c \
		handle_oct.c \
		handle_unsigned.c \
		handle_escape.c \
		handle_address.c \
		handle_wchar.c \
		handle_wstr.c 
HANS = $(addprefix $(HAN_DIR)/, $(HAN))

DIST_DIR = $(addprefix $(SRC_DIR)/, dictionary)
DIST = 	dictionary.c \
		dict_helper.c
DISTS = $(addprefix $(DIST_DIR)/, $(DIST))

SRC_OBJ = $(SRC:.c=.o)
HAN_OBJ = $(HAN:.c=.o)
DIST_OBJ = $(DIST:.c=.o)

OBJ_DIR = objects

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT)
	@gcc -c $(SRCS) $(HANS) $(DISTS) $(HEADER)
	@cp $(LIBFT) $(NAME)
	@ar rc $(NAME) $(SRC_OBJ) $(HAN_OBJ) $(DIST_OBJ)
	@ranlib $(NAME)
	@mkdir $(OBJ_DIR)
	@mv *.o $(OBJ_DIR)
	@echo "\033[33mlib File \"$(NAME)\" Created\033[0m"

$(D_NAME): $(LIBFT)
	@gcc -g $(SRCS) main*.c $(HANS) $(HEADER) $(DISTS) $(LIBFT) -o $(D_NAME);
	@echo "\033[33mft_printf File \"$(D_NAME)\" Created\033[0m"

$(LIBFT):
	@make -C libft

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf *.o
	@make -C libft clean
	@echo "\033[31m$(NAME) Object File Removed\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf *.a
	@rm -rf $(D_NAME) $(D_NAME).dSYM
	@make -C libft fclean
	@echo "\033[31mft_printf File \"$(NAME)\" Removed\033[0m"

re: fclean all
