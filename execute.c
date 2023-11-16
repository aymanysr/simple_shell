#include "shell.h"

/**
 * _execute - Executes a command in a new child process.
 * @command: Null-terminated array of strings representing the cmd to execute.
 * @argv: Null-terminated array of strings representing the args to the cmd.
 * @i: The index of the command in the argv array.
 *
 * Return: The exit status of the command.
 */
int _execute(char **command, char **argv, int i)
{
	char *whole_cmd;
	pid_t childProcess; /* Process ID of the child process */
	int status; /* Exit status of the child process */

	/* Get the full path of the command */
	whole_cmd = _getpath(command[0]);
	/* If the command was not found, print an error message and return 127 */
	if (whole_cmd == NULL)
	{
		print_error(argv[0], command[0], i);
		emptyArrayOfStrings(command);
		return (127);
	}

	/* Create a new child process */
	childProcess = fork();
	/* If this is the child process */
	if (childProcess == 0)
	{
		/* Execute the command. If it fails, clean up and exit. */
		if (execve(whole_cmd, command, environ) == -1)
		{
			free(whole_cmd), whole_cmd = NULL;
			emptyArrayOfStrings(command);
		}
	}
	/* If this is the parent process */
	else
	{
		/* Wait for the child process to finish and get its exit status */
		waitpid(childProcess, &status, 0);
		emptyArrayOfStrings(command);
		free(whole_cmd), whole_cmd = NULL;
	}

	/* Return the exit status of the command */
	return (WEXITSTATUS(status));
}
