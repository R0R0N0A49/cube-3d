NAME=display.a
CC=cc
CFLAGS= -Wall -Werror -Wextra -g -O2
RM=rm -rf

SRCS=	minimap.c \
		player.c \
		raycasting.c \
		menu.c \
		option.c \
		editeur.c \
		move.c \
		rotate.c \
		keybind.c \
		check_button_menu.c \
		check_option.c
OBJS=$(SRCS:.c=.o)

ARRC=ar -rcs

all : $(NAME)

$(NAME) : $(OBJS)
	@clear
	@$(ARRC) $(NAME) $(OBJS)
	@mv *.o ../../OBJS
	@clear

%.o : %.c ../../includes/cub3d.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

bonus : all

.PHONY: all clean fclean re bonus
