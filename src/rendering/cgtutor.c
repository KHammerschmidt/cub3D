/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cgtutor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:29:40 by sachmull          #+#    #+#             */
/*   Updated: 2022/04/26 19:18:44 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rendering.h>

void	init_dda_data(t_dda *d, t_state *state, int column)
{
	d->camerax = 2 * column / (double)WIN_W - 1;
	d->raydirx = state->player.dir.x + state->player.plane.x * d->camerax;
	d->raydiry = state->player.dir.y + state->player.plane.y * d->camerax;
	d->mapx = (int)state->player.pos.x;
	d->mapy = (int)state->player.pos.y;
	d->deltadistx = 1e30;
	if (d->raydirx != 0)
		d->deltadistx = fabs(1 / d->raydirx);
	d->deltadisty = 1e30;
	if (d->raydiry != 0)
		d->deltadisty = fabs(1 / d->raydiry);
	d->stepx = 1;
	if (d->raydirx < 0)
		d->stepx = -1;
	d->stepy = 1;
	if (d->raydiry < 0)
		d->stepy = -1;
	d->sidedistx = (d->mapx + 1.0 - state->player.pos.x) * d->deltadistx;
	if (d->raydirx < 0)
		d->sidedistx = (state->player.pos.x - d->mapx) * d->deltadistx;
	d->sidedisty = (d->mapy + 1.0 - state->player.pos.y) * d->deltadisty;
	if (d->raydiry < 0)
		d->sidedisty = (state->player.pos.y - d->mapy) * d->deltadisty;
}

void	dda(t_dda *data, t_state *state)
{
	while (state->map->map[data->mapy][data->mapx] == '0'
		|| state->map->map[data->mapy][data->mapx] == 'O')
	{
		if (data->sidedistx < data->sidedisty)
		{
			data->sidedistx += data->deltadistx;
			data->mapx += data->stepx;
			data->side = 0;
			data->perpwalldist = (data->sidedistx - data->deltadistx);
			data->texture = *state->tex[3];
			if (data->raydirx > 0)
				data->texture = *state->tex[1];
		}
		else
		{
			data->sidedisty += data->deltadisty;
			data->mapy += data->stepy;
			data->side = 1;
			data->perpwalldist = (data->sidedisty - data->deltadisty);
			data->texture = *state->tex[0];
			if (data->raydiry > 0)
				data->texture = *state->tex[2];
		}
	}
}

void	get_draw_data(t_dda *data, t_state *state)
{
	data->lineheight = (int)((double)WIN_H / data->perpwalldist);
	data->drawstart = -data->lineheight / 2 + WIN_H / 2;
	if (data->drawstart < 0)
		data->drawstart = 0;
	data->drawend = data->lineheight / 2 + WIN_H / 2;
	if (data->drawend >= WIN_H)
		data->drawend = WIN_H - 1;
	if (data->side == 0)
		data->wallx = state->player.pos.y + data->perpwalldist * data->raydiry;
	else
		data->wallx = state->player.pos.x + data->perpwalldist * data->raydirx;
	data->wallx -= floor(data->wallx);
	data->texx = (int)(data->wallx * (double)data->texture.width);
	if (data->side == 0 && data->raydirx > 0)
			data->texx = data->texture.width - data->texx - 1;
	if (data->side == 1 && data->raydiry < 0)
			data->texx = data->texture.width - data->texx - 1;
	data->step = 1.0 * data->texture.height / data->lineheight;
	data->texpos = (data->drawstart - WIN_H / 2 + data->lineheight / 2) \
		* data->step;
}

void	draw(t_dda *data, t_state *state, int column)
{
	int				y;
	int				texy;
	unsigned int	color;

	y = data->drawstart;
	while (y <= data->drawend)
	{
		texy = (int)data->texpos & (data->texture.height - 1);
		data->texpos += data->step;
		color = ((unsigned int *)data->texture.addr) \
			[data->texture.width * texy + data->texx];
		if (state->map->map[data->mapy][data->mapx] == 'D')
			color = mu_new_trgb(0, 92, 79, 44);
		mu_put_pixel(&state->img, column, y, color);
		++y;
	}
	mu_draw_rect(&state->img, \
		mu_new_rect(column, 0, 1, data->drawstart), state->map->ceiling);
	mu_draw_rect(&state->img, mu_new_rect(column, data->drawend + 1, 1, \
		WIN_H - data->drawend), state->map->floor);
}

void	cgtutor(t_state *state)
{
	t_dda		data;
	int			column;

	column = 0;
	while (column < WIN_W)
	{
		init_dda_data(&data, state, column);
		dda(&data, state);
		get_draw_data(&data, state);
		draw(&data, state, column);
		++column;
	}
	mlx_put_image_to_window(state->mlx, state->win, state->img.img, 0, 0);
}
