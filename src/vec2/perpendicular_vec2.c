/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perpendicular_vec2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:51:24 by sachmull          #+#    #+#             */
/*   Updated: 2022/03/30 11:54:44 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vec2.h>

t_vec2	perpendicular_vec2(t_vec2 og, t_clock_dir dir)
{
	if (dir == CLOCKWISE)
		return ((t_vec2){.x = og.y, .y = -og.x});
	return ((t_vec2){.x = -og.y, .y = og.x});
}
