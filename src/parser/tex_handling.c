/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:47:23 by khammers          #+#    #+#             */
/*   Updated: 2022/04/07 18:20:07 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

/* Allocates memory for each texture (NO, SO, EA, WE)  */
int	load_textures(t_state *state)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		state->tex[i] = NULL;
		state->tex[i] = mu_new_xpm_img(state->mlx, state->map->path_text[i]);
		if (state->tex[i] == NULL)
		{
			ft_putstr_fd("Error\nXPM file could not be put to image\n", 1);
			return (-1);
		}
		i++;
	}
	return (0);
}
