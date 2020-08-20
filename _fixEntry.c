#include "minishell.h"

/**
 * _null_char - Adds a null character at the end of a string
 *
 * @entry: string to add the null char to
 *
 * Return: pointer to the null terminated string
 */
char *_null_char(char *entry)
{
	int x;

	for (x = 0; entry[x] != '\n'; x++)
	{

	}
	entry[x] = '\0';
	entry = _lessSpaces(entry);

	return (entry);
}

/**
 * _lessSpaces - removes unwanted spaces from a command
 *
 * @entry: string to take the unwanted spaces from
 *
 * Return: modified string
 */
char *_lessSpaces(char *entry)
{
	int pos, space = 0;

	for (pos = 0; entry[pos] != '\0'; pos++)
	{
		if (pos == 0 && entry[pos] == ' ')
		{
			entry = _deleteChar(entry, pos);
			pos--;
		}
		else if (entry[pos] == ' ' && space)
		{
			entry = _deleteChar(entry, pos);
			pos--;
		}
		else if (entry[pos] == ' ')
			space = 1;
		else
			space = 0;
	}
	return (entry);
}

/**
 * _deleteChar - eliminates a char from a string moving the char back one space
 *
 * @entry: string to modify
 * @indx: index of the char to be deleted
 *
 * Return: modified string
 */
char *_deleteChar(char *entry, int indx)
{

	for (; entry[indx] != '\0'; indx++)
	{
		entry[indx] = entry[indx + 1];
	}
	return (entry);
}
