#include "cub.h"

/*
 each type of information from an element can be separated by one or more spaces
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
		while (x < state->map->map_width)
		{
			if (state->map->map[y][x] != '0' && state->map->map[y][x] != '1'
				&& state->map->map[y][x] != 'N' && state->map->map[y][x] != 'S'
				&& state->map->map[y][x] != 'E' && state->map->map[y][x] != 'W'
				&& state->map->map[y][x] != ' ' && state->map->map[y][x] != '-' \
				&& state->map->map[y][x] != '\0')
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
		while (x < state->map->map_width)
		{
			if (state->map->map[y][x] == 'N' || state->map->map[y][x] == 'S'
				|| state->map->map[y][x] == 'E' || state->map->map[y][x] == 'W')
					p_pos++;
			x++;
		}
		y++;
	}
	if (p_pos == 0 || p_pos > 1)
		return (-1);
	return (0);
}

static int	check_space(t_state *state, int y, int x, char c)
{

	if (c == '0')
	{
		if (state->map->map[y + 1][x] == ' ' || state->map->map[y - 1][x] == ' '
			|| state->map->map[y][x + 1] == ' ' || state->map->map[y][x - 1] == ' ')
				return (-1);
	}
	return (0);
}


/* Checks whether all 0 or ' ' are framed by walls. */
int	check_walls(t_state *state)
{
	int	x;
	int	y;

	y = 0;
	while (y != state->map->map_height)
	{
		x = 0;
		while (x < state->map->map_width)
		{
			if (state->map->map[y][x] != '1' &&
				check_space(state, y, x, state->map->map[y][x]) != 0)
				return (-1);
			if (check_column(state, x) != 0)
				return (-1);
			x++;
		}
		if (check_row(state, y) != 0)
			return (-1);
		y++;
	}
	return (0);
}

/* Calls the different error checks of input and  map specifics
and prints an error message in case it fails. */
int	map_error_check(t_state *state)
{
	print_map(state);
	if (check_identifiers(state) != 0)
	{
		ft_putstr_fd("Error\nNo valid information in *.cub file\n", 1);
		return (-1);
	}
	if (check_forbidden_characters(state) != 0)
	{
		ft_putstr_fd("Error\nInvalid characters in *.cub file.\n", 1);
		return (-1);
	}
	if (check_necessary_characters(state) != 0)
	{
		ft_putstr_fd("Error\nNo valid player start position.\n", 1);
		return (-1);
	}
	if (check_walls(state) == -1)
	{
		ft_putstr_fd("Error\nGamefield must be surrounded by walls.\n", 1);
		return (-1);
	}
	return (0);
}
