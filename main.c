#include "shell.h"

/**
 * main - simple shell main function
 * @ac: count of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success
 */
int main(int ac, char **argv)
{
	char *line = NULL;
	char **command = NULL;
	int status = 0, i = 0;

	/* Ignore the argument count */
	(void)ac;

	/* Main loop */
	while (1)
	{
		/* Read a line from standard input */
		line = read_line();

		/* If end of file is reached (CTRL + D), exit the loop */
		if (line == NULL)
		{
		/* If the input is a terminal, print a newline */
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);

			/* Return the last command's status */
			return (status);
		}
		i++;

		/* Tokenize the line into an array of words */
		command = tokenizer(line);

		/* If there are no words, skip this iteration */
		if (command == NULL)
			continue;

		/* Execute the command and store its exit status */
		status = _execute(command, argv, i);
	}
}
