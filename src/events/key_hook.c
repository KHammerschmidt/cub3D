/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:01:27 by sachmull          #+#    #+#             */
/*   Updated: 2022/04/09 18:13:35 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>

void	door(t_state *state)
{
	const int	y = state->player.pos.y + state->player.dir.y;
	const int	x = state->player.pos.x + state->player.dir.x;

	if ((int)state->player.pos.x != x || (int)state->player.pos.y != y)
	{
		if (state->map->map[y][x] == 'D')
			state->map->map[y][x] = 'O';
		else if (state->map->map[y][x] == 'O')
			state->map->map[y][x] = 'D';
	}
}

int	key_down(int kc, t_state *state)
{
	if (kc == LEFT_KC)
		state->pressed[LEFT] = 1;
	else if (kc == RIGHT_KC)
		state->pressed[RIGHT] = 1;
	else if (kc == W_KC)
		state->pressed[W] = 1;
	else if (kc == A_KC)
		state->pressed[A] = 1;
	else if (kc == S_KC)
		state->pressed[S] = 1;
	else if (kc == D_KC)
		state->pressed[D] = 1;
	else if (kc == ESC_KC)
		exit_cub(state);
	else if (kc == F_KC)
		door(state);
	return (0);
}

int	key_up(int kc, t_state *state)
{
	if (kc == LEFT_KC)
		state->pressed[LEFT] = 0;
	else if (kc == RIGHT_KC)
		state->pressed[RIGHT] = 0;
	else if (kc == W_KC)
		state->pressed[W] = 0;
	else if (kc == A_KC)
		state->pressed[A] = 0;
	else if (kc == S_KC)
		state->pressed[S] = 0;
	else if (kc == D_KC)
		state->pressed[D] = 0;
	else if (kc == ESC_KC)
		exit_cub(state);
	return (0);
}
