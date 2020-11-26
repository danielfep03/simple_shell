#include "header.h"

/**
 * _itoa - Funtion to execute program.
 *
 * @count_w: Command from the user imput.
 *
 * Return: Always return 0.
 */
char *_itoa(int count_w)
{
	char *numstr;
	unsigned int tmp, digits;

	tmp = count_w;
	for (digits = 0; tmp != 0; digits++)
		tmp /= 10;
	numstr = malloc(sizeof(char) * (digits + 1));
	if (numstr == NULL)
	{
		perror("Fatal Error1");
		exit(127);
	}
	numstr[digits] = '\0';
	for (--digits; count_w; --digits)
	{
		numstr[digits] = (count_w % 10) + '0';
		count_w /= 10;
	}
	return (numstr);
}

/**
 * _string_directory - Split a string in tokens for each directory in the path.
 *
 * @argv: array to concatenate with directory and /.
 *
 * Return: On succes string concatenated 0r NULL if fails.
*/

char *_string_directory(char **argv)
{
	struct stat st;
	int i = 0, j = 0, k = 0;
	char **token_path = NULL, *p = NULL, *path = NULL;

	path = _getenv("PATH"); /*string de directorios*/

	if (path[0] == ':')
		path = _hack_path(path);

	token_path = _split_string(path, ":"); /*tokens del path*/

	i = 0;
	while (token_path[i]) /*recorre cada uno de los tokens*/
	{
		for (j = 0; token_path[i][j]; j++)
		;
		for (k = 0; argv[0][k]; k++)
		;
		p = malloc(sizeof(char) * (j + k + 2));
			if (!p)
			perror("Error"), _sfree(token_path), exit(0);

		for (j = 0; token_path[i][j]; j++)
			p[j] = token_path[i][j];
		p[j] = '/';
		for (k = 0; argv[0][k]; k++)
			p[j + k + 1] = argv[0][k];
		p[j + k + 1] = '\0';

		if (stat(p, &st) == 0)
		{
			_sfree(token_path);
			return (p);
		}
		i++;
		free(p);
	}
	_sfree(token_path);
	return (NULL);
}

/**
 * _hack_path - Function to set a . at the begining of a string.
 *
 * @path: string from buffer
 *
 * Return: string with a . at the begining of a string.
 */

char *_hack_path(char *path)
{
	char *path2 = NULL;
	char *path_cpy = NULL;
	int i = 0;

	path_cpy = _strdup(path); /*Duplico el path en otra variable*/

	for (; path[i] != '\0'; i++) /*Para saber el length de Path*/
	;
	path2 = malloc(sizeof(char) * i + 2);
	if (!path2)
	{
		free(path_cpy);
		exit(0);
	}

	path2[0] = '.';

	for (i = 0; path_cpy[i] != '\0'; i++)
	{
		path2[i + 1] = path_cpy[i];
	}
	path2[i] = '\0';

	free(path_cpy);
	return (path2);
}