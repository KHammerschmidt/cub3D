/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_identifiers_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:09:27 by khammers          #+#    #+#             */
/*   Updated: 2022/04/09 22:58:18 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

/* Checks every line for identifiers, cuts newline characters at the end
of string and saves texture path as well as rgb value in 2D arrays. */
static int	get_rgb_spawning(t_state *state, char *line, int i)
{
	char	**token;
	char	*temp;
	int		ret;

	ret = 0;
	temp = NULL;
	token = get_token(line);
	if (token == NULL)
		return (1);
	temp = ft_strtrim(token[1], "\n");
	ret = get_pos(state, line, temp, i);
	ft_free_strarray(&token);
	ft_free_string(&temp);
	if (ret == -1)
	{
		ft_putstr_fd("Error\nToo many identifiers\n", 1);
		return (-1);
	}
	return (0);
}

/* Reads *.cub file and checks for spawning and colour identifiers as well
as the start of the map. */
static int	get_identifiers(t_state *state, char *file)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = 0;
	if (open_cub_file(file, &fd) == -1)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (get_rgb_spawning(state, line, i) == -1)
			exit_cub(state);
		if (state->map->pos_map == -5 && line[0] != '\n' \
			&& check_characters(line) == 0)
			state->map->pos_map = i;
		ft_free_string(&line);
		i++;
	}
	ft_free_string(&line);
	close(fd);
	return (0);
}

static void	init_id_pos(t_state *state)
{
	int	i;

	i = 0;
	while (i != 6)
	{
		state->map->id_pos[i] = -1;
		i++;
	}
}

static int	check_id_pos(t_state *state)
{
	int	i;

	i = 0;
	while (i != 6)
	{
		if (state->map->id_pos[i] == -1 || \
			state->map->id_pos[i] > state->map->pos_map)
			return (-1);
		i++;
	}
	return (0);
}

int	parse_identifiers(t_state *state, char *file)
{
	init_id_pos(state);
	if (get_identifiers(state, file) != 0)
		return (-1);
	if (check_id_pos(state) == -1)
	{
		ft_putstr_fd("Error\nInvalid indentifier\n", 1);
		return (-1);
	}
	if (rgb_config(state) != 0)
		return (-1);
	return (0);
}
