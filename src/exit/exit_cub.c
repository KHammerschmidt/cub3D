/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:24:21 by sachmull          #+#    #+#             */
/*   Updated: 2022/04/26 19:12:46 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exit.h>

void	free_mlx(t_state *state)
{
	mlx_destroy_image(state->mlx, state->img.img);
	mlx_destroy_window(state->mlx, state->win);
}

void	free_hand(t_state *state)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (state->hand[i])
			mlx_destroy_image(state->mlx, state->hand[i]->img);
		free(state->hand[i]);
		++i;
	}
}

int	exit_cub(t_state *state)
{
	free_state(state);
	free_hand(state);
	free_mlx(state);
	exit(0);
}
