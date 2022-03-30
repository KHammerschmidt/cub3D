#include "cub.h"

/*
 map must be closed/surrounded by walls, if not return error

 except for map content, each type of element can be separated by one or more empty lines
 except for map content which has to be the last, each type of element can be set
 in any order in the file except for the map,
 each type of information from an element can be separated by one or more spaces
 the map must be parsed as it looks in the file, Spaces are valid part of the map and are up to you to handle.

 each element (except map) firsts information is the type identifier (composed by one or two characters, followed
 by all specific informations for each object in a strict order such as identifier:
 NO, path to north texture---> NO ./path_to_north_texture
 SO
 WE
 EA East texture

 Floor: identifier F, RGB colors in range [0.255]
 F 220,100,0

 Ceiling colour:
 C 255,30,0
 identifier C, R,G,B color in range 0,255,255

 if any misconfiguration is found in the file, the program must exit properly and return
  "Error\n followed by explicit error message"
 */

/* Checks for forbidden characters in *.cub file except 0,1,N,W,S,E,' '. */
static int	check_forbidden_characters(t_state *state)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < state->map->map_height)
	{
		x = 0;
		while (x != state->map->map_width)
		{
			if (state->map->map[y][x] != '0' && state->map->map[y][x] != '1'
				&& state->map->map[y][x] != 'N' && state->map->map[y][x] != 'S'
				&& state->map->map[y][x] != 'E' && state->map->map[y][x] != 'W'
				&& state->map->map[y][x] != ' ' && state->map->map[y][x] != '\0')
					return (-1);
			x++;
		}
		y++;
	}
	return (0);
}

/* Checks for a player position in *.cub map. If multiple player positions
are found, they are overwritten with walls, except the first one. */
static int	check_necessary_characters(t_state *state)
{
	int		x;
	int		y;
	int		p_pos;

	x = 0;
	y = 0;
	p_pos = 0;
	while (y < state->map->map_height)
	{
		x = 0;
		while (x != state->map->map_width)
		{
			if (state->map->map[y][x] == 'N' || state->map->map[y][x] == 'S'
				|| state->map->map[y][x] == 'E' || state->map->map[y][x] == 'W')
				{
					p_pos++;
					if (p_pos != 1)
					{
						state->map->map[y][x] = '1';
						// ft_free_all(state);
						// ft_putstr_fd("Error\nMultiple player in map\n", 1);
						// return (-1);
					}
				}
			x++;
		}
		y++;
	}
	if (p_pos == 0)
		return (-1);
	return (0);
}

// int	check_column_wall(t_state *state, int x, int y)
// {
// 	int	j;

// 	j = 0;
// 	if (y == state->map->map_height)
// 	{
// 		printf("Last column!\n");
// 		return (1);
// 	}
// 	while ((j + y) != state->map->map_height)
// 	{
// 		if (state->map->map[y + j][x] == '1')
// 			return (0);
// 		j++;

// 	}
// 	return (1);
// }

int	get_cln_wall_first(t_state *state, int x)
{
	int	y;

	y = 0;
	while (y != state->map->map_height)
	{
		while (state->map->map[y][x] != '1')
			y++;
		if (state->map->map[y][x] == '1')
			return (0);
	}
	if (y == state->map->map_height)
		return (-1);
	return (0);
}

int	check_column(t_state *state, int x)
{
	int	cl_first;
	int	cl_last;

	cl_first = get_cln_wall_first(state, x);
	if (cl_first == -1)
		return (-1);
	printf("cl_first: %d\n", cl_first);
	// cl_last = get_cln_wall_last(state, x);
	// if (cl_last == -1 || cl_last == cl_first && state->map->map_height != 1)
	// 	return (-1);
	return (0);
}

/* Calls the different error checks of input and  map specifics
and prints an error message in case it fails. */
int	map_error_check(t_state *state)
{
	// if (check_identifiers(state) != 0)
	// {
	// 	ft_putstr_fd("Error\nNo valid information in *.cub file\n", 1);
	// 	return (-1);
	// }
	// if (check_forbidden_characters(state) != 0)
	// {
	// 	ft_putstr_fd("Error\nInvalid characters in *.cub file.\n", 1);
	// 	return (-1);
	// }
	// if (check_necessary_characters(state) != 0)
	// {
	// 	ft_putstr_fd("Error\nMissing start position in *.cub file.\n", 1);
	// 	return (-1);
	// }
	if (check_walls(state) != 0)
	{
		ft_putstr_fd("Error\nGamefield must be surrounded by walls.\n", 1);
		return (-1);
	}
	// 	if (check_inner_map(state, x, y) != 0)
	// {
	// 	ft_free_strarray(&state->map->map);
	// 	return (-1);
	// }
	// if (state->map->map[y][x] == '0')
	// 	check_surroundings(state, y, x)
	return (0);
}





// static int	check_surrounding_walls(t_state *state)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y != state->map->map_height)
// 	{
// 		x = 0;
// 		while (x != state->map->map_width)
// 		{
// 			if (state->map->map[y][x] != '1')
// 			{
// 				if (check_column_wall(state, x, y) == 0 && check_row_wall(state, x, y) == 0)
// 				{
// 					printf("[%d][%d]\n", y, x);
// 					x++;
// 				}
// 				else
// 				{
// 					printf("The end: [%d][%d]\n", y, x);
// 					// ft_free_strarray(&state->map->map);
// 					return (-1);
// 				}
// 			}
// 			else
// 				x++;
// 		}
// 		y++;
// 	}
// 	return (0);
// }