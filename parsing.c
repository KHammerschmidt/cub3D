#include "cub.h"

/*	Parsing the *.cub map.

	Identifying the height of the map and the width of each row for memory
	allocation. Parsing the content of the map into state->map[][]. */
int	parsing(t_state *state, int argc, char **argv)
{
	if (get_identifiers(state, argv[1]) == -1)
		return (-1);
	if (parse_map(state, argv) != 0)
		return (-1);
	if (map_error_check(state) != 0)
		return (-1);
	return (0);
}
