/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:09:45 by khammers          #+#    #+#             */
/*   Updated: 2022/04/08 21:54:27 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

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
int	get_to_pos(int pos, int fd)
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
	ft_free_string(&line);
	return (0);
}

/* Opens file and iterates through file until map position. */
int	open_file_get_to_pos(t_state *state, char *file)
{
	int	fd;

	fd = 0;
	if (open_cub_file(file, &fd) == -1)
		return (-1);
	get_to_pos(state->map->pos_map, fd);
	return (fd);
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
