/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utility.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:36:41 by sachmull          #+#    #+#             */
/*   Updated: 2022/04/01 13:31:12 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILITY_H
# define MLX_UTILITY_H

# include <stdio.h>
# include <mlx.h>
# include <libft.h>

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_rectangle
{
	int	x;
	int	y;
	int	width;
	int	height;
}				t_rect;

t_img	mu_new_img(void *mlx, int width, int height);
t_rect	mu_new_rect(int x, int y, int width, int height);
int		mu_new_trgb(int t, int r, int g, int b);
void	mu_draw_rect(t_img *img, t_rect rect, int color);
int		mu_put_pixel(t_img *img, int x, int y, int color);
t_img	*mu_new_xpm_img(void *mlx_ptr, char *filepath);

#endif
