/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:34:53 by khammers          #+#    #+#             */
/*   Updated: 2022/04/09 22:46:53 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exit.h>

/* Frees memory area allocated to the game's images. */
static void	free_textures(t_state *state)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (state->tex[i])
		{
			mlx_destroy_image(state->mlx, state->tex[i]->img);
			free(state->tex[i]);
			state->tex[i] = NULL;
		}
		i++;
	}
}

/* Frees memory area used to save gamefield in 2D array. */
static void	free_map(t_state *state)
{
	int	y;

	y = 0;
	while (y < state->map->map_height)
	{
		if (state->map->map[y])
		{
			free (state->map->map[y]);
			state->map->map[y] = NULL;
		}
		y++;
	}
	if (state->map->map != NULL)
	{
		free (state->map->map);
		state->map->map = NULL;
	}
}

static void	free_colours(t_state *state)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (state->map->colours[i])
		{
			free(state->map->colours[i]);
			state->map->colours[i] = NULL;
		}
		i++;
	}
	if (state->map->colours)
	{
		free(state->map->colours);
		state->map->colours = NULL;
	}
}

static void	free_path_textures(t_state *state)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (state->map->path_text[i])
		{
			free(state->map->path_text[i]);
			state->map->path_text[i] = NULL;
		}
		i++;
	}
	if (state->map->path_text)
	{
		free(state->map->path_text);
		state->map->path_text = NULL;
	}
}

void	free_state(t_state *state)
{
	free_colours(state);
	free_path_textures(state);
	if (state->map->map)
		free_map(state);
	free_textures(state);
	if (state->map)
	{
		free(state->map);
		state->map = NULL;
	}
}
