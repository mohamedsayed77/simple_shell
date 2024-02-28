#include "header.h"

/**
 * main - Entry point for the shell program.
 * @ac: The number of arguments passed to the program.
 * @argv: Array of strings containing the arguments passed
 * to the program.
 * Return: Upon successful execution of the program, returns 0.
 */
int main(int ac, char **argv)
{
	char *line = NULL;
	char **command = NULL;
	int status = 0, idx = 0;
	(void)ac;

	do {
		line = read_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);

			return (status);
		}
		idx++;
		command = tokenize(line);

		if (!command)
			continue;
		if (is_builtin(command[0]))
			handle_builtin(command, argv, &status, idx);
		else
			status = exec(command, argv, idx);
	} while (1);
}
