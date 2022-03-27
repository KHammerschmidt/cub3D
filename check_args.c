#include "cub.h"

/* Check for 2 command line args, the last one of *.cub format. Return 0 if
input is correct, print an error message and return -1 if not. */
int	check_args(int argc, char **argv)
{
	char	*map_format;

	map_format = ".cub";
	if (argv[1] == NULL || argc != 2)
	{
		ft_putstr_fd("Error\nNo valid map.\n", 1);
		return (-1);
	}
	if (!(ft_strncmp((argv[1] - 4), map_format, 4)))
	{
		ft_putstr_fd("Error\nNo valid map in *.cub format.\n", 1);
		return (-1);
	}
	return (0);
}
