/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mu_draw_rect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:47:19 by sachmull          #+#    #+#             */
/*   Updated: 2022/03/30 15:56:27 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx_utility.h>

void	mu_draw_rect(t_img *img, t_rect rect, int color)
{
	int	x;
	int	y;

	x = rect.x;
	while (x < rect.x + rect.width)
	{
		y = rect.y;
		while (y < rect.y + rect.height)
		{
			mu_put_pixel(img, x, y, color);
			++y;
		}
		++x;
	}
}
