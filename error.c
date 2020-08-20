#include "minishell.h"

/**
* not_found - used to print error message when a command has not been found
*
* @argv: argument in position 0
* @count: number of shell iteration we're in
* @string: name of the command that has not been found
* @retVal: value of return
*
* Return: void
*/

void not_found(char *argv, int count, char *string, int *retVal)
{
	char *mess = NULL;
	int lens;
	char *c = NULL;
	(void)string;

	c = _itoa(count);
	mess = _concat(6, argv, ": ", c, ": ", string, ": not found\n");
	for (lens = 0; mess[lens] != '\0'; lens++)
	{
	}
	lens++;
	write(STDERR_FILENO, mess, lens);
	free(c);
	free(mess);
	*retVal = 127;
}
