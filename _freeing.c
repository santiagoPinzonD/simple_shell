#include "minishell.h"

/**
 * freeArr - freedom a array
 *
 * @arr: array that inside
 *
 * Return: void
 */
void freeArr(char *arr[])
{
	int pos = 0;

	while (arr[pos])
	{
		free(arr[pos]);
		pos++;
	}
}
