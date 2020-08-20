#include "minishell.h"

/**
  * _searchpath - searches for a given command in the path
  *
  * @com: command to search in path
  *
  * Return: pointer to the string that represents the complete path of com.
  * NULL if not found in any dir of PATH.
  */
char *_searchpath(char *com)
{
	char *path = _getenv("PATH");
	char *token = NULL, *dir = NULL;
	struct stat st;

	if (path == NULL)
	{
		return (NULL);
	}
	token = strtok(path, ":");
	while (token != NULL)
	{
		dir = _concat(3, token, "/", com);
		if (stat(dir, &st) == 0)
		{
			free(path);
			return (dir);
		}
		free(dir);
		token = strtok(NULL, ":");
	}
	/*At this points means it was not found in PATH*/
	free(path);
	dir = NULL;
	return (dir);
}
