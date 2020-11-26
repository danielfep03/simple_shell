#include "header.h"
#define BSIZE 4


/**
 * _print_env - Function to print env
 * @buffer: string from buffer to compare
 * Return: 1 for success or -1 for error
 */

int _print_env(char *buffer)
{
	int i = 0, j = 0;
	char *key_word[] = {"env", NULL};
	char *env_token = NULL;

	if (buffer[0] == ' ')
		env_token =	_strtok(buffer, " ");
	else
	{
		env_token = buffer;
	}

	if (_strcmp(env_token, key_word[0]) == 0)
	{
		while (environ[i])
		{
			for (j = 0; environ[i][j]; j++)
			;
			write(1, environ[i], j);
			write(1, "\n", 1);
			i++;
		}
		return (1);
	}
return (-1);
}

/**
 * _getenv - Function to get de enviroment
 * @name:string from buffer
 * Return: PATH to succes or NULL for error
 */

char *_getenv(char *name)
{
	int i = 0, j = 0;
	char *null = "(null)";

	char *path = NULL;

	for (j = 0; name[j]; j++)
	;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (!_strcmp(environ[i], name))
		{
			path = (environ[i] + (j + 1));
			return (path);
		}
	}
	return (null);
}

/**
 * _getline - Function to set a . at the begining of a string.
 *
 * @buffer: string from buffer
 * @bufsize: string from buffer
 * @fd: string from buffer
 *
 * Return: string with a . at the begining of a string.
 */

int _getline(char **buffer, size_t *bufsize, int fd)
{
	static char *buff;
	static size_t size;
	unsigned int len = 0, i = 0, sizeold;
	int r;

	if (*bufsize == 0)
		size = BSIZE;
	if (*buffer == 0)
	{
		buff = malloc(sizeof(char) * size);
		if (!buff)
			return (write(2, "Memory Error", 22), 0);
		*buffer = buff;
	}
	buff = _memset(buff, '\0', size);
	do {

		r = read(fd, buff + len, BSIZE);
		if (r >= 0)
			i = len, len += r;
		if (r == -1 || r == 0)
			return (-1);
		if  (len >= size)
		{
			sizeold = size, size += BSIZE;
			buff = _realloc(buff, sizeold, size);
			if (!buff)
				return (write(2, "Memory Error", 22), 0);
		}
		for (; i < len; i++)
		{
			if (buff[i] == '\n')
			{
				*buffer = buff, *bufsize = size;
				return (len);
			}
		}

	} while (1);
	return (len);
}

