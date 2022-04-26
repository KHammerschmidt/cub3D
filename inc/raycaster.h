/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:25:35 by sachmull          #+#    #+#             */
/*   Updated: 2022/04/08 15:41:45 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
# define RAYCASTER_H

# include <mlx.h>
# include <stdlib.h>
# include <mlx_utility.h>
# include <libft.h>
# include <events.h>
# include <rendering.h>
# include <math.h>
# include <vec2.h>
# include <parser.h>

# define PI 3.14159265359
# define WIN_W 2048
# define WIN_H 1024

typedef struct s_player
{
	t_vec2	pos;
	t_vec2	dir;
	t_vec2	plane;
}				t_player;

typedef struct s_tex
{
	void	*tex;
	int		width;
	int		height;
}				t_tex;

typedef enum e_keys {W, A, S, D, LEFT, RIGHT, ESC, MOUSE, KEY_COUNT}	t_keys;

typedef struct s_map	t_map;

typedef struct s_state
{
	void			*mlx;
	void			*win;
	t_img			img;
	int				mouse_x;
	t_player		player;
	t_keys			pressed[KEY_COUNT];
	t_img			*hand[4];
	unsigned int	counter;

	t_map			*map;
	int				ceiling;
	int				floor;
	t_img			*tex[4];
}				t_state;

#endif
