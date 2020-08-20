#include "minishell.h"
/**
 * main - initial part of the simple shell
 *
 * @argc: number of arguments to main
 * @argv: array with the arguments recieved
 *
 * Return: 0 always
 */
int main(int argc, char *argv[])
{
	char *entry = NULL;
	size_t n_bytes = 0;
	int count = 0, inte = 1, retVal = 0;
	(void) argc;

	while (inte)
	{
		count++;
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		signal(SIGINT, sigfunc);
		if (getline(&entry, &n_bytes, stdin) == EOF)
		{
			free(entry);
			write(STDOUT_FILENO, "\n", isatty(STDIN_FILENO));
			return (0);
		}
		entry = _null_char(entry);

		conditions(argv[0], entry, &retVal, &count);
	}
	return (0);
}

/**
 * conditions - checks conditions that main needs
 *
 * @argv: first agument of main
 * @entry: string gotten from getline
 * @retVal: Valor de retorno
 * @count: n_ite
 * Return: void
 */
void conditions(char *argv, char *entry, int *retVal, int *count)
{
	int control = 1;
	char *av[50];
	struct stat st;
	char *dir = NULL;

	if (!speComs(entry, retVal))
		control = 0;
	_array_this(entry, av);
	if (stat(av[0], &st) == 0)
	{
		create_child(av[0], av, retVal);
		control = 0;
	}
	if (control)
		dir = _searchpath(entry);
	if (dir != NULL)
	{
		av[0] = dir;
		create_child(av[0], av, retVal);
		free(dir);
		control = 0;
	}
	if (control)
	{
		_array_this(entry, av);
		not_found(argv, *count, av[0], retVal);
	}
}



/**
 * create_child - executes a given command
 *
 * @route: route where the command is located
 * @av: array where the route and arguments are stored
 *
 * Return: void
 */
void create_child(char *route, char **av, int *retVal)
{
	pid_t child;
	int status;

	child = fork();
	if (child == 0)
	{
		/*_array_this(entry, av);*/
		if (execve(route, av, NULL) == -1)
			exit(-1);
		exit(0);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			*retVal = WEXITSTATUS(status);
	}
}
