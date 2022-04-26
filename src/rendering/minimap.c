/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:12:58 by sachmull          #+#    #+#             */
/*   Updated: 2022/04/26 19:18:36 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rendering.h>

int	get_color(t_state *state)
{
	if (state->map->ceiling == state->map->floor)
	{
		if (state->map->rgb[2] > 50)
			return (state->map->ceiling - 50);
		else
			return (state->map->ceiling + 50);
	}
	return (state->map->floor);
}

void	draw_minimap(t_state *state)
{
	t_vec2			coor;
	const t_vec2	scale = (t_vec2){.x = (WIN_W / 5) / \
		state->map->map_width, .y = (WIN_H / 5) / state->map->map_height};

	coor.y = 0;
	while (coor.y < state->map->map_height)
	{
		coor.x = 0;
		while (coor.x < state->map->map_width)
		{
			if (state->map->map[(int)coor.y][(int)coor.x] == '1')
				mu_draw_rect(&state->img, mu_new_rect(coor.x * scale.x, \
				coor.y * scale.y, scale.x, scale.y), get_color(state));
			else if (state->map->map[(int)coor.y][(int)coor.x] == 'D'
				|| state->map->map[(int)coor.y][(int)coor.x] == 'O')
				mu_draw_rect(&state->img, mu_new_rect(coor.x * scale.x, coor.y \
				* scale.y, scale.x, scale.y), mu_new_trgb(0, 92, 79, 44));
			++coor.x;
		}
		++coor.y;
	}
	mu_draw_rect(&state->img, mu_new_rect(state->player.pos.x * scale.x,
			state->player.pos.y * scale.y, (double)scale.x / 1.5,
			(double)scale.y / 2.5), get_color(state));
	mlx_put_image_to_window(state->mlx, state->win, state->img.img, 0, 0);
}
