NAME=cub3d
CC=cc
CFLAGS= -Wall -Werror -Wextra -g
RM=rm -rf

SRCS=src/cub3d.c
OBJS=$(SRCS:.c=.o)

PARS_DIR=src/parcing
PARS=$(src/parsing)/parsing.a

all : $(NAME)

$(NAME) : $(PARSING) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(PARS)
	clear
	@if [ $$? -eq 0 ]; then \
    	echo ${GREEN}">-Compilation successful-<"${WHITE}; \
    fi

%.o : %.c include/cub3d.h
	$(CC) $(CFLAGS) -c $< -o $@

$(PARSING) :
	@make --directory $(PARSING_DIR)

clean :
	@make clean --directory $(PARS_DIR)
	@$(RM) $(OBJS)
	@echo ${BLUE}">------Files clean-------<\n"${WHITE}

fclean : clean
	@$(RM) $(PARS)
	@$(RM) $(NAME)
	@echo ${CYAN}">-------Name clean-------<\n"${WHITE}

re : fclean all

bonus : all

.PHONY: all clean fclean re bonus