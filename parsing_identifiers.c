#include "cub.h"

/* Checks if there are any characters found in line which are not map
characters. If so, the start of the map has not bee n found. */
static int	check_characters(t_state *state, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ft_strlen(line) - 1)
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W' && line[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

/* Returns the length of an array. */
int	ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

/* Checks every line for identifiers, cuts newline characters at the end
of string and saves texture path as well as rgb value in 2D arrays. */
static int	get_rgb_spawning(t_state *state, char *line)
{
	char	**token;
	char	*temp;

	temp = NULL;
	token = ft_split(line, ' ');
	if (token == NULL || ft_arrlen(token) != 2)
		return (1);
	temp = ft_strtrim(token[1], "\n");
	if (ft_strnstr(line, "NO", ft_strlen(line)) != 0)
		state->map->path_text[0] = ft_strdup(temp);
	if (ft_strnstr(line, "EA", ft_strlen(line)) != 0)
		state->map->path_text[1] = ft_strdup(temp);
	if (ft_strnstr(line, "SO", ft_strlen(line)) != 0)
		state->map->path_text[2] = ft_strdup(temp);
	if (ft_strnstr(line, "WE", ft_strlen(line)) != 0)
		state->map->path_text[3] = ft_strdup(temp);
	if (ft_strnstr(line, "C", ft_strlen(line)) != 0)
		state->map->colours[0] = ft_strdup(temp);
	if (ft_strnstr(line, "F", ft_strlen(line)) != 0)
		state->map->colours[1] = ft_strdup(temp);
	ft_free_strarray(&token);
	ft_free_string(&temp);
	return (0);
}

/* Reads *.cub file and checks for spawning and colour identifiers as well
as the start of the map. */
int	get_identifiers(t_state *state, char *file)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = 0;
	if (open_cub_file(file, &fd) == -1)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		get_rgb_spawning(state, line);
		if (state->map->pos_map == -5 && line[0] != '\n' \
			&& check_characters(state, line) == 0)
			state->map->pos_map = i;
		ft_free_string(&line);
		i++;
	}
	ft_free_string(&line);
	close(fd);
	return (0);
}

int	parse_identifiers(t_state *state, char *file)
{
	if (get_identifiers(state, file) != 0)
		return (-1);
	if (check_identifiers(state) != 0)
		return (-1);
	return (0);
}