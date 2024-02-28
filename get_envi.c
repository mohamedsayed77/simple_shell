#include "header.h"

/**
 * _getenv - Get the value of an environment variable
 * @variable: The name of the environment variable to retrieve
 * Return: A pointer to the value of the environment variable if found.
 * - NULL if the environment variable is not found.
 */
char *_getenv(char *variable)
{
	char *tmp, *key, *value, *envi;
	int i;


	for (i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);
		key = my_strtok(tmp, "=");

		if (_strcmp(key, variable) == 0)
		{
			value = my_strtok(NULL, "\n");
			envi = _strdup(value);
			free(tmp);
			return (envi);

		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}
