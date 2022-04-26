/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:08:31 by khammers          #+#    #+#             */
/*   Updated: 2022/04/08 18:05:48 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static int	check_file_format(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (file[len - 1] != 'b' || file[len - 2] != 'u' || \
		file[len - 3] != 'c' || file[len - 4] != '.')
		return (-1);
	return (0);
}

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
	if (check_file_format(argv[1]) != 0)
	{
		ft_putstr_fd("Error\nNo valid map in *.cub format.\n", 1);
		return (-1);
	}
	return (0);
}
