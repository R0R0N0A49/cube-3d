# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 12:04:03 by antoine           #+#    #+#              #
#    Updated: 2024/05/16 13:35:32 by acaffard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
SRC=ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c\
	ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c\
	ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c\
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c\
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
	get_next_line.c get_next_line_utils.c ft_printf.c ft_printf_utils.c
OBJS=$(SRC:.c=.o)
RM=rm -rf
CC=cc
CFLAGS=-Wextra -Werror -Wall
ARRC=ar -rcs

CYAN = \033[1;36m
BLUE = \033[1;34m
GREEN = \033[1;32m
GC = \033[6;32m
WHITE = \033[1;37m
BAR_LENGTH = 20

all: $(NAME)

$(NAME): $(OBJS)
	@$(ARRC) $(NAME) $(OBJS)
	@mv *.o ../../OBJS

TOTAL := $(words $(SRC))
COUNT = 0

%.o: %.c libft.h
	@$(CC) $(CFLAGS) -c $< -o $@
	clear
	@$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
	@echo -n "$(BLUE)Compiling MLX42   :$(GREEN) ✅\n$(BLUE)Compiling Libft   :$(CYAN)"
	@echo -n "["
	@completed=$$(( $(COUNT) * $(BAR_LENGTH) / $(TOTAL) )); \
	remaining=$$(( $(BAR_LENGTH) - completed )); \
	for i in $$(seq 1 $$completed); do echo -n "█"; done; \
	for i in $$(seq 1 $$remaining); do echo -n "▒"; done
	@echo "] ($(COUNT)/$(TOTAL))"

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
