#include "header.h"
/**
 * exec - Execute a command
 * @command: Array of command arguments
 * @argv: Array of command-line arguments
 * @idx: Index of the current command
 * Return: The exit status of the child process.
 */
int exec(char **command, char **argv, int idx)
{
	char *full_cmd;
	pid_t pid;
	int status;

	full_cmd = _getpath(command[0]);

	if (!full_cmd)
	{
		print_error(argv[0], command[0], idx);
		free_array_string(command);
		return (127);
	}
	pid = fork();

	if (pid == 0)
	{
		if (execve(full_cmd, command, environ) == -1)
		{
			free(full_cmd), full_cmd = NULL;
			free_array_string(command);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		free_array_string(command);
		free(full_cmd), full_cmd = NULL;
	}
	return (WEXITSTATUS(status));
}
