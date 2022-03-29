#include "cub.h"

/* Transforms rgb values from char to int and checks their range. */
static int	parse_rgb_info(t_state *state, int i, int *k)
{
	int		j;
	char	**temp;

	j = 0;
	temp = ft_split(state->map->colours[i], ',');
	if (temp == NULL)
		return (-1);
	while (temp[j])
	{
		state->map->rgb[*k] = ft_atoi(temp[j++]);
		if (state->map->rgb[*k] < 0 || state->map->rgb[*k] > 255)
		{
			ft_putstr_fd("Error\nRGB value out of range\n", 1);
			return (-1);
		}
		(*k)++;
	}
	ft_free_strarray(&temp);
	return (0);
}

/* Saves the rgb value if correct within struct state. */
static int	get_rgb(t_state *state)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (state->map->colours[i])
	{
		parse_rgb_info(state, i, &k);
		i++;
	}
	return (0);
}

/* Transforms rgb values into one int using bitshifting. */
static void	transform_rgb(t_state *state )
{
	state->ceiling = ((state->map->rgb[0] & 0xff) << 16) + \
		((state->map->rgb[1] & 0xff) << 8) + (state->map->rgb[2] & 0xff);
	state->floor = ((state->map->rgb[3] & 0xff) << 16) + \
		((state->map->rgb[4] & 0xff) << 8) + (state->map->rgb[5] & 0xff);
}

/* Checks for right strlen of path and colour array, right range of RGV values
and a valid path for texture paths. */
int	check_identifiers(t_state *state)
{
	if (ft_arrlen(state->map->path_text) != 4
		|| ft_arrlen(state->map->colours) != 2
		|| state->map->pos_map == -5)
		return (-1);
	if (get_rgb(state) != 0)
		return (-1);
	transform_rgb(state);
	// //HOW TO CHECK FOR VALID PATH TO TEXTURE??? MINILIBX FUNCTION
	//similar to open but minilibx functino
	return (0);
}

/* Checks for a valid texture path. */
// static int	check_identifier_content(char	**string)
// {
// 	int	i;

// 	i = 0;
// 	while (string[i])
// 	{
// 		if (i == 0 && ft_strlen(string[i]) != 2)
// 			return (-1);
// 		if (i == 1 && ft_strncmp(string[i], "/", 1) != 0
// 			&& (ft_strncmp(string[i], ".", 1) != 0))
// 			return (-1);
// 		i++;
// 	}
// 	if (i != 1)
// 		return (-1);
// 	return (0);
// }