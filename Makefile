# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/05 13:58:06 by skoskine          #+#    #+#              #
#    Updated: 2021/03/16 21:30:35 by skoskine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = $(LIST_SRC) $(MATH_SRC) $(MEM_SRC) $(STR_SRC) $(PUTS_SRC) $(OTHER_SRC) $(PRINTF_SRC)
LIBFT_SRC = ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
ft_lstmap.c ft_lstpushback.c ft_lstsize.c ft_bzero.c ft_memalloc.c \
ft_memmove.c ft_strcat.c ft_strchr.c ft_strcpy.c ft_strdup.c ft_strncat.c \
ft_strncpy.c ft_strnew.c ft_putendl_fd.c ft_putendl.c ft_putnbr_fd.c \
ft_putnbr.c ft_putstr_fd.c ft_putstr.c ft_strjoin.c ft_strlcat.c ft_strmap.c \
ft_strmapi.c ft_strrchr.c ft_strtrim.c ft_strsplit.c ft_strtrim.c ft_atoi.c \
ft_atoi_base.c ft_itoa.c ft_itoa_base.c ft_uintmax_itoa_base.c \
ft_intmax_itoa_base.c ft_realloc.c ft_fabs.c get_next_line.c

LIST_SRC = $(addprefix list/, \
	ft_lstadd.c \
	ft_lstdel.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstpushback.c \
	ft_lstsize.c \
)

MATH_SRC = $(addprefix math/, \
	ft_abs.c \
	ft_dpow.c \
	ft_fabs.c \
	ft_isnan.c \
	ft_isnegative.c \
	ft_isneginf.c \
	ft_isposinf.c \
	ft_modf.c \
	ft_power.c \
	ft_uintmax_pow.c \
	ft_atoi.c \
	ft_atoi_base.c \
)

MEM_SRC = $(addprefix mem/, \
	ft_bzero.c \
	ft_calloc.c \
	ft_memalloc.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdel.c \
	ft_memmove.c \
	ft_memset.c \
	ft_realloc.c \
)

PUTS_SRC = $(addprefix puts/, \
	ft_putchar_fd.c \
	ft_putchar.c \
	ft_putendl_fd.c \
	ft_putendl.c \
	ft_putnbr_fd.c \
	ft_putnbr.c \
	ft_putstr_fd.c \
	ft_putstr.c \
)

STR_SRC = $(addprefix str/, \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_isspace.c \
	ft_strcat.c \
	ft_strchr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlen.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strnew.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strsplit.c \
	ft_strstr.c \
	ft_strsub.c \
	ft_strtrim.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_intmax_itoa_base.c \
	ft_uintmax_itoa_base.c \
	ft_itoa_base.c \
	ft_itoa.c \
)

OTHER_SRC = $(addprefix other/, \
	get_next_line.c \
)

PRINTF_SRC = $(addprefix printf/src/, \
	ft_asprintf.c \
	ft_dprintf.c \
	ft_printf.c \
	ft_vasprintf.c \
	conversion_specs.c \
	dtoa.c \
	parse_chars.c \
	parse_doubles.c \
	parse_pointers.c \
	parse_signed_integers.c \
	parse_unsigned_integers.c \
	parse_helpers.c \
	parser.c \
	round_double.c \
)

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror -g
CPPFLAGS = -I . -I printf/include

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(SRC:.c=.o) 
	ar rc $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $^ -o $@ $(CPPFLAGS)

$(LIBFT_SRC): libft.h

$(PRINTF_SRC): printf/include/ft_printf.h

clean:
	@rm -f $(SRC:.c=.o)

fclean: clean
	@rm -f $(NAME)

re: fclean all
