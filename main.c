#include "header.h"

/**
 * main - super shell
 * @ac: arguments count.
 * @argv: arguments.
 * Return: Always return 0.
 */

int main(int ac, char *argv[])
{
	size_t bytesnum = 0;
	int r_count = 0, w_count = 0;
	char *buffer = NULL, **array = NULL, *tok = NULL;
	char *_close[] = {"exit", NULL};
	(void)ac, (void)argv;

	if (isatty(STDIN_FILENO) != 0)
		write(STDOUT_FILENO, "$", 1);

	signal(SIGINT, _ctrl_c);

	while ((r_count = getline(&buffer, &bytesnum, stdin)) != -1 && ++w_count)
	{
		if (r_count != 1)
		{
			if (_print_env(buffer) == -1)
			{
				buffer[r_count - 1] = '\0';
				if (_strcmp(buffer, _close[0]) == 0)
					free(buffer), exit(0);

				array = _split_string(buffer, " ");
				tok = _token(array);
				if (tok == NULL)
					tok = array[0];

				_exec(w_count, tok, array);
			}
		}
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "$", 1);
	}
	if (isatty(STDIN_FILENO) != 0)
	write(STDOUT_FILENO, "\n", 1);

	free(buffer);
	return (0);
}
