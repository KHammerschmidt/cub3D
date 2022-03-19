NAME		=		cub3D

CC 			=		gcc
FLAGS		=		-g -Wall -Werror -Wextra -L ./srcs/mlx -lmlx -L ./srcs/libft -lft -framework OpenGl -framework AppKit

SRC			=		main.c					\
					get_next_line.c			\
					input_verification.c	\
					map_parsing_1.c			\
					map_parsing_2.c			\
					map_error_handling_1.c	\
					map_mem_allocation.c	\
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
