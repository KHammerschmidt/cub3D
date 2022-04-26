/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:49:42 by sachmull          #+#    #+#             */
/*   Updated: 2022/04/08 15:36:59 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>

int	loop_hook(t_state *state)
{
	movement(state);
	cgtutor(state);
	draw_minimap(state);
	hand(state);
	++state->counter;
	return (0);
}
