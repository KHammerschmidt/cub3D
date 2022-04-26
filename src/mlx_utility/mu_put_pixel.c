/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mu_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:51:32 by sachmull          #+#    #+#             */
/*   Updated: 2022/04/01 17:30:20 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx_utility.h>

int	mu_put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < img->width && y >= 0 && y < img->height)
	{
		dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
		return (1);
	}
	return (0);
}
