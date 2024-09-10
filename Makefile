NAME=cub3d
CC=cc
CFLAGS= -Wall -Werror -Wextra -g
MLXFLAGS= -ldl -lX11 -lglfw -lm -lz -lbsd -lXext
RM=rm -rf

SRCS=src/cub3d.c src/read_file.c src/print_error.c src/t_test.c
OBJS=$(SRCS:.c=.o)

PARS_DIR=src/parsing
PARS=$(PARS_DIR)/parsing.a

LIBFT_DIR= includes/libft
LIBFT=$(LIBFT_DIR)/libft.a

CYAN='\033[1;36m'
BLUE='\033[1;34m'
GREEN='\033[1;32m'
WHITE='\033[1;37m'

all : $(NAME)

$(NAME) : MLX $(LIBFT) $(PARS) $(OBJS)
	$(MLX)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(PARS) $(LIBFT) ./MLX42/build/libmlx42.a $(MLXFLAGS) 
	@mv src/*.o OBJS
	@clear
	@echo ${GREEN}">-Compilation successful-<"${WHITE};

%.o : %.c includes/cub3d.h
	@$(CC) $(CFLAGS) -c $< -o $@

MLX :
	@if ls | grep -q "MLX42"; then \
		clear; \
		echo "MLX42 already exist"; \
	else \
		git clone https://github.com/codam-coding-college/MLX42.git; \
		cmake ./MLX42 -B ./MLX42/build; \
		make -C ./MLX42/build --no-print-directory -j4; \
		make --directory ./MLX42/build; \
	fi

$(LIBFT) :
	@mkdir OBJS
	@make --directory $(LIBFT_DIR)

$(PARS) :
	@make --directory $(PARS_DIR)

clean :
	@$(RM) OBJS
	@clear
	@echo ${BLUE}">------Files clean-------<\n"${WHITE}

fclean : clean
	@$(RM) $(PARS) $(LIBFT) $(NAME)
	@echo ${CYAN}">-------Name clean-------<\n"${WHITE}

end :
	@$(RM) MLX42
	@echo ${BLUE}"\n>------MLX42 clean-------<\n"${WHITE}

re : fclean all
	@clear
	@echo ${BLUE}">------Files clean-------<\n"${WHITE}
	@echo ${CYAN}">-------Name clean-------<\n"${WHITE}
	@echo ${GREEN}">-Compilation successful-<"${WHITE};

bonus : all

.PHONY: all clean fclean re bonus MLX end