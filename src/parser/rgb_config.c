/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 19:15:26 by khammers          #+#    #+#             */
/*   Updated: 2022/04/09 23:18:19 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

/* Transforms rgb values into one int using bitshifting. */
static void	transform_rgb(t_state *state )
{
	state->map->ceiling = ((state->map->rgb[0] & 0xff) << 16) + \
		((state->map->rgb[1] & 0xff) << 8) + (state->map->rgb[2] & 0xff);
	state->map->floor = ((state->map->rgb[3] & 0xff) << 16) + \
		((state->map->rgb[4] & 0xff) << 8) + (state->map->rgb[5] & 0xff);
}

/* Transforms rgb into int and checks it's valid range. */
static int	parse_rgb_info(t_state *state, char **temp, int j, int k)
{
	state->map->rgb[k] = ft_atoi(temp[j]);
	if (state->map->rgb[k] < 0 || state->map->rgb[k] > 255)
	{
		ft_putstr_fd("Error\nRGB value out of range\n", 1);
		ft_free_strarray(&temp);
		return (-1);
	}
	return (0);
}

static int	check_temp(char **temp)
{
	if (temp == NULL)
	{
		ft_putstr_fd("Error\nSplit failed\n", 1);
		return (-1);
	}
	if (ft_arrlen(temp) != 3)
	{
		ft_putstr_fd("Error\nNo valid RGB input\n", 1);
		ft_free_strarray(&temp);
		return (-1);
	}
	return (0);
}

/* Saves the rgb value if correct within struct state. */
static int	get_rgb(t_state *state)
{
	int		i;
	int		j;
	int		k;
	char	**temp;

	i = 0;
	k = 0;
	temp = NULL;
	while (state->map->colours[i])
	{
		j = 0;
		temp = ft_split(state->map->colours[i], ',');
		if (check_temp(temp) != 0)
			return (-1);
		while (temp[j])
		{
			if (parse_rgb_info(state, temp, j, k) != 0)
				return (-1);
			j++;
			k++;
		}
		ft_free_strarray(&temp);
		i++;
	}
	return (0);
}

int	rgb_config(t_state *state)
{
	if (get_rgb(state) != 0)
		return (-1);
	transform_rgb(state);
	return (0);
}
