/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:23:08 by sachmull          #+#    #+#             */
/*   Updated: 2022/04/08 15:53:53 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include <raycaster.h>
# include <vec2.h>

typedef struct s_state	t_state;

typedef struct s_dda
{
	t_img			texture;
	double			camerax;
	double			raydirx;
	double			raydiry;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
	double			wallx;
	int				texx;
	double			step;
	double			texpos;
	int				texy;
	unsigned int	color;
}				t_dda;

void	cgtutor(t_state *state);
void	draw_minimap(t_state *state);
void	hand(t_state *state);

#endif
