#include "header.h"

/**
 *_ctrl_c - function to capture interruption signal
 *@sig: signal variable
 *Return: void
 */

void _ctrl_c(int sig)
{
	(void)sig;
	write(STDERR_FILENO, "\n", 1);
	write(STDOUT_FILENO, "$", 1);
}

/**
 * _sfree - Function to free double pointers
 * @i_want_to_be_free: double pointer to be free
 */

void _sfree(char **i_want_to_be_free)
{
	int ptr_index;

	for (ptr_index = 0; i_want_to_be_free[ptr_index] != NULL; ptr_index++)
	{
		free(i_want_to_be_free[ptr_index]);
	}
	free(i_want_to_be_free);
}

/**
 * _error - Funtion to execute program.
 *
 * @count_w: Command from the user imput.
 * @array: arguments for the program to execute.
 *
 * Return: Always return 0.
 */

void _error(int count_w, char *array[])
{
	int i = 0;
	char *print_c = NULL;

	print_c = _itoa(count_w);

	for (i = 0; print_c[i]; i++)
	;

	write(STDERR_FILENO, "\033[94mminishell$: \033[0m", 17);
	write(STDERR_FILENO, print_c, i); /* by Andy.*/
	write(STDERR_FILENO, ": ", 2);

	for (i = 0; array[0][i]; i++)
	;

	write(STDERR_FILENO, array[0], i);
	write(STDERR_FILENO, ": not found\n", 12);
	free(print_c);
}
