/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:18:16 by sachmull          #+#    #+#             */
/*   Updated: 2022/04/01 12:49:55 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>

int	mouse_down(int button, int x, int y, t_state *state)
{
	(void)button;
	(void)y;
	(void)x;
	state->pressed[MOUSE] = 1;
	return (0);
}

int	mouse_up(int button, int x, int y, t_state *state)
{
	(void)button;
	(void)y;
	(void)x;
	state->pressed[MOUSE] = 0;
	return (0);
}

int	mouse_move(int x, int y, t_state *state)
{
	(void)y;
	if (state->pressed[MOUSE])
	{
		if (x > state->mouse_x)
		{
			rotate(state, 1);
			rotate(state, 1);
		}
		else if (x < state->mouse_x)
		{
			rotate(state, -1);
			rotate(state, -1);
		}
	}
	state->mouse_x = x;
	return (0);
}
