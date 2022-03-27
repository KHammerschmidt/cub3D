#include "cub.h"

/* Allocates with calloc for width length of every row in map. */
int	mem_alloc_rows(t_state *state, char *file)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = 0;
	line = NULL;
	if (open_cub_file(file, &fd) == -1)
		return (-1);
	get_to_pos(state, state->map->pos_map, fd);
	while (i < state->map->map_height)
	{
		state->map->map[i] = ft_calloc(sizeof(char), state->map->map_width + 1);
		if (state->map->map[i] == NULL)
		{
			ft_putstr_fd("Error\nAllocation failed!\n", 1);
			ft_free_strarray(&state->map->map);
			return (-1);
		}
		ft_free_string(&line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (0);
}

/* Allocates with calloc for height number of columns. */
int	mem_alloc_columns(t_state *state)
{
	state->map->map = ft_calloc(state->map->map_height, sizeof(char *));
	if (state->map == NULL)
	{
		ft_putstr_fd("Error\nAllocation failed!\n", 1);
		return (-1);
	}
	return (0);
}
