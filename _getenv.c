#include "minishell.h"
/**
 * _getenv - get the value of the enviroment variable
 *
 * @name: name of the variable
 *
 * Return: string that is value of variable
 */
char *_getenv(const char *name __attribute__((unused)))
{
	char *tok;
	int i = 0;
	char *token;
	char *envi[100];

	while (environ[i])
	{
		envi[i] = _strdup(environ[i]);
		i++;
	}
	envi[i] = NULL;
	i = 0;
	tok = strtok(envi[i], "=");
	while (_strcmp(name, tok) && envi[i])
	{
		/*token = tok;*/
		tok = strtok(NULL, "\0");
		free(envi[i]);
		/*envi[i] = _concat(3, token, "=", tok);*/
		envi[i] = _strdup(environ[i]);
		if (!envi[++i])
			return (NULL);
		tok = strtok(envi[i], "=");
	}
	tok = strtok(NULL, "\0");
	token = _strdup(tok);
	freeArr(envi);
	return (token);
}
