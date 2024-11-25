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

SRCS =	cub3d.c \
       	t_tmp.c \
    	read_file.c \
		t_tmp_clear.c \
		init.c

PARS_SRCS = parsing.c \
            pars_map.c \
            pars_line.c \
            check_line.c \
            print_error.c \
            printerrorpars.c \
            pars_start_line.c

DISP_SRCS = utils.c \
			moove.c \
			rotate.c \
            raycasting.c \
			raycasting_dda.c \
			init_raycasting.c \
			key_press.c

SRCS_DIR_BONUS = src_bonus
PARS_DIR_BONUS = src_bonus/parsing
DISP_DIR_BONUS = src_bonus/display

SRCS_BONUS =	t_tmp_bonus.c \
				cub3d_bonus.c \
				texture_bonus.c \
				read_file_bonus.c \
				init_anim_bonus.c \
				init_door_bonus.c \
				init_image_bonus.c \
				t_tmp_clear_bonus.c \
				cub3d_utils_bonus.c \
				init_struct_bonus.c \
				init_anim_p2_bonus.c \
				free_bonus.c \

PARS_SRCS_BONUS =	parsing_bonus.c \
            		pars_map_bonus.c \
           			pars_line_bonus.c \
            		pars_door_bonus.c \
            		check_line_bonus.c \
            		print_error_bonus.c \
            		printerrorpars_bonus.c \
            		pars_start_line_bonus.c

DISP_SRCS_BONUS =	door_bonus.c \
					loop_bonus.c \
           			menu_bonus.c \
					mouse_bonus.c \
            		fonts_bonus.c \
            		option_bonus.c \
					utils_bonus.c \
					moove_bonus.c \
					rotate_bonus.c \
            		player_bonus.c \
 					minimap_bonus.c \
					mini_iso_bonus.c \
					draw_iso_bonus.c \
					draw_menu_bonus.c \
            		animation_bonus.c \
            		raycasting_bonus.c \
					door_utils_bonus.c \
					raycast_item_bonus.c \
					draw_minimap_bonus.c \
					check_button_bonus.c \
					init_minimap_bonus.c \
					button_utils_bonus.c \
					color_raycast_bonus.c \
					raycasting_dda_bonus.c \
					init_raycasting_bonus.c \
					draw_rayminimap_bonus.c \
					door_raycasting_bonus.c \
					condition_option_bonus.c \
					draw_raycasting_bonus.c \
					check_option_button_bonus.c \
					key_press_utils_bonus.c \
					key_press_bonus.c \
					check_bonus.c

ALL_SRCS = $(SRCS) $(PARS_SRCS) $(DISP_SRCS)
ALL_SRCS_BONUS = $(SRCS_BONUS) $(PARS_SRCS_BONUS) $(DISP_SRCS_BONUS)

OBJS = $(ALL_SRCS:%.c=$(OBJS_DIR)/%.o)
OBJS_BONUS = $(ALL_SRCS_BONUS:%.c=$(OBJS_DIR)/%.o)

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

TOTAL := $(words $(SRCS_BONUS))
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

$(OBJS_DIR)/%.o: $(SRCS_DIR_BONUS)/%.c | $(OBJS_DIR)
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

TOTAL_P := $(words $(PARS_SRCS_BONUS))
COUNT_P = 0

$(OBJS_DIR)/%.o: $(PARS_DIR_BONUS)/%.c | $(OBJS_DIR)
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

TOTAL_D := $(words $(DISP_SRCS_BONUS))
COUNT_D = 0

$(OBJS_DIR)/%.o: $(DISP_DIR_BONUS)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	clear
	@$(eval COUNT_D=$(shell echo $$(($(COUNT_D)+1))))
	@echo -n "$(BLUE)Compiling MLX42   :$(GREEN) ✅\n$(BLUE)Compiling Libft   :$(GREEN) ✅\n$(BLUE)Compiling Cub3d   :$(GREEN) ✅\n$(BLUE)Compiling Parsing :"
	@echo -n "$(GREEN) ✅\n$(BLUE)Compiling Display :$(CYAN) ["
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

bonus:  CREATE_DIR MLX $(LIBFT) $(OBJS_BONUS)
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJS_BONUS) $(LIBFT) ./MLX42/build/libmlx42.a $(MLXFLAGS)
		clear
		@echo -n "$(BLUE)Compiling MLX42   :$(GREEN) ✅\n$(BLUE)Compiling Libft   :$(GREEN) ✅\n$(BLUE)Compiling Cub3d   :$(GREEN) ✅\n$(BLUE)Compiling Parsing :"
		@echo "$(GREEN) ✅\n$(BLUE)Compiling Display :$(GREEN) ✅$(WHITE)"
		@echo "$(GC)Compilation Finish$(WHITE)"

.PHONY: all clean fclean re bonus MLX
