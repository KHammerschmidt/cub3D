/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_identifiers_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:55:05 by khammers          #+#    #+#             */
/*   Updated: 2022/04/26 23:11:07 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static int	save_idf_spawning(t_state *state, int checker, int i, char *temp)
{
	if (state->map->path_text[checker] != NULL)
		return (-1);
	state->map->path_text[checker] = ft_strdup(temp);
	state->map->id_pos[checker] = i;
	return (0);
}

static int	save_idf_rgb(t_state *state, char *line, char *temp, int i)
{
	if (ft_strnstr(line, "C", ft_strlen(line)) != 0)
	{
		if (state->map->colours[0] != NULL)
			return (-1);
		state->map->colours[0] = ft_strdup(temp);
		state->map->id_pos[4] = i;
	}
	if (ft_strnstr(line, "F", ft_strlen(line)) != 0)
	{
		if (state->map->colours[1] != NULL)
			return (-1);
		state->map->colours[1] = ft_strdup(temp);
		state->map->id_pos[5] = i;
	}
	return (0);
}

int	get_pos(t_state *state, char *line, char *temp, int i)
{
	if (ft_strnstr(line, "NO ", 3) != 0)
		if (save_idf_spawning(state, 0, i, temp) != 0)
			return (-1);
	if (ft_strnstr(line, "EA ", 3) != 0)
		if (save_idf_spawning(state, 1, i, temp) != 0)
			return (-1);
	if (ft_strnstr(line, "SO ", 3) != 0)
		if (save_idf_spawning(state, 2, i, temp) != 0)
			return (-1);
	if (ft_strnstr(line, "WE ", 3) != 0)
		if (save_idf_spawning(state, 3, i, temp) != 0)
			return (-1);
	if (ft_strnstr(line, "C", ft_strlen(line)) != 0 || \
		ft_strnstr(line, "F", ft_strlen(line)) != 0)
	{
		if (save_idf_rgb(state, line, temp, i) != 0)
			return (-1);
	}
	return (0);
}

char	**get_token(char *line)
{
	char	**token;

	token = ft_split(line, ' ');
	if (token == NULL || ft_arrlen(token) != 2)
	{
		ft_free_strarray(&token);
		return (NULL);
	}
	return (token);
}

/* Checks if there are any characters found in line which are not map
characters. If so, the start of the map has not bee n found. */
int	check_characters(char *line)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (i < ft_strlen(line) - 1)
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W' && line[i] != ' '
			&& line[i] != 'D')
			return (1);
		i++;
	}
	return (0);
}
