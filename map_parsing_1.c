#include "cub.h"

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

/* Checks for an empty line when specifying the map in *.cub file. */
int	check_for_empty_lines(t_state *state, char *file)
{
	int		fd;
	char	*line;

	fd = 0;
	line = NULL;
	if (open_cub_file(file, &fd) == -1)
		return (-1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (ft_strlen(line) == 0 || line[0] == '\n')
		{
			printf("Error\nEmpty line found in map.\n");
			return (-1);
		}
		ft_free_string(&line);
		line = get_next_line(fd);
	}
	ft_free_string(&line);
	close(fd);
	return (0);
}

static int verify_map_start(char *line, int x)
{
	while (line[x] != '1')
		x++;
	if (line[x] == '1')
		return (0);
	return (1);
}

static int	get_map_start(t_state *state, char *file)
{
	int		x;
	int		y;
	int		fd;
	char	*line;

	x = 0;
	y = 0;
	fd = 0;
	line = NULL;
	if (open_cub_file(file, &fd) == -1)
		return (-1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		while (line[x])
		{
			if (line[x] == ' ' || line[x] == '1' || line[x] == '0')
			{
				if (line[x] != '1')
				{
					if (verify_map_start(line, x) == 0)
					{
						state->pos_map = y;
						close(fd);
						ft_free_string(&line);
						break ;
					}
				}
			}
			x++;
		}
		ft_free_string(&line);
		line = get_next_line(fd);
		y++;
	}
	if (state->pos_map == 0)
	{
		ft_putstr_fd("Error\nNo valid map found in *.cub.\n");
		return (-1);
	}
	ft_free_string(&line);
	return (0);
}

/* Finds calls gnl until the specified position in *.cub. */
int	get_to_pos(t_state *state, int pos, int fd)
{
	char	*line;
	int		i;

	i = 0;
	while (i != pos && line != NULL)
	{
		line = get_next_line(fd);
		ft_free_string(&line);
		i++;
	}
	if (line == NULL)
		return (1);
	return (0);
}

static int	checker_identifier(t_state *state, char *file)
{
	int		x;
	int		y;
	int		fd;
	char	*line;

	x = 0;
	y = 0;
	fd = 0;
	line = NULL;
	if (open_cub_file(file, &fd) == -1)
		return (-1);

	line = get_next_line(fd);
	while (line != NULL)
	{
		while (line[x])
		{
			if (line[x] == ' ' || line[x] == '1' || line[x] == '0')

			{
				if (line[x] != '1')
				{
					if (verify_map_start(line, x) == 0)
					{
						state->pos_map = y;
						close(fd);
						ft_free_string(&line);
						break ;
					}
				}
			}
			x++;
		}
		ft_free_string(&line);
		line = get_next_line(fd);
		y++;
	}
	if (state->pos_map == 0)
	{
		ft_putstr_fd("Error\nNo valid map found in *.cub.\n", 1);
		return (-1);
	}
	ft_free_string(&line);
	return (0);
}

/*	Parsing the *.cub map.

	Identifying the height of the map and the width of each row for memory
	allocation. Parsing the content of the map into state->map[][]. */
int	parsing(t_state *state, int argc, char **argv)
{
	if (checker_identifier(state, argv[1]) != 0)
		return (-1);


	get_map_start(state, argv[1]);
	if (check_for_empty_lines(state, argv[1]) != 0)
		return (-1);
	get_map_height(state, argv[1]);
	if (state->map_height == -1)
		return (-1);
	get_max_width(state, argv[1]);
	if (state->map_width == -1)
		return (-1);
	if (mem_alloc_columns(state) == -1)
		return (-1);
	if (mem_alloc_rows(state, argv[1]) == -1)
		return (-1);
	if (read_map(state, argv[1]) == -1)
		return (-1);
	return (0);
}
