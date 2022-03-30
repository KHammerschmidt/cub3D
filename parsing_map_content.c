#include "cub.h"

/* Writes on every position of the rectangular map a 0. */
static void	init_map(t_state *state)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < state->map->map_height)
	{
		x = 0;
		while (x < state->map->map_width)
		{
			state->map->map[y][x] = '-';
			x++;
		}
		y++;
	}
}

static int	read_map_grid(t_state *state, int fd)
{
	int		y;
	int		x;
	int		width;
	char	*line;

	y = 0;
	x = 0;
	line = get_next_line(fd);
	width = ft_strlen(line) - 1;
	while (y < state->map->map_height)
	{
		x = 0;
		if (y == (state->map->map_height -1))
			width = ft_strlen(line);
		else
			width = ft_strlen(line) - 1;
		while (x != width)
		{
			state->map->map[y][x] = line[x];
			x++;
		}
		ft_free_string(&line);
		line = get_next_line(fd);
		y++;
	}
	return (0);
}

int	read_map(t_state *state, char *file)
{
	int		fd;

	fd = 0;
	if (open_cub_file(file, &fd) == -1)
		return (-1);
	init_map(state);
	get_to_pos(state, state->map->pos_map, fd);
	if (read_map_grid(state, fd) != 0)
	{
		close(fd);
		ft_putstr_fd("Error\nEmpty line in map found.\n", 1);
		return (-1);
	}
	close(fd);
	return (0);
}
