/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:51:27 by sachmull          #+#    #+#             */
/*   Updated: 2022/04/07 21:17:37 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>

void	go(t_state *state, t_vec2 dir)
{
	const double	new_x = state->player.pos.x + STEP_SIZE * dir.x;
	const double	new_y = state->player.pos.y + STEP_SIZE * dir.y;

	if (new_x > 0 && new_x < state->map->map_width && new_y > 0
		&& new_y < state->map->map_height
		&& (state->map->map[(int)new_y][(int)new_x] == '0'
		|| state->map->map[(int)new_y][(int)new_x] == 'O'))
	{
		state->player.pos.x = new_x;
		state->player.pos.y = new_y;
	}
}

void	rotate(t_state *state, int dir)
{
	const double	olddirx = state->player.dir.x;
	const double	oldplanex = state->player.plane.x;

	state->player.dir.x = olddirx * cos(dir * ROTATION_SPEED)
		- state->player.dir.y * sin(dir * ROTATION_SPEED);
	state->player.dir.y = olddirx * sin(dir * ROTATION_SPEED)
		+ state->player.dir.y * cos(dir * ROTATION_SPEED);
	state->player.plane.x = oldplanex * cos(dir * ROTATION_SPEED)
		- state->player.plane.y * sin(dir * ROTATION_SPEED);
	state->player.plane.y = oldplanex * sin(dir * ROTATION_SPEED)
		+ state->player.plane.y * cos(dir * ROTATION_SPEED);
}

void	movement(t_state *state)
{
	if (state->pressed[W])
		go(state, state->player.dir);
	if (state->pressed[A])
		go(state, perpendicular_vec2(state->player.dir, CLOCKWISE));
	if (state->pressed[S])
		go(state, s_multiplication(state->player.dir, -1));
	if (state->pressed[D])
		go(state, perpendicular_vec2(state->player.dir, COUNTER_CLOCKWISE));
	if (state->pressed[LEFT])
		rotate(state, -1);
	if (state->pressed[RIGHT])
		rotate(state, 1);
}
