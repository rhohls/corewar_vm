# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/01 07:07:02 by rhohls            #+#    #+#              #
#    Updated: 2018/09/05 12:26:47 by rhohls           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
INC_PATH = ./includes/

SRC_FILE =	ft_stacknew.c	\
			ft_atoi_long.c	\
			ft_strcount.c	\
			ft_stackpop.c	\
			ft_stackpush.c	\
			ft_stackqueue.c	\
			ft_stackserve.c	\
			get_next_line.c	\
			ft_atoi.c		\
			ft_bzero.c		\
			ft_int_len.c	\
			ft_int_len_neg.c	\
			ft_isalnum.c	\
			ft_isalpha.c	\
			ft_isascii.c	\
			ft_isdigit.c	\
			ft_isprint.c	\
			ft_itoa.c		\
			ft_lstadd.c		\
			ft_lstdel.c		\
			ft_lstdelone.c	\
			ft_lstiter.c	\
			ft_lstmap.c		\
			ft_lstnew.c		\
			ft_memalloc.c	\
			ft_memccpy.c	\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_memcpy.c		\
			ft_memdel.c		\
			ft_memmove.c	\
			ft_memset.c		\
			ft_nextdig.c	\
			ft_power.c		\
			ft_putchar.c	\
			ft_putchar_fd.c	\
			ft_putendl.c	\
			ft_putendl_fd.c	\
			ft_putnbr.c		\
			ft_putnbr_fd.c	\
			ft_putstr.c		\
			ft_putstr_fd.c	\
			ft_strcat.c		\
			ft_strchr.c		\
			ft_strclr.c		\
			ft_strcmp.c		\
			ft_strcmp_simple.c	\
			ft_strcpy.c		\
			ft_strdel.c		\
			ft_strdup.c		\
			ft_strequ.c		\
			ft_striter.c	\
			ft_striteri.c	\
			ft_strjoin.c	\
			ft_strjoinfree.c	\
			ft_strlcat.c	\
			ft_strlen.c		\
			ft_strmap.c		\
			ft_strmapi.c	\
			ft_strncat.c	\
			ft_strncmp.c	\
			ft_strncmp_simple.c	\
			ft_strncpy.c	\
			ft_strnequ.c	\
			ft_strnew.c		\
			ft_strnstr.c	\
			ft_strrchr.c	\
			ft_strsplit.c	\
			ft_strstr.c		\
			ft_strsub.c		\
			ft_strtrim.c	\
			ft_strvalid.c	\
			ft_tolower.c	\
			ft_toupper.c	\
			ft_whitespace.c	\
			ft_printf.c		\
			ft_dprintf.c	\
			ft_stackdel.c	\
			ft_stackdup.c	\
			ft_stackrev.c	\
			ft_strstack.c	\
			ft_puthex.c		\
			ft_puthex_fd.c	\
			

OBJ_FILE = $(SRC_FILE:%.c=%.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_FILE))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_FILE))

CCFLAGS = -Wall -Werror -Wextra
CC = gcc $(CCFLAGS)

#all: $(NAME)

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@echo "\x1b[32m"Made Library $@"\x1b[0m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) -I$(INC_PATH) -o $@ -c $<
	@echo "\x1b[2m"Making "\x1b[35m"$@"\x1b[0m"

clean:
	@/bin/rm -f $(OBJ)
	@echo "\x1b[31m"Removed all $(NAME) objects"\x1b[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\x1b[31m"Removed libft.a"\x1b[0m"

re: fclean all

.PHONY: re fclean clean all
