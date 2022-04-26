/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:09:50 by khammers          #+#    #+#             */
/*   Updated: 2022/04/09 23:17:54 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

/* Checks if file can be opened with reading permissions. */
static int	check_access(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		ft_putstr_fd("Error\nFile could not be read\n", 1);
		return (-1);
	}
	close (fd);
	return (0);
}

/*	Parsing the *.cub map.

	Identifying the height of the map and the width of each row for memory
	allocation. Parsing the content of the map into state->map[][]. */
int	parsing(t_state *state, char **argv)
{
	if (check_access(argv[1]) != 0)
		return (-1);
	if (parse_identifiers(state, argv[1]) != 0)
		return (-1);
	if (parse_map(state, argv) != 0)
		return (-1);
	if (map_error_check(state) != 0)
		return (-1);
	if (load_textures(state) != 0)
		return (-1);
	return (0);
}
