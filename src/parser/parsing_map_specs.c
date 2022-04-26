/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_specs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:09:41 by khammers          #+#    #+#             */
/*   Updated: 2022/04/09 18:18:37 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static void	get_len(t_state *state, char *line, int y)
{
	int	len;

	len = ft_strlen(line);
	if (len > state->map->map_width && y == (state->map->map_height - 1))
		state->map->map_width = len;
	else if (len > state->map->map_width)
		state->map->map_width = len - 1;
}

/* Reads every line with gnl to identify the longest line in *.cub file. */
int	get_max_width(t_state *state, char *file)
{
	int		y;
	int		fd;
	char	*line;

	y = 0;
	line = NULL;
	if (open_cub_file(file, &fd) == -1)
		return (-1);
	get_to_pos(state->map->pos_map, fd);
	while (y < state->map->map_height)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		get_len(state, line, y);
		ft_free_string(&line);
		y++;
	}
	ft_free_string(&line);
	close(fd);
	return (0);
}

static int	check_empty_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line != NULL && ft_isinstring(line, '1') == 0)
	{
		ft_putstr_fd("Error\nNo valid map content\n", 1);
		ft_free_string(&line);
		close(fd);
		return (-1);
	}
	ft_free_string(&line);
	return (0);
}

/* Opens the file and reads every line calling gnl to count the map height.
After gnl returns NULL once it is checked for an empty line when specifying
the map. */
int	get_map_height(t_state *state, char *file)
{
	int		fd;
	int		i;
	int		len;
	char	*line;

	i = 0;
	len = 0;
	line = NULL;
	fd = open_file_get_to_pos(state, file);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if ((ft_strchr(line, '1') == NULL && ft_isalpha(line[0]) == 0))
			break ;
		state->map->map_height++;
		ft_free_string(&line);
		line = get_next_line(fd);
	}
	ft_free_string(&line);
	if (check_empty_line(fd) != 0)
		return (-1);
	close(fd);
	return (0);
}
