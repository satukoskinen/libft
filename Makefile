# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/05 13:58:06 by skoskine          #+#    #+#              #
#    Updated: 2021/02/16 08:44:09 by skoskine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
ft_memmove.c ft_memset.c ft_strcat.c ft_strchr.c ft_strcmp.c ft_strcpy.c \
ft_strdup.c ft_strlcat.c ft_strlen.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
ft_strnstr.c ft_strrchr.c ft_strstr.c ft_tolower.c ft_toupper.c ft_itoa.c \
ft_memalloc.c ft_memdel.c ft_putchar_fd.c ft_putchar.c ft_putendl_fd.c \
ft_putendl.c ft_putnbr_fd.c ft_putnbr.c ft_putstr_fd.c \
ft_putstr.c ft_strclr.c ft_strdel.c ft_strequ.c ft_striter.c ft_striteri.c \
ft_strjoin.c ft_strmap.c ft_strmapi.c ft_strnequ.c ft_strnew.c ft_strsplit.c \
ft_strsub.c ft_strtrim.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
ft_lstiter.c ft_lstmap.c ft_lstpushback.c ft_lstsize.c ft_isspace.c \
ft_atoi_base.c ft_itoa_base.c ft_abs.c ft_power.c ft_dpow.c \
ft_isnan.c ft_isposinf.c ft_isneginf.c ft_isnegative.c ft_modf.c \
ft_uintmax_itoa_base.c ft_intmax_itoa_base.c ft_realloc.c ft_dtoa.c
LIBFT_SRCS = ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
ft_lstmap.c ft_lstpushback.c ft_lstsize.c ft_bzero.c ft_memalloc.c \
ft_memmove.c ft_strcat.c ft_strchr.c ft_strcpy.c ft_strdup.c ft_strncat.c \
ft_strncpy.c ft_strnew.c ft_putendl_fd.c ft_putendl.c ft_putnbr_fd.c \
ft_putnbr.c ft_putstr_fd.c ft_putstr.c ft_strjoin.c ft_strlcat.c ft_strmap.c \
ft_strmapi.c ft_strrchr.c ft_strtrim.c ft_strsplit.c ft_strtrim.c ft_atoi.c \
ft_atoi_base.c ft_itoa.c ft_itoa_base.c ft_uintmax_itoa_base.c \
ft_intmax_itoa_base.c ft_realloc.c ft_dtoa.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(SRCS)
	@$(CC) $(CFLAGS) -c $^
	@ar rc $@ $(SRCS:.c=.o)

$(LIBFT_SRCS): libft.h

clean:
	@rm -f */*~ *~ $(SRCS:.c=.o)

fclean: clean
	@rm -f $(NAME)

re: fclean all
