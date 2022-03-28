#ifndef CUB_H
#define CUB_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# include "./srcs/libft/libft.h"



//xpm to image!!!




typedef struct s_map
{
	int			map_height;
	int			map_width;
	int			pos_map;
	char		**map;
	char		**path_text;
	char		**colours;
	int			rgb[6];
} t_map;


typedef struct s_state
{
	t_map	*map;
	int			ceiling;
	int			floor;
	// char	**rgb;
	// char	**xpm;
} t_state;

#define BUFFER_SIZE 1

int		main(int argc, char **argv);

/* Input verification and functions for map parsing & map error handling. */
int		check_args(int argc, char **argv);

/* Map parsing */
int		open_cub_file(char *file, int *fd);
int		parsing(t_state *state, int argc, char **argv);
int		get_map_height(t_state *state, char *file);
int		get_max_width(t_state *state, char *file);
int		mem_alloc_columns(t_state *state);
int		mem_alloc_rows(t_state *state, char *file);
int		read_map(t_state *state, char *file);
int		map_error_checkmap_error_check(t_state *state);
int		checker_line(int fd);
int		map_error_check(t_state *state);
int		parse_map(t_state *state, char **argv);


int		get_identifiers(t_state *state, char *file);
int		check_identifiers(t_state *state);

/*  */
void	print_map(t_state *state);
int		get_to_pos(t_state *state, int pos, int fd);
int		ft_isinstring(char *string, char c);

/* GNL */
char	*get_next_line(int fd);
char	*ft_get_output(char **line);

/* Utils */
void	ft_free_string(char **string);
void	ft_free_strarray(char ***arr);
int		ft_arrlen(char **token);

#endif