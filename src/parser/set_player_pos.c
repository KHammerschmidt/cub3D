/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:16:03 by sachmull          #+#    #+#             */
/*   Updated: 2022/04/05 16:08:10 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static void	set_val(t_state *state, int x, int y, char dir)
{
	state->player.pos = (t_vec2){.x = (double)x + 0.5, .y = (double)y + 0.5};
	if (dir == 'N')
		state->player.dir = (t_vec2){.x = 0.001, .y = -1.001};
	else if (dir == 'E')
		state->player.dir = (t_vec2){.x = 1.001, .y = 0.001};
	else if (dir == 'S')
		state->player.dir = (t_vec2){.x = 0.001, .y = 1.001};
	else
		state->player.dir = (t_vec2){.x = -1.001, .y = 0.001};
	state->player.plane = perpendicular_vec2(state->player.dir,
			COUNTER_CLOCKWISE);
	state->map->map[y][x] = '0';
}

void	set_player_pos(t_state *state)
{
	int	y;
	int	x;

	y = 0;
	while (y < state->map->map_height)
	{
		x = 0;
		while (x < state->map->map_width)
		{
			if (state->map->map[y][x] == 'N')
				set_val(state, x, y, 'N');
			else if (state->map->map[y][x] == 'E')
				set_val(state, x, y, 'E');
			else if (state->map->map[y][x] == 'S')
				set_val(state, x, y, 'S');
			else if (state->map->map[y][x] == 'W')
				set_val(state, x, y, 'W');
			++x;
		}
		++y;
	}
}
