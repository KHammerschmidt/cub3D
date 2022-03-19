#include "cub.h"

int	main(int argc, char *argv[])
{
	t_state	state;

	state = (t_state){0};
	ft_memset(&state, 0, sizeof(t_state));
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
