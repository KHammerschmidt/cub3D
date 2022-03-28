#include "cub.h"

/* Checks for a valid texture path. */
static int	check_identifier_content(char	**string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (i == 0 && ft_strlen(string[i]) != 2)
			return (-1);
		if (i == 1 && ft_strncmp(string[i], "/", 1) != 0 && (ft_strncmp(string[i], ".", 1) != 0))
			return (-1);
		i++;
	}
	if (i != 1)
		return (-1);
	return (0);
}

static int	convert_rgb(t_state *state, int *rgb)
{
	int	i;

	i = 0;
	while (rgb[i] != -5)
	{
		printf("ABC     ");
		i++;
	}
	printf("\n");
	return (0);
}

static int	check_rgb(t_state *state, int index)
{
	int		i;
	int		j;
	int		k;
	char	**temp;
	char	*save;

	i = 0;
	j = 0;
	k = 0;
	while (state->map->colours[i])
	{
		save = ft_strtrim(state->map->colours[i], "\n");
		if (save == NULL)
			return (-1);
		temp = ft_split(save, ',');
		while (temp[j])
		{
			state->map->rgb[k] = ft_atoi(temp[j]);
			if (state->map->rgb[k] < 0 || state->map->rgb[k] > 255)
			{
				ft_putstr_fd("Error\nRGB value out of range\n", 1);
				return (-1);
			}
			j++;
			k++;
		}
		i++;
	}
	return (0);
}

static void	transform_rgb(t_state *state )
{
	//bitshifting
	state->ceiling = (state->map->rgb[0] << 16) + (state->map->rgb[1] << 8) + (state->map->rgb[2] << 2);
	state->floor = (state->map->rgb[3] << 16) + (state->map->rgb[4] << 8) + (state->map->rgb[5] << 2);
	printf("ceiling: %d    floor: %d\n", state->ceiling, state->floor);
}

/* Checks for right strlen of path and colour array, right range of RGV values
and a valid path for texture paths. */
int	check_identifiers(t_state *state)
{
	if (ft_arrlen(state->map->path_text) != 4 || ft_arrlen(state->map->colours) != 2
		|| state->map->pos_map == -5)
		return (-1);
	if (check_rgb(state, 0) != 0 || check_rgb(state, 1) != 0)
		return (-1);
	transform_rgb(state);
	// //HOW TO CHECK FOR VALID PATH TO TEXTURE??? MINILIBX FUNCTION
	return (0);
}
