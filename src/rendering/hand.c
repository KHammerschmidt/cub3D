/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 22:19:05 by sachmull          #+#    #+#             */
/*   Updated: 2022/04/26 19:18:40 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rendering.h>

#define HAND_HEIGHT 300
#define HAND_WIDTH 300

void	draw_hand_pixel(t_state *state, t_vec2 *tex, t_vec2 *coor)
{
	unsigned int	color;
	const int		i = (state->counter % 40) / 10;

	color = ((unsigned int *)state->hand[i]->addr) \
		[(int)(state->hand[i]->width * (int)tex->y + (int)tex->x)];
	mu_put_pixel(&state->img, coor->x, coor->y, color);
	mu_put_pixel(&state->img, WIN_W - coor->x, coor->y, color);
}

void	hand(t_state *state)
{
	t_vec2			tex;
	t_vec2			coor;
	const int		i = (state->counter % 40) / 10;
	const t_vec2	step = (t_vec2){.x = 1.0 * state->hand[i]->width / \
		HAND_WIDTH, .y = 1.0 * state->hand[i]->height / HAND_HEIGHT};
	const t_vec2	start = (t_vec2){.x = WIN_W / 2 - HAND_WIDTH, \
		.y = WIN_H - HAND_HEIGHT - WIN_H / 20};

	tex = (t_vec2){.x = 0, .y = 0};
	coor = (t_vec2){.x = start.x, .y = start.y};
	while (coor.y < HAND_HEIGHT + start.y)
	{
		tex.x = 0;
		coor.x = start.x;
		while (coor.x < HAND_WIDTH + start.x)
		{
			draw_hand_pixel(state, &tex, &coor);
			tex.x += step.x;
			coor.x += 1;
		}
		coor.y += 1;
		tex.y += step.y;
	}
	mlx_put_image_to_window(state->mlx, state->win, state->img.img, 0, 0);
}
