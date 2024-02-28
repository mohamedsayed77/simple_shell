#include "header.h"

/**
 * is_builtin - Check if a command is a built-in shell command
 * @command: The command name to check
 * Return: 1 if the command is a built-in shell command.
 * - 0 if the command is not a built-in shell command.
 */
int is_builtin(char *command)
{
	int i;
	char *builtins[] = {
		"exit", "env", "setenv", "unsetenv", NULL
	};

	for (i = 0; builtins[i]; i++)
	{
		if (_strcmp(command, builtins[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * handle_builtin - Handles built-in shell commands
 * @command: The array of command tokens.
 * @argv: The array of arguments.
 * @status: Pointer to the exit status of the shell.
 * @idx: The index of the command in the command history.
 */

void handle_builtin(char **command, char **argv, int *status, int idx)
{
	if (_strcmp(command[0], "exit") == 0)
		exit_shell(command, argv, status, idx);

	else if (_strcmp(command[0], "env") == 0)
		print_env(command, status);

	else if (_strcmp(command[0], "setenv") == 0)
		setenv_command(command, status);

	else if (_strcmp(command[0], "unsetenv") == 0)
		unsetenv_command(command, status);
}
