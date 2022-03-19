#ifndef CUB_H
#define CUB_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# include "./srcs/libft/libft.h"


typedef struct s_state
{
	char	**map;
	int		map_height;
	int		map_width;
	int		pos_map;
} t_state;

#define BUFFER_SIZE 1

int		main(int argc, char **argv);

/* Input verification and functions for map parsing & map error handling. */
int		input_verification(int argc, char **argv);

/* Map parsing */
int		open_cub_file(char *file, int *fd);
int		parsing(t_state *state, int argc, char **argv);
int		get_map_height(t_state *state, char *file);
int		get_max_width(t_state *state, char *file);
int		mem_alloc_columns(t_state *state);
int		mem_alloc_rows(t_state *state, char *file);
int		read_map(t_state *state, char *file);
int		map_error_check(t_state *state);

/*  */
void	print_map(t_state *state);
int		get_to_pos(t_state *state, int pos, int fd);

/* GNL */
char	*get_next_line(int fd);
char	*ft_get_output(char **line);

/* Utils */
void	ft_free_string(char **string);
void	ft_free_strarray(char ***arr);

#endif