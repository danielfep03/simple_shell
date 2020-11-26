#include "header.h"

/**
 * _split_string - Function to splir an array in tokens
 *@str: string from buffer.
 *@delim: character to create tokens
 * Return: an array splited by tokens to success
 */

char **_split_string(char *str, char *delim)
{

	int i = 0, x = 0;
	char **array = NULL, *token = NULL, *token2;
	char *str_copy = NULL;

	str_copy = _strdup(str);

	token = _strtok(str_copy, delim);

	while (token)
	{
		token = _strtok(NULL, delim);
		i++;
	}
	free(str_copy);

	str_copy = _strdup(str);
	token2 = _strtok(str_copy, delim);
	array = malloc(sizeof(char *) * (i + 1));

	while (token2)
	{
		array[x] = _strdup(token2);
		token2 = _strtok(NULL, delim);
		x++;
	}
	array[x] = NULL;

	free(token);
	free(token2);
	free(str_copy);
	return (array);
}

/**
 * _strcmp - to compare two string
 *@s1: value waited from the main.c
 *@s2: source to be compare
 * Return: Always 0.
 */

int _strcmp(char *s1, char *s2)
{
	int c = 0, x = 0;

	for (c = 0; s1[c] != '\0' && s2[c] != '\0'; c++)
	{
		if (s1[c] == s2[c])
			x = 0;
		else
			return (s1[c] - s2[c]);
	}
	return (x);
}

/**
 * _strtok - Funtion to create an array of tokens.
 *
 * @str: Command from the user imput.
 * @delim: Delimiter.
 *
 * Return: Always return 0.
 */

char *_strtok(char *str, const char *delim) /* by Leo. */
{
	const char *org = delim;
	int isEqual = 1, isGetInto = 0;
	static char *step, *stepNull;
	static int isEnd;

	if (str)
		isEnd = 0;
	if (isEnd)
		return (NULL);
	step = (str) ? str : (stepNull + 1);
	if (str)
		stepNull = str;
	else
		str = step;
	while (*str && isEqual)
	{
		isEqual = 0;
		for (delim = org; *delim; delim++)
			if (*str == *delim)
				isEqual = 1;
		str = (!isEqual) ? str : str + 1;
		isEnd = (*str) ? 0 : 1;
		if (isEnd)
			return (NULL);
	}
	step = str;
	while (*str && !isEqual)
	{
		isEqual = 0;
		for (delim = org; *delim; delim++)
			if (*str == *delim)
			{
				isGetInto = 1, isEqual = 1;
				isEnd = (*(str + 1)) ? 0 : 1, *str = '\0';
			}
		str = (isEqual) ? str : str + 1;
		if (!isGetInto && !*str)
			isEnd = 1;
	}
	return (stepNull = str, step);
}

/**
 * _token - Function to split a strink by tokens
 *
 * @array: array to save all tokens
 *e
 * Return: string divided by token to success
 */

char *_token(char *array[])
{
	char *token = NULL;

	if (array[0][0] == '/' || array[0][0] == ' ')
	{
		if (array[0][0] == ' ')
		{
			token = _string_directory(array);
			return (token);
		}
		else
		{
			token = array[0];
		}

	}
	else
	{
		token = _string_directory(array);
	}
	return (token);
}

/**
 * _strdup - Function that duplicate an array
 * with a new apce in memory
 * @str: string to duplicated
 * Return: duplicated string to succes or NULL from error
 */

char *_strdup(char *str)
{
	char *copy;
	int index = 0, len = 0;

	if (str == NULL)
		return (NULL);

	for (index = 0; str[index]; index++)
		len++;

	copy = malloc(sizeof(char) * (len + 1));

	if (copy == NULL)
		return (NULL);

	for (index = 0; str[index]; index++)
		copy[index] = str[index];

	copy[len] = '\0';

	return (copy);
}
