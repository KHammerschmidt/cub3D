/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mu_create_rect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:43:19 by sachmull          #+#    #+#             */
/*   Updated: 2022/03/14 14:44:51 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx_utility.h>

t_rect	mu_new_rect(int x, int y, int width, int height)
{
	return ((t_rect){.x = x, .y = y, .width = width, .height = height});
}
