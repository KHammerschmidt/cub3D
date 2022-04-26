/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 23:58:14 by khammers          #+#    #+#             */
/*   Updated: 2022/04/09 18:06:18 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <fcntl.h>
# include <libft.h>
# include <raycaster.h>

typedef struct s_map
{
	int		map_height;
	int		map_width;
	int		pos_map;
	char	**map;
	char	**path_text;
	char	**colours;
	int		rgb[6];
	int		id_pos[6];
	int		ceiling;
	int		floor;
}	t_map;

# define BUFFER_SIZE 1

/* Check and set the players start coordinates */
void	set_player_pos(t_state *state);

/* Input verification and functions for map parsing & map error handling. */
int		check_args(int argc, char **argv);
int		parsing(t_state *state, char **argv);
int		open_file_get_to_pos(t_state *state, char *file);
int		parse_identifiers(t_state *state, char *file);
int		get_pos(t_state *state, char *line, char *temp, int i);
char	**get_token(char *line);
int		check_characters(char *line);
int		parse_map(t_state *state, char **argv);
int		get_map_height(t_state *state, char *file);
int		get_max_width(t_state *state, char *file);
int		mem_alloc_columns(t_state *state);
int		mem_alloc_rows(t_state *state, char *file);
int		read_map(t_state *state, char *file);
int		map_error_check(t_state *state);
int		rgb_config(t_state *state);
int		check_column(t_state *state, int x);
int		check_row(t_state *state, int y);
int		load_textures(t_state *state);
/* Utils */
int		get_to_pos(int pos, int fd);
int		ft_isinstring(char *string, char c);
int		open_cub_file(char *file, int *fd);

/* GNL */
char	*get_next_line(int fd);
char	*ft_get_output(char **line);

/* Utils */
void	ft_free_string(char **string);
void	ft_free_strarray(char ***arr);
int		ft_arrlen(char **token);

#endif
