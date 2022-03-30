#include "cub.h"

/* Loops within map over free spaces and detects the first occurence of
a wall. If first character is not a wall, -1 is returned. */
static int	ft_strchr_pos_first(t_state *state, int y)
{
	int	x;

	x = 0;
	while (state->map->map[y][x] == ' ' || state->map->map[y][x] == '\0')
		x++;
	if (state->map->map[y][x] != '1')
		return (-1);
	else
		return (0);
}

/* Saves the last occurence of a wall in map. */
static int	ft_strchr_pos_last(t_state *state, int y, char c)
{
	int	x;
	int	save;

	x = 0;
	save = 0;
	while (x < state->map->map_width)
	{
		if (state->map->map[y][x] == c)
			save = x;
		x++;
	}
	return (save);
}

/* Checks whether each row of map starts with a wall element and
ends with one. */
int	check_row(t_state *state, int y)
{
	int	i;
	int	rw_first;
	int	rw_last;

	i = 0;
	rw_first = ft_strchr_pos_first(state, y);
	if (rw_first == -1)
		return (-1);
	rw_last = ft_strchr_pos_last(state, y, '1');
	if (rw_last == -1 || rw_last == rw_first && \
		ft_strlen(state->map->map[y]) != 1)
		return (-1);
	i = rw_last;
	while (i != state->map->map_width)
	{
		if (state->map->map[y][i] != '1' && state->map->map[y][i] != '\0'
			&& state->map->map[y][i] != ' ')
			return (-1);
		i++;
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
		while (x != state->map->map_width)
		{
			// if (state->map->map[y][x] != '1')
			// 	check_inside_map(state, y, x);
			// if (check_column(state, x) != 0)
			// 	return (-1);
			x++;
		}
		if (check_row(state, y) != 0)
			return (-1);
		y++;
	}
	return (0);
}
