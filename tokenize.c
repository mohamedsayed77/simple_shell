#include "header.h"
/**
 * tokenize - tokenizes a string
 * @line: the string to tokenize
 * Return: an array of tokens, or NULL if the memory allocation fails
 */
char **tokenize(char *line)
{
	char *token = NULL, *tmp = NULL;
	char **cmd = NULL;
	int count = 0, i = 0;

	if (!line)
		return (NULL);
	tmp = _strdup(line);
	token = my_strtok(tmp, TOK_DELIM);

	if (token == NULL)
	{
		free(tmp), tmp = NULL;
		free(line), line = NULL;
		return (NULL);
	}
	while (token)
	{
		count++;
		token = my_strtok(NULL, TOK_DELIM);
	}
	free(tmp), tmp = NULL;
	cmd = malloc(sizeof(char *) * (count + 1));

	if (!cmd)
	{
		free(line);
		return (NULL);
	}
	token = my_strtok(line, TOK_DELIM);

	while (token)
	{
		cmd[i++] = _strdup(token);
		token = my_strtok(NULL, TOK_DELIM);
	}
	free(line), line = NULL;
	cmd[i] = NULL;
	return (cmd);
}
/**
 * my_strtok - Custom implementation of strtok function
 * @str: The string to be tokenized
 * @delim: The delimiter characters
 * Return: Pointer to the next token found in the string,
 *  or NULL if no more tokens are found.
 */
char *my_strtok(char *str, const char *delim)
{
	static char *input;
	char *token;

	if (str)
		input = str;
	if (!input)
		return (NULL);
	while (*input && my_strchr(delim, *input))
		input++;
	if (!*input)
		return (NULL);
	token = input;
	while (*input && !my_strchr(delim, *input))
		input++;
	if (*input)
		*input++ = '\0';
	else
		input = NULL;
	return (token);
}

