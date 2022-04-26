/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:33:45 by sachmull          #+#    #+#             */
/*   Updated: 2022/04/08 15:41:19 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC2_H
# define VEC2_H

typedef enum e_clock_dir {CLOCKWISE, COUNTER_CLOCKWISE}	t_clock_dir;

typedef struct s_vec2
{
	double	x;
	double	y;
}				t_vec2;

t_vec2	perpendicular_vec2(t_vec2 og, t_clock_dir dir);
t_vec2	s_multiplication(t_vec2 vec, double scalar);

#endif
