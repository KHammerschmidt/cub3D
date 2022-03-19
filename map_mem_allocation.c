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
	while (i < state->map_height)
	{
		state->map[i] = (char *)ft_calloc(sizeof(char), state->map_width + 1);
		if (state->map[i] == NULL)
		{
			ft_putstr_fd("Error\nAllocation failed!\n", 1);
			ft_free_strarray(&state->map);
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
	state->map = (char **)ft_calloc(state->map_height, sizeof(char *));
	if (state->map == NULL)
	{
		ft_putstr_fd("Error\nAllocation failed!\n", 1);
		return (-1);
	}
	return (0);
}

/* Reads every line with gnl to identify the longest line in *.cub file. */
int	get_max_width(t_state *state, char *file)
{
	int		y;
	int		fd;
	int		len;
	char	*line;

	y = 0;
	line = NULL;
	if (open_cub_file(file, &fd) == -1)
		return (-1);
	get_to_pos(state, state->pos_map, fd);
	// while (y != state->pos_map)
	// {
	// 	line = get_next_line(fd);
	// 	ft_free_string(&line);
	// 	y++;
	// }
	// y = 0;
	while (y < state->map_height)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		len = ft_strlen(line) - 1;
		if (len > state->map_width && y == (state->map_height - 1))
			state->map_width = len + 1;
		else if (len > state->map_width)
			state->map_width = len;
		ft_free_string(&line);
		y++;
	}
	ft_free_string(&line);
	close(fd);
	return (0);
}

/* Opens the file and reads every line calling gnl to count the map height. */
int	get_map_height(t_state *state, char *file)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = 0;
	line = NULL;
	if (open_cub_file(file, &fd) == -1)
		return (-1);
	while (i != state->pos_map)
	{
		line = get_next_line(fd);
		ft_free_string(&line);
		i++;
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_free_string(&line);
		state->map_height++;
		line = get_next_line(fd);
	}
	ft_free_string(&line);
	close(fd);
	return (0);
}
