#include "cub.h"

static int	init_struct(t_state *state)
{
	state->map = ft_calloc(sizeof(t_map), 1);
	if (state->map == NULL)
	{
		ft_putstr_fd("Error\nMemory allocation error\n", 1);
		return (-1);
	}
	state->map->map_height = 0;
	state->map->map_width = 0;
	state->map->map = NULL;
	state->map->pos_map = -5;
	state->map->path_text = ft_calloc(sizeof(char *), 5);
	state->map->colours = ft_calloc(sizeof(char *), 4);
	if (state->map->path_text == NULL || state->map->path_text == NULL)
	{
		ft_putstr_fd("Error\nMemory allocation error\n", 1);
		// ft_free_all(state);
		return (-1);
	}
	state->map->colours[2] = NULL;
	state->map->path_text[4] = NULL;
	return (0);
}

/* // void	ft_free_all(t_state *state)
// {
// 	free_colours(state);
// 	free_path_text(state);
// 	free_map(state);
// } */

int	main(int argc, char *argv[])
{
	t_state	state;

	state = (t_state){0};
	if (init_struct(&state) != 0)
		return (1);
	if (check_args(argc, argv) == -1)
		return (1);
	if (parsing(&state, argc, argv) == -1)
		return (1);
	print_map(&state);
	// ft_free(state);
	return (0);
}
