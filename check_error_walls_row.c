#include "cub.h"

/* Checks if map line starts with a wall, loops over empty spaces. */
static int	get_rw_first_wl(t_state *state, int y)
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

/* Checks if map line ends with a wall. */
static int	get_rw_last_wl(t_state *state, int y, char c)
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
	x = save + 1;
	while (x < state->map->map_width)
	{
		if (state->map->map[y][x] != ' ' && state->map->map[y][x] != '-')
			return (-1);
		x++;
	}
	return (save);
}

/* Checks whether each map row starts and ends with a wall ('1'), empty spaces
are ignored. */
int	check_row(t_state *state, int y)
{
	int	i;
	int	rw_first;
	int	rw_last;

	i = 0;
	rw_first = get_rw_first_wl(state, y);
	if (rw_first == -1)
		return (-1);
	rw_last = get_rw_last_wl(state, y, '1');
	if (rw_last == -1 || (rw_last == rw_first && \
		ft_strlen(state->map->map[y]) != 1))
		return (-1);
	return (0);
}
