NAME=cub3d
CC=cc
CFLAGS= -Wall -Werror -Wextra -g
RM=rm -rf

SRCS=src/cub3d.c
OBJS=$(SRCS:.c=.o)

PARS_DIR=src/parsing
PARS=$(PARS_DIR)/parsing.a

CYAN='\033[1;36m'
BLUE='\033[1;34m'
GREEN='\033[1;32m'
WHITE='\033[0;37m'

all : $(NAME)

$(NAME) : $(PARS) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(PARS)
	@clear
	@if [ $$? -eq 0 ]; then \
    	echo ${GREEN}">-Compilation successful-<"${WHITE}; \
    fi

%.o : %.c include/cub3d.h
	@$(CC) $(CFLAGS) -c $< -o $@

$(PARS) :
	@make --directory $(PARS_DIR)

clean :
	@make clean --directory $(PARS_DIR)
	@$(RM) $(OBJS)
	@clear
	@echo ${BLUE}">------Files clean-------<\n"${WHITE}

fclean : clean
	@$(RM) $(PARS)
	@$(RM) $(NAME)
	@echo ${CYAN}">-------Name clean-------<\n"${WHITE}

re : fclean all
	@clear
	@echo ${BLUE}">------Files clean-------<\n"${WHITE}
	@echo ${CYAN}">-------Name clean-------<\n"${WHITE}
	@echo ${GREEN}">-Compilation successful-<"${WHITE};

bonus : all

.PHONY: all clean fclean re bonus