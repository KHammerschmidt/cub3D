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

/* Checks if character c is in string, returns 0 if found. */
int	ft_isinstring(char *string, char c)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == c)
			return (0);
		i++;
	}
	return (1);
}

/* Returns the length of an array. */
int	ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
