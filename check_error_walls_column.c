/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_walls_column.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:45:14 by khammers          #+#    #+#             */
/*   Updated: 2022/03/30 18:26:29 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/* Checks if a column starts with a wall, loops over empty spaces. */
static int	get_cln_first_wl(t_state *state, int x)
{
	int	y;

	y = 0;
	while ((state->map->map[y][x] == ' ' || state->map->map[y][x] == '-')
		&& y < state->map->map_height - 1)
		y++;
	if (state->map->map[y][x] != '1')
	{
		y = 0;
		while (state->map->map[y][x])
		{
			if (state->map->map[y][x] == ' ' && y < state->map->map_height)
			{
				printf("HERRE\n");
				return (0);
			}
			y++;
		}
		// return (-1);
	}
	return (0);
}

/* Checks if a column ends with a wall. */
static int	get_cln_last_wl(t_state *state, int x)
{
	int	y;
	int	save;

	y = 0;
	save = 0;
	while (y < state->map->map_height)
	{
		if (state->map->map[y][x] == '1')
			save = y;
		y++;
	}
	y = save + 1;
	while (y < state->map->map_height)
	{
		if (state->map->map[y][x] != ' ' && state->map->map[y][x] != '\0' && state->map->map[y][x] != '-')
			return (-1);
		y++;
	}
	return (save);
}

static int ft_col_height(t_state *state, int x)
{
	int	counter;
	int	y;

	y = 0;
	counter = 0;
	while (y < state->map->map_height)
	{
		if (state->map->map[y][x] == '1' && state->map->map[y][x] == '0' && state->map->map[y][x] == ' ' &&
		state->map->map[y][x] == '-')
			counter++;
		y++;
	}
	return (counter);
}

/* Checks whether each column in map starts and ends with a wall ('1'),
empty spaces are ignored. */
int	check_column(t_state *state, int x)
{
	int	cl_first;
	int	cl_last;

	cl_first = get_cln_first_wl(state, x);
	if (cl_first == -1)
		return (-1);
	cl_last = get_cln_last_wl(state, x);
	if ((cl_last == -1 || cl_last == cl_first) && ft_col_height(state, x) != 1)
		return (-1);
	return (0);
}
