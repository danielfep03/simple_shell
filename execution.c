#include "header.h"

/**
 * _exec - Funtion to execute program.
 *
 * @token: Command from the user imput.
 * @array: arguments for the program to execute.
 * @count_w: holis.
 *
 * Return: Always return 0.
 */

int _exec(int count_w, char *token, char *array[])
{
	struct stat st;
	pid_t child = 0;

	if (stat(token, &st) == 0)
	{
		child = fork();
		if (child == -1)
			free(token),
			perror("Error"), exit(0);

		if (child == 0)
		{
			if (execve(token, array, NULL) == -1)
				perror("Error Execve"), exit(0);
		}
		else
		{
			wait(NULL);
			if (token != array[0])
				free(token);
			_sfree(array);

		}
	}
	else
	{
		_error(count_w, array);
		_sfree(array);
	}
	return (0);
}
