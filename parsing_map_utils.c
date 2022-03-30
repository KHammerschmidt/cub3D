#include "cub.h"

void	print_map(t_state *state)
{
	//nur testing
	int		x;
	int		y;

	x = 0;
	y = 0;
	printf("\n CUB3D MAP \n\n");
	while (y < state->map->map_height)
	{
		x = 0;
		while (x != state->map->map_width)
		{
			if (state->map->map[y][x] == '\0')
				printf("[X]");
			else
				printf("[%c]", state->map->map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n");
}


/* Opens the file with reading permission and saves the file descriptor in fd
passed by it's address. Function returns -1 if unsuccessful. */
int	open_cub_file(char *file, int *fd)
{
	*fd = open(file, O_RDONLY);
	if (*fd == -1)
	{
		ft_putstr_fd("Error\nFile could not be read.\n", 1);
		close(*fd);
		return (-1);
	}
	return (0);
}


/* Loops through file until the specified position in *.cub. */
int	get_to_pos(t_state *state, int pos, int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (i != pos)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		ft_free_string(&line);
		i++;
	}
	if (line == NULL)
		return (1);
	return (0);
}

/* Gets map height and width, allocates respective memory and saves
map content in array. Returns 0 if no errors occur. */
int	parse_map(t_state *state, char **argv)
{
	if (get_map_height(state, argv[1]) == -1)
		return (-1);
	if (get_max_width(state, argv[1]) == -1)
		return (-1);
	if (mem_alloc_columns(state) == -1)
		return (-1);
	if (mem_alloc_rows(state, argv[1]) == -1)
		return (-1);
	if (read_map(state, argv[1]) == -1)
		return (-1);
	return (0);
}
