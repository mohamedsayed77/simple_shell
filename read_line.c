#include "header.h"
/**
 * read_line - Reads a line from standard input.
 * Return: A pointer to the line read from standard input,
 *  or NULL if an error occurs.
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t n;

	write(STDIN_FILENO, "$ ", 2);
	n = my_getline(&line, &len, stdin);
	if (n == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
/**
 * my_getline - Custom implementation of the getline function
 * @line: Pointer to a pointer where the line will be stored
 * @len: Pointer to a variable storing the allocated size of the buffer
 * @stream: File stream to read from
 * Return: On success, the function returns the length of the line read
 *         (excluding the null terminator). On failure, it returns -1.
 */

ssize_t my_getline(char **line, size_t *len, FILE *stream)
{
	static char buffer[BUFFER_SIZE];

	if (line == NULL || stream == NULL)
		return (-1);

	if (*line == NULL)
	{
		*len = BUFFER_SIZE;
		*line = malloc(*len);

		if (*line == NULL)
			return (-1);
	}
	(*line)[0] = '\0';

	while (fgets(buffer, sizeof(buffer), stream) != NULL)
	{

		if (*len - _strlen(*line) <= (size_t)_strlen(buffer))
		{
			*len += BUFFER_SIZE;
			*line = realloc(*line, *len);

			if (*line == NULL)
			{
				free(*line);
				return (-1);
			}
		}

		_strcat(*line, buffer);
		if ((*line)[_strlen(*line) - 1] == '\n')
			return (_strlen(*line));
	}
	return (-1);
}
