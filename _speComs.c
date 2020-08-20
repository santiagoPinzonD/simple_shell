#include "minishell.h"

/**
  * speComs - depending on the entry, executes an instruction.
  * Or does nothing if the entry is something not recognized
  *
  * @entry: the string gotten from getline
  * @retVal: value of return
  * Return: void
  */
int speComs(char *entry, int *retVal)
{
	int i = 0, len;
	char *exi = "exit";
	char *env = "env";

	if (!_strcmp(exi, entry))
	{
		free(entry);
		exit(*retVal);
	}
	if (!_strcmp(env, entry))
	{
		while (environ[i])
		{
			for (len = 0; environ[i][len] != '\0'; len++)
			{
			}
			write(STDOUT_FILENO, environ[i], len);
			write(STDOUT_FILENO, "\n", 1);
			i++;
		}
		return (0);
	}
	return (1);
}
