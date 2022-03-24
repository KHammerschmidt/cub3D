#include "cub.h"

// void	get_identifiers(t_state *state)
// {
// 	int		fd;
// 	char 	*line;

// 	fd = 0;
// 	line = NULL;
// 	if (open_cub_file(file, &fd) == -1)
// 		return (-1);
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		if (ft_strnstr(line, "NO", ft_strlen(line)) != 0)
// 			state->pos_no == ft_split(line);
// 		if (ft_strnstr(line, "SO", ft_strlen(line)) != 0)
// 			state->pos_so == ft_split(line);
// 		if (ft_strnstr(line, "EA", ft_strlen(line)) != 0)
// 			state->pos_ea == ft_split(line);
// 		if (ft_strnstr(line, "WE", ft_strlen(line)) != 0)
// 			state->pos_we == ft_split(line);
// 		if (ft_strnstr(line, "F", ft_strlen(line)) != 0)
// 			state->pos_no == ft_split(line);
// 		if (ft_strnstr(line, "C", ft_strlen(line)) != 0)
// 			state->pos_no == ft_split(line);
// 		ft_free_string(&line);
// 		line = get_next_line(fd);
// 	}
// }