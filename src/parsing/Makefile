NAME=parsing.a
CC=cc
CFLAGS= -Wall -Werror -Wextra -g
RM=rm -rf

SRCS=parsing.c
OBJS=$(SRCS:.c=.o)

ARRC=ar -rc

all : $(NAME)

$(NAME) : $(OBJS)
	@clear
	@$(ARRC) $(NAME) $(OBJS)
	@clear

%.o : %.c ../../includes/parsing.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

bonus : all

.PHONY: all clean fclean re bonus
