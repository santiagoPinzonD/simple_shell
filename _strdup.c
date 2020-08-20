#include "minishell.h"

/**
 * *_strdup - duplicates a string allocating memory for the new one
 *
 * @src: string to be duplicated
 *
 * Return: Pointer to the new allocated string
 */

char *_strdup(char *src)
{
	int c, len;
	char a;
	char *dest;

	for (len = 0; src[len] != '\0'; len++)
	{
	}
	dest = malloc(sizeof(char) * (len + 2));
	for (c = 0; src[c] != '\0'; c++)
	{
		a = src[c];
		dest[c] = a;
	}
	dest[c] = '\0';
	return (dest);
}
