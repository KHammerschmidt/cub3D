/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_multiplication.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:59:57 by sachmull          #+#    #+#             */
/*   Updated: 2022/03/30 12:01:13 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vec2.h>

t_vec2	s_multiplication(t_vec2 vec, double scalar)
{
	return ((t_vec2){.x = vec.x * scalar, .y = vec.y * scalar});
}
