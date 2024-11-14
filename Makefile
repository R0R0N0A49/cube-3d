NAME = cub3D
CC = cc
MAKEFLAGS += --no-print-directory
CFLAGS = -O2 -Wall -Werror -Wextra -I./MLX42/include -g
MLXFLAGS = -ldl -lX11 -lglfw -lm -lz -lbsd -lXext
RM = rm -rf

SRCS_DIR = src
PARS_DIR = src/parsing
DISP_DIR = src/display
OBJS_DIR = OBJS

SRCS = cub3d.c \
       read_file.c \
       t_tmp.c \
       texture.c \
       init_anim.c

PARS_SRCS = parsing.c \
            pars_line.c \
            pars_map.c \
            check_line.c \
            printerrorpars.c \
            print_error.c

DISP_SRCS = minimap.c \
            player.c \
            raycasting.c \
            menu.c \
            option.c \
            fonts.c \
            animation.c \
            raycast_item.c \
			mini_iso.c \
			color_raycast.c

ALL_SRCS = $(SRCS) $(PARS_SRCS) $(DISP_SRCS)

OBJS = $(ALL_SRCS:%.c=$(OBJS_DIR)/%.o)

LIBFT_DIR = includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

CYAN = \033[1;36m
BLUE = \033[1;34m
GREEN = \033[1;32m
GC = \033[6;32m
WHITE = \033[1;37m
BAR_LENGTH = 20

all: $(NAME)

$(NAME): MLX $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) ./MLX42/build/libmlx42.a $(MLXFLAGS)
	clear
	@echo "$(BLUE)Compiling MLX42   :$(GREEN) ✅\n$(BLUE)Compiling Cub3d   :$(GREEN) ✅\n$(BLUE)Compiling Parsing :\
$(GREEN) ✅\n$(BLUE)Compiling Display :$(GREEN) ✅"
	@echo "$(GC)Compilation Finish$(WHITE)"

TOTAL := $(words $(SRCS))
COUNT = 0

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(LIBFT):
	@make --directory $(LIBFT_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	clear
	@$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
	@echo -n "$(BLUE)Compiling MLX42   :$(GREEN) ✅\n$(BLUE)Compiling Cub3d   :$(CYAN)"
	@echo -n "["
	@completed=$$(( $(COUNT) * $(BAR_LENGTH) / $(TOTAL) )); \
	remaining=$$(( $(BAR_LENGTH) - completed )); \
	for i in $$(seq 1 $$completed); do echo -n "█"; done; \
	for i in $$(seq 1 $$remaining); do echo -n "▒"; done
	@echo "] ($(COUNT)/$(TOTAL))"

TOTAL_P := $(words $(PARS_SRCS))
COUNT_P = 0

$(OBJS_DIR)/%.o: $(PARS_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	clear
	@$(eval COUNT_P=$(shell echo $$(($(COUNT_P)+1))))
	@echo -n "$(BLUE)Compiling MLX42   :$(GREEN) ✅\n$(BLUE)Compiling Cub3d   :$(GREEN) ✅\n$(BLUE)Compiling Parsing :$(CYAN)"
	@echo -n "["
	@completed=$$(( $(COUNT_P) * $(BAR_LENGTH) / $(TOTAL_P) )); \
	remaining=$$(( $(BAR_LENGTH) - completed )); \
	for i in $$(seq 1 $$completed); do echo -n "█"; done; \
	for i in $$(seq 1 $$remaining); do echo -n "▒"; done
	@echo "] ($(COUNT_P)/$(TOTAL_P))"

TOTAL_D := $(words $(DISP_SRCS))
COUNT_D = 0

$(OBJS_DIR)/%.o: $(DISP_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	clear
	@$(eval COUNT_D=$(shell echo $$(($(COUNT_D)+1))))
	@echo -n "$(BLUE)Compiling MLX42   :$(GREEN) ✅\n$(BLUE)Compiling Cub3d   :$(GREEN) ✅\n$(BLUE)Compiling Parsing :\
	$(GREEN) ✅\n$(BLUE)Compiling Display :$(CYAN)"
	@echo -n "["
	@completed=$$(( $(COUNT_D) * $(BAR_LENGTH) / $(TOTAL_D) )); \
	remaining=$$(( $(BAR_LENGTH) - completed )); \
	for i in $$(seq 1 $$completed); do echo -n "█"; done; \
	for i in $$(seq 1 $$remaining); do echo -n "▒"; done
	@echo "] ($(COUNT_D)/$(TOTAL_D))"

MLX:
	@clear
	@if [ -d "MLX42" ]; then \
		echo "$(BLUE)Compiling MLX42   :$(GREEN) ✅"; \
	else \
		git clone https://github.com/codam-coding-college/MLX42.git; \
		cmake ./MLX42 -B ./MLX42/build; \
		make -s -C ./MLX42/build -j4; \
		echo "$(BLUE)Compiling MLX42   :$(GREEN) ✅"; \
	fi

clean:
	@$(RM) $(OBJS_DIR)
	clear
	@echo "$(BLUE)OBJS clear     : ✅$(WHITE)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(BLUE)$(NAME) clear    : ✅$(WHITE)"

end: fclean
	@$(RM) MLX42
	@echo "$(BLUE)Removing MLX42 : ✅$(WHITE)"

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus MLX
