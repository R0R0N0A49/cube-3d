NAME=cub3d
CC=cc
CFLAGS= -Wall -Werror -Wextra -g
RM=rm -rf

SRCS=src/cub3d.c
OBJS=$(SRCS:.c=.o)

PARS_DIR=src/parsing
PARS=$(PARS_DIR)/parsing.a

LIBFT_DIR= includes/libft
LIBFT=$(LIBFT_DIR)/libft.a

CYAN='\033[1;36m'
BLUE='\033[1;34m'
GREEN='\033[1;32m'
WHITE='\033[0;37m'

all : $(NAME)

$(NAME) : $(LIBFT) $(PARS) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(PARS) $(LIBFT)
	@mv src/*.o OBJS
	@clear
	@if [ $$? -eq 0 ]; then \
    	echo ${GREEN}">-Compilation successful-<"${WHITE}; \
    fi

%.o : %.c include/cub3d.h
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
	@make --directory $(LIBFT_DIR)

$(PARS) :
	@make --directory $(PARS_DIR)

clean :
	@$(RM) OBJS/*.o
	@clear
	@echo ${BLUE}">------Files clean-------<\n"${WHITE}

fclean : clean
	@$(RM) $(PARS)
	@$(RM) $(LIBFT)
	@$(RM) $(NAME)
	@echo ${CYAN}">-------Name clean-------<\n"${WHITE}

re : fclean all
	@clear
	@echo ${BLUE}">------Files clean-------<\n"${WHITE}
	@echo ${CYAN}">-------Name clean-------<\n"${WHITE}
	@echo ${GREEN}">-Compilation successful-<"${WHITE};

bonus : all

.PHONY: all clean fclean re bonus