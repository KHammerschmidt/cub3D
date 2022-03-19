#include "cub.h"

/* Frees a string passed with it's address. */
void	ft_free_string(char **string)
{
	int	i;

	i = 0;
	if (!*string)
		return ;
	free(*string);
	*string = NULL;
}

/* Frees a string array passed by it's address. */
void	ft_free_strarray(char ***arr)
{
	int	i;

	if (*arr == NULL)
		return ;
	i = 0;
	while ((*arr)[i] != NULL)
	{
		free((*arr)[i]);
		(*arr)[i] = NULL;
		i++;
	}
	free(*arr);
	*arr = NULL;
}
