#include "cub.h"

static void	init_struct(t_state *state)
{
	// ft_memset(&state, 0, sizeof(t_state));
	// state->map_char = "01NSEW";
	state->map_char[0] = '0';
	state->map_char[1] = '1';
	state->map_char[2] = 'N';
	state->map_char[3] = 'S';
	state->map_char[4] = 'E';
	state->map_char[5] = 'W';
	state->map_char[6] = ' ';
	state->map_char[7] = '\0';

	state->pos_no = NULL;
	state->pos_so = NULL;
	state->pos_we = NULL;
	state->pos_ea = NULL;
}

int	main(int argc, char *argv[])
{
	t_state	state;

	state = (t_state){0};
	init_struct(&state);
	if (input_verification(argc, argv) == -1)
		return (1);
	if (parsing(&state, argc, argv) == -1)
		return (1);
	if (map_error_check(&state) != 0)
		return (1);
	print_map(&state);
	printf("Everything goes to plan!\n");
	return (0);
}
