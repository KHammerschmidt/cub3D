/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 19:58:49 by sachmull          #+#    #+#             */
/*   Updated: 2022/03/26 19:58:51 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_next_line(int fd)
{
	char	*line;
	char	*buf;
	char	*tmp;

	line = ft_calloc(1, 1);
	buf = ft_calloc(2, 1);
	tmp = NULL;
	while (!ft_strchr(line, '\n'))
	{
		if (read(fd, buf, 1) < 1)
		{
			free(buf);
			if (ft_strlen(line))
				return (line);
			free(line);
			return (NULL);
		}
		tmp = ft_strjoin(line, buf);
		free(line);
		line = tmp;
	}
	free(buf);
	return (line);
}
