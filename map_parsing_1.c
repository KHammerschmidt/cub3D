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

/* Checks if there are any characters found in line which are not map characters.
If so, the start of the map has not bee n found. */
static int	check_characters(t_state *state, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ft_strlen(line) - 1)
	{
		j = 0;
		while (line[i] != state->map_char[j] && state->map_char[j] != '\0')
			j++;
		if (state->map_char[j] == '\0')
			return (1);
		i++;
	}
	return (0);
}

/* Finds calls gnl until the specified position in *.cub. */
int	get_to_pos(t_state *state, int pos, int fd)
{
	char	*line;
	int		i;

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

static int	check_identifiers(t_state *state)
{
	if (state->pos_no == NULL || state->pos_so == NULL || state->pos_ea == NULL
		|| state->pos_we == NULL || state->pos_map == -5)
	{
		ft_putstr_fd("Error\n*.cub file is missing information\n", 1);
		return (-1);
	}
	return (0);
}

int	get_identifiers(t_state *state, char *file)
{
	int		fd;
	int		i;
	char 	*line;

	i = 0;
	fd = 0;
	line = NULL;
	if (open_cub_file(file, &fd) == -1)
		return (-1);
	line = get_next_line(fd);
	state->pos_map = -5;
	while (line != NULL)
	{
		if (ft_strnstr(line, "NO", ft_strlen(line)) != 0)
			state->pos_no = ft_split(line, ' ');
		if (ft_strnstr(line, "SO", ft_strlen(line)) != 0)
			state->pos_so = ft_split(line, ' ');
		if (ft_strnstr(line, "EA", ft_strlen(line)) != 0)
			state->pos_ea = ft_split(line, ' ');
		if (ft_strnstr(line, "WE", ft_strlen(line)) != 0)
			state->pos_we = ft_split(line, ' ');
		// if (ft_strnstr(line, "F", ft_strlen(line)) != 0)
		// 	state->pos_no = ft_split(line, ' ');
		// if (ft_strnstr(line, "C", ft_strlen(line)) != 0)
		// 	state->pos_no = ft_split(line, ' ');
		if (state->pos_map == -5 && line[0] != '\n' && check_characters(state, line) == 0)
			state->pos_map = i;
		ft_free_string(&line);
		line = get_next_line(fd);
		i++;
	}
	ft_free_string(&line);
	close(fd);
	if (check_identifiers(state) != 0)
	{
		ft_putstr_fd("Error\nNo map found in *.cub file.\n", 1);
			return (-1);
	}
	return (0);
}

static int	parse_map(t_state *state, char **argv)
{
	if (get_map_height(state, argv[1]) == -1)
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

/*	Parsing the *.cub map.

	Identifying the height of the map and the width of each row for memory
	allocation. Parsing the content of the map into state->map[][]. */
int	parsing(t_state *state, int argc, char **argv)
{
	if (get_identifiers(state, argv[1]) != 0)
		return (-1);
	if (parse_map(state, argv) != 0)
		return (-1);
	return (0);
}
