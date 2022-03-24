/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_handling_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:38:17 by khammers          #+#    #+#             */
/*   Updated: 2022/03/24 19:37:51 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	while (y < state->map_height)
	{
		x = 0;
		while (x != state->map_width)
		{
			if (state->map[y][x] != '0' && state->map[y][x] != '1'
				&& state->map[y][x] != 'N' && state->map[y][x] != 'S'
				&& state->map[y][x] != 'E' && state->map[y][x] != 'W'
				&& state->map[y][x] != ' ')
				{
					printf("map: %c\n", state->map[y][x]);
					return (-1);
				}
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
	while (y < state->map_height)
	{
		x = 0;
		while (x != state->map_width)
		{
			if (state->map[y][x] == 'N' || state->map[y][x] == 'S'
				|| state->map[y][x] == 'E' || state->map[y][x] == 'W')
				{
					p_pos++;
					if (p_pos != 1)
						state->map[y][x] = '1';
				}
			x++;
		}
		y++;
	}
	if (p_pos == 0)
		return (-1);
	return (0);
}

int	check_column_wall(t_state *state, int x, int y)
{
	int	j;

	j = 0;
	if (y == state->map_height)
	{
		printf("Last column!\n");
		return (1);
	}
	while ((j + y) != state->map_height)
	{
		if (state->map[y + j][x] == '1')
			return (0);
		j++;

	}
	return (1);
}

int	ft_strchr_pos_last(char *s, char c)
{
	int	i;
	int	save;

	i = 0;
	save = 0;
	while (s[i] != '\0')
	{
		if (s[i] == 'c')
			save = i;
		i++;
	}
	return (save);
}

int	check_row_wall(t_state *state, int x, int y)
{
	int	i;

	i = 0;
	if (ft_strchr_pos_last(state->map[y], '1') == x)
		return (0);
	while ((x + i) != state->map_width)
	{
		if (state->map[y][x + i] == '1')
			return (0);
		i++;
	}
	return (1);
}

static int	check_surrounding_walls(t_state *state)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y != state->map_height)
	{
		x = 0;
		while (x != state->map_width)
		{
			if (state->map[y][x] != '1')
			{
				if (check_column_wall(state, x, y) == 0 && check_row_wall(state, x, y) == 0)
					x++;
				else
				{
					ft_free_strarray(&state->map);
					return (-1);
				}
			}
			else
				x++;
		}
		y++;
	}
	return (0);
}

int	map_error_check(t_state *state)
{
	if (check_forbidden_characters(state) != 0)
	{
		ft_putstr_fd("Error\nInvalid characters in *.cub file.\n", 1);
		return (-1);
	}
	if (check_necessary_characters(state) != 0)
	{
		ft_putstr_fd("Error\nMissing start position in *.cub file.\n", 1);
		return (-1);
	}
	if (check_surrounding_walls(state) != 0)
	{
		ft_putstr_fd("Error\nGamefield must be surrounded by walls.\n", 1);
		return (-1);
	}
	return (0);
}