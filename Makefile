NAME = cub3D
CC = gcc
CFLAGS = -Wall -Werror -Wextra

define LOGO

                                    .--,-``-.
  ,----..                          /   /     '.      ,---,
 /   /   \                ,---,   / ../        ;   .'  .' `\\
|   :     :         ,--,,---.'|   \ ``\  .`-    ',---.'     \\
.   |  ;. /       ,'_ /||   | :    \___\/   \   :|   |  .`\  |
.   ; /--`   .--. |  | ::   : :         \   :   |:   : |  '  |
;   | ;    ,'_ /| :  . |:     |,-.      /  /   / |   ' '  ;  :
|   : |    |  ' | |  . .|   : '  |      \  \   \ '   | ;  .  |
.   | '___ |  | ' |  | ||   |  / :  ___ /   :   ||   | :  |  '
'   ; : .'|:  | : ;  ; |'   : |: | /   /\   /   :'   : | /  ;
'   | '/  :'  :  `--'   \   | '/ :/ ,,/  ',-    .|   | '` ,/
|   :    / :  ,      .-./   :    |\ ''\        ; ;   :  .'
 \   \ .'   `--`----'   /    \  /  \   \     .'  |   ,.'
  `---`                 `-'----'    `--`-,,-'    '---'

endef
export LOGO

RESET = \033[0m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m

SRC =	src/main.c \
		src/mlx_utility/mu_draw_rect.c src/mlx_utility/mu_new_img.c src/mlx_utility/mu_new_rect.c \
		src/mlx_utility/mu_new_trgb.c src/mlx_utility/mu_put_pixel.c src/mlx_utility/mu_new_xpm_img.c \
		src/events/key_hook.c src/events/loop_hook.c src/events/mouse_hook.c src/events/movement.c \
		src/rendering/cgtutor.c src/rendering/minimap.c src/rendering/hand.c \
		src/vec2/perpendicular_vec2.c src/vec2/s_multiplication.c	\
		src/parser/check_args.c src/parser/parsing.c src/parser/parsing_identifiers_1.c \
		src/parser/parsing_identifiers_2.c src/parser/parsing_map_content.c src/parser/parsing_map_specs.c \
		src/parser/parsing_map_utils.c src/parser/map_mem_alloc.c src/parser/check_error_walls_row.c \
		src/parser/check_error_walls_column.c src/parser/map_error_handling_1.c src/parser/get_next_line.c \
		src/parser/utils.c src/parser/tex_handling.c src/parser/set_player_pos.c src/parser/rgb_config.c \
		src/exit/exit_cub.c	src/exit/free_state.c


INC = -Iinc -Imlx -Ilibft

LMLX = -Lmlx -lmlx -framework OpenGL -framework AppKit
MLX = ./mlx/libmlx.a

LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(SRC) $(MLX) $(LIBFT)
	@echo "$(YELLOW)\nBuilding $(NAME) ...$(RESET)"
	@$(CC) $(CFLAGS) $(SRC) $(INC) $(MLX) $(LMLX) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)$(NAME) successfully build\n$(RESET)"
	@echo "$(BLUE)"
	@echo "$$LOGO"
	@echo "$(RESET)"

$(MLX):
	@echo "$(YELLOW)\nBuilding MLX ...$(RESET)"
	@make -C mlx
	@echo "$(GREEN)MLX successfully build\n$(RESET)"

$(LIBFT):
	@echo "$(YELLOW)\nBuilding Libft ...$(RESET)"
	@make -C libft
	@echo "$(GREEN)Libft successfully build\n$(RESET)"

clean:
	@echo "$(YELLOW)\nCleaning the place\n$(RESET)"
	@make clean -C libft

fclean: clean
	@rm $(NAME)
	@make fclean -C libft
	@make clean -C mlx

re: fclean all

.PHONY: all clean fclean re
