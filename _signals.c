#include "minishell.h"

/**
  * sigfunc - func for ctrl + c
  *
  * @signal: signal received of main
  *
  * Return: void
  */
void sigfunc(int signal)
{
	(void) signal;
	write(STDIN_FILENO, "\n#cisfun$ ", 10);
}
