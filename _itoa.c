#include "minishell.h"

/**
 * _itoa - converts an int to a char*
 *
 * @num: int to be converted
 *
 * Return: pointer to the converted int
 */
char *_itoa(int num)
{
	int n_digit = 1, result = num, digit = 0;
	char *str = NULL;

	while (result / 10)
	{
		n_digit++;
		result /= 10;
	}
	str = malloc(sizeof(char) * (n_digit + 1));
	if (str == NULL)
	{
		return (NULL);
	}
	result = num;
	str[n_digit] = '\0';

	while (n_digit > 0)
	{
		digit = result % 10;
		str[--n_digit] = digit + '0';
		result /= 10;
	}
	return (str);
}
