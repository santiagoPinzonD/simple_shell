#include "minishell.h"

/**
 * _concat - function that concatenates a list of strings
 *
 * @n: number of string that are to be concatenated
 *
 * Return: pointer to the new concatenated string
 */

char *_concat(int n, ...)
{
	/* _concat(5, "sh: ", c, ": ", string, " not found"); */
	va_list args;
	int lend, arg, ch, totalChars, x = 0;
	char *dest;
	char *currarg;

	va_start(args, n);
	totalChars = argsLen(args, n);
	dest = malloc(totalChars * sizeof(char));
	va_start(args, n);
	dest = _strcpy(dest, va_arg(args, char *));
	for (lend = 0; dest[lend] != '\0'; lend++)
	{
	}
	for (arg = 0; arg < n - 1; arg++)
	{
		currarg = va_arg(args, char *);
		for (ch = 0; currarg[ch] != '\0'; ch++, x++)
		{
			dest[lend + x] = currarg[ch];
		}
	}
	dest[lend + x] = '\0';
	va_end(args);
	return (dest);
}

/**
* argsLen - gets the total amount of chars that the variadic arguments have
*
* @args: variadic arguments
* @n: number of args
*
* Return: total of chars
*/

int argsLen(va_list args, int n)
{
	char *currarg;
	int pos, narg = 0, totalChars = 0;

	currarg = va_arg(args, char *);
	while (narg < n)
	{
		for (pos = 0; currarg[pos] != '\0'; pos++)
		{
			totalChars++;
		}
		narg++;
	}
	return (totalChars);
}
