#include "header.h"


/**
 * exit_shell - Exit the shell with a specified status code
 * @command: Array of command arguments
 * @argv: Array of command-line arguments
 * @status: Pointer to an integer representing the status
 * @idx: Index of the current command
 */

void exit_shell(char **command, char **argv, int *status, int idx)
{
	int exit_value = (*status);
	char *index, err_msg[] = {": exit: Illegal number: "};

	if (command[1])
	{
		if (is_positive_num(command[1]))
		{
			exit_value = _atoi(command[1]);
		}
		else
		{
			index = _itoa(idx);

			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, index, _strlen(index));
			write(STDERR_FILENO, err_msg, _strlen(err_msg));
			write(STDERR_FILENO, command[1], _strlen(command[1]));
			write(STDERR_FILENO, "\n", 1);


			free(index);
			free_array_string(command);
			(*status) = 2;

			return;
		}
	}
	free_array_string(command);
	exit(exit_value);
}

/**
 * print_env - Print the environment variables
 * @command: Array of command arguments (unused in this function)
 * @status: Pointer to an integer representing the status
 */

void print_env(char **command, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);

	}
	free_array_string(command);
	(*status) = 0;
}
/**
 * setenv_command - Set or update an environment variable
 * @command: Array of command arguments containing the variable name and value
 * @status: Pointer to an integer representing the status
 * Returns: This function does not return a value directly.
 *  It sets the status variable
 * indirectly based on the success or failure of the setenv() operation.
 */

void setenv_command(char **command, int *status)
{
	if (command[1] == NULL || command[2] == NULL)
	{
		write(STDERR_FILENO, "setenv: Too few arguments.\n", 24);
		free_array_string(command);
		(*status) = 1;
		return;
	}

	if (setenv(command[1], command[2], 1) != 0)
	{
		write(STDERR_FILENO, "setenv: ", 8);
		perror("");
	}

	free_array_string(command);
	(*status) = 0;
}
/**
 * unsetenv_command - Unset an environment variable
 * @command: Array of command arguments containing the variable name
 * @status: Pointer to an integer representing the status
 * Returns: This function does not return a value directly.
 * It sets the status variable
 * indirectly based on the success or failure of the unsetenv() operation.
 */
void unsetenv_command(char **command, int *status)
{
	if (command[1] == NULL)
	{
		write(STDERR_FILENO, "unsetenv: Too few arguments.\n", 25);
		free_array_string(command);
		(*status) = 1;
		return;
	}

	if (unsetenv(command[1]) != 0)
	{
		write(STDERR_FILENO, "unsetenv: ", 10);
		perror("");
	}

	free_array_string(command);
	(*status) = 0;
}
