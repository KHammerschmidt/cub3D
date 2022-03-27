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

		i++;
	}
}

/* Checks if RGB values are valid. */
static int	check_valid_rgb(t_state *state)
{
	int		i;
	int		j;
	int		*rgb;
	char	**temp;
	char	*save;

	i = 0;
	j = 0;
	while (i < 2)
	{
		save = ft_strtrim(state->map->colours[i]);		//cut out newline
		temp = ft_split(save, ',');						//split by comma
		if (!temp)
			return (-1);
		while (temp[i])
		{
			save = ft_strtrim(temp[i], "\n");
			rgb[j] = ft_atoi(save);
			if (rgb[j] < 0 || rgb[j] > 255)
			{
				ft_putstr_fd("Error\nRGB value out of range\n", 1);
				return (-1);
			}
			rgb[i] = -5;
			if (i == 0)
				state->map->ceiling = convert_rgb(state, rgb);
			ft_free_string(&save);
			i++;
			j++;
		}
		if (i == 1)
			state->map->floor = convert_rgb(rgb[i]);
		printf("%d %d %d\n", rgb[0], rgb[1], rgb[2]);
		ft_free_strarray(&temp);
	}
	// rgb[i] = 0;
	return (0);
}

/* Checks for right strlen of path and colour array, right range of RGV values
and a valid path for texture paths. */
int	check_identifiers(t_state *state)
{
	if (ft_arrlen(state->map->path_text) != 4 || ft_arrlen(state->map->colours) != 2
		|| state->map->pos_map == -5)
		return (-1);
	//HOW TO CHECK FOR VALID PATH TO TEXTURE??? MINILIBX FUNCTION
	check_valid_rgb(state);
	// check_valid_path();

	return (0);
}
