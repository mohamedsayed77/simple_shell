#include "header.h"
/**
 * print_error - Prints an error message to stderr when a command is not found.
 * @name: The name of the shell.
 * @cmd: The command that was not found.
 * @idx: The index of the command.
 */
void print_error(char *name, char *cmd, int idx)
{
	char *index, mssg[] = ": not found\n";

	index = _itoa(idx);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, mssg, _strlen(mssg));

free(index);
}

