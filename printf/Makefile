# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/05 09:43:48 by skoskine          #+#    #+#              #
#    Updated: 2021/03/07 20:16:10 by skoskine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_DIR = src/
OBJ_DIR = obj/
LIBFT_DIR = ../

SRC = $(addprefix $(SRC_DIR), \
	ft_printf.c \
	ft_vasprintf.c \
	ft_asprintf.c \
	ft_dprintf.c \
	parser.c \
	conversion_specs.c \
	parse_chars.c \
	parse_doubles.c \
	dtoa.c \
	round_double.c \
	parse_signed_integers.c \
	parse_unsigned_integers.c \
	parse_pointers.c \
	parse_helpers.c \
)
OBJS = $(subst $(SRC_DIR), $(OBJ_DIR), $(SRC:.c=.o))

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror -g
CPPFLAGS = -I include -I ../

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@ar rcs $@ $(OBJS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -o $@ $^ $(CPPFLAGS)

$(OBJ_DIR):
	@mkdir $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
	
.PHONY: all clean fclean re