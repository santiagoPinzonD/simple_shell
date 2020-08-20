#include "minishell.h"


/**
* _array_this - separates entry into words and adds each to a position in av
*
* @entry: command that the used entered
* @av: pointer to the array where the strings are to be positioned
*
* Return: void
*/

void _array_this(char *entry, char **av)
{
	int x = 0;
	char *tok = NULL;

	tok = strtok(entry, " ");

	while (tok != NULL)
	{
		av[x] = tok;
		tok = strtok(NULL, " ");
		x++;
	}
	av[x] = NULL;
}
