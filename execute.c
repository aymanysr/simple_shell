#include "shell.h"

/**
 * _execute - Executes a command in a new child process.
 * @command: Null-terminated array of strngs representing the cmd to execute.
 * @argv: Null-terminated arr of strngs representing the args to the cmd.
 *
 * Return: The exit status of the command.
 */
int _execute(char **command, char **argv)
{
	pid_t childProcess; /* Process ID of the child process */
	int status; /* Exit status of the child process */

	/* Create a new child process */
	childProcess = fork();
	if (childProcess == 0) /* If this is the child process */
	{
		/* Execute the command. If it fails, print an error message and exit. */
		if (execve(command[0], command, NULL) == -1)
		{
			perror(argv[0]);
			emptyArrayOfStrings(command);
			exit(127);
		}
	}
	else /* If this is the parent process */
	{
		/* Wait for the child process to finish and get its exit status */
		waitpid(childProcess, &status, 0);
		emptyArrayOfStrings(command);
	}

	/* Return the exit status of the command */
	return (WEXITSTATUS(status));
}
