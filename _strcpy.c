#include "minishell.h"

/**
 * *_strcpy - check the code for Holberton School students.
 * @dest: this a pointer
 * @src: this is a pointer
 * Return: Always 0.
 */

char *_strcpy(char *dest, char *src)
{
	int c;
	char a;

	for (c = 0; src[c] != '\0'; c++)
	{
		a = src[c];
		dest[c] = a;
	}
	dest[c] = '\0';
	return (dest);
}
