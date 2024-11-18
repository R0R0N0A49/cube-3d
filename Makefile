NAME = cub3D
CC = cc
MAKEFLAGS += --no-print-directory
CFLAGS = -Ofast -Wall -Werror -Wextra -I./MLX42/include -g
MLXFLAGS = -ldl -lX11 -lglfw -lm -lz -lbsd -lXext
RM = rm -rf

SRCS_DIR = src
PARS_DIR = src/parsing
DISP_DIR = src/display
OBJS_DIR = OBJS

SRCS = cub3d.c \
       t_tmp.c \
       texture.c \
       read_file.c \
       init_anim.c \
       init_door.c \
	   t_tmp_clear.c \
	   init_anim_p2.c

PARS_SRCS = parsing.c \
            pars_map.c \
            pars_line.c \
            pars_door.c \
            check_line.c \
            print_error.c \
            printerrorpars.c \
            pars_start_line.c

DISP_SRCS =	door.c \
            menu.c \
            fonts.c \
            option.c \
			utils.c \
			moove.c \
			rotate.c \
            player.c \
 			minimap.c \
			mini_iso.c \
			draw_iso.c \
			draw_menu.c \
            animation.c \
            raycasting.c \
			door_utils.c \
            raycast_item.c \
			draw_minimap.c \
			check_button.c \
			init_minimap.c \
			button_utils.c \
			color_raycast.c \
			raycasting_dda.c \
			init_raycasting.c \
			draw_rayminimap.c \
			door_raycasting.c \
			condition_option.c \
			raycasting_bonus.c \
			check_option_button.c \
			loop.c \
			mouse.c \
			key_press_utils.c \
			key_press.c \
			check.c

ALL_SRCS = $(SRCS) $(PARS_SRCS) $(DISP_SRCS)

OBJS = $(ALL_SRCS:%.c=$(OBJS_DIR)/%.o)

LIBFT_DIR = includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

CYAN = \033[1;36m
BLUE = \033[1;34m
GREEN = \033[1;32m
GC = \033[6;32m
WHITE = \033[0;37m
BAR_LENGTH = 20

all: $(NAME)

$(NAME): CREATE_DIR MLX $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) ./MLX42/build/libmlx42.a $(MLXFLAGS)
	clear
	@echo "$(BLUE)Compiling MLX42   :$(GREEN) ✅\n$(BLUE)Compiling Libft   :$(GREEN) ✅\n$(BLUE)Compiling Cub3d   :$(GREEN) ✅\n$(BLUE)Compiling Parsing :\
$(GREEN) ✅\n$(BLUE)Compiling Display :$(GREEN) ✅$(WHITE)"
	@echo "$(GC)Compilation Finish$(WHITE)"

CREATE_DIR :
	@[ -d $(OBJS_DIR) ] || mkdir -p $(OBJS_DIR)

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
	@echo -n "$(BLUE)Compiling MLX42   :$(GREEN) ✅\n$(BLUE)Compiling Libft   :$(GREEN) ✅\n$(BLUE)Compiling Cub3d   :$(CYAN)"
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
	@echo -n "$(BLUE)Compiling MLX42   :$(GREEN) ✅\n$(BLUE)Compiling Libft   :$(GREEN) ✅\n$(BLUE)Compiling Cub3d   :$(GREEN) ✅\n$(BLUE)Compiling Parsing :$(CYAN)"
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
	@echo -n "$(BLUE)Compiling MLX42   :$(GREEN) ✅\n$(BLUE)Compiling Libft   :$(GREEN) ✅\n$(BLUE)Compiling Cub3d   :$(GREEN) ✅\n$(BLUE)Compiling Parsing :\
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
	@make clean --directory $(LIBFT_DIR)
	@$(RM) $(OBJS_DIR)
	clear
	@echo "$(BLUE)OBJS clear     : ✅$(WHITE)"

fclean: clean
	@make fclean --directory $(LIBFT_DIR)
	@$(RM) $(NAME)
	@echo "$(BLUE)$(NAME) clear    : ✅$(WHITE)"

end: fclean
	@$(RM) MLX42
	@echo "$(BLUE)Removing MLX42 : ✅$(WHITE)"

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus MLX
