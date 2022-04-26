/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mu_create_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:39:24 by sachmull          #+#    #+#             */
/*   Updated: 2022/03/14 14:45:12 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx_utility.h>

t_img	mu_new_img(void *mlx, int width, int height)
{
	t_img	img;

	img = (t_img){.width = width, .height = height};
	img.img = mlx_new_image(mlx, width, height);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	return (img);
}
