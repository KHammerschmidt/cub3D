NAME		=		cub3D

CC 			=		gcc
FLAGS		=		-g -Wall -Werror -Wextra -L ./srcs/mlx -lmlx -L ./srcs/libft -lft -framework OpenGl -framework AppKit

SRC			=		main.c						\
					get_next_line.c				\
					check_args.c				\
					parsing.c					\
					parsing_identifiers.c		\
					parsing_map_content.c		\
					parsing_map_specs.c			\
					parsing_map_utils.c			\
					map_mem_alloc.c				\
					check_error_identifiers.c	\
					map_error_handling_1.c		\
					utils.c

LIBFT_OBJ	=		./srcs/libft/libft.a
MLX			=		./srcs/mlx/libmlx.a

OBJECTS		=		$(SRC:.c=.o)
OBJECTS_B	=		$(SRC_B:.c=.o)

all: $(NAME)

$(NAME): $(MLX) $(OBJECTS) $(LIBFT_OBJ)
	$(CC) $(FLAGS) $^ -o $@

$(MLX):
	make --directory=./srcs/mlx

$(LIBFT_OBJ):
	make --directory=./srcs/libft

clean:
	rm -f $(OBJECTS)
	make clean -C ./srcs/libft
# make clean -C ./srcs/mlx

fclean: clean
	rm -f $(NAME)
	make fclean -C ./srcs/libft

re: fclean all
