#include "minishell.h"

/**
 * _strcmp - check the code for Holberton School students.
 * @s1: this a string
 * @s2: this is a string
 * Return: 0
 */

int _strcmp(const char *s1, const char *s2)
{
	while ((*s1 || *s2) && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
	/*se retorna la resta que seria la comparacion y se hace entre ASCII*/
}
