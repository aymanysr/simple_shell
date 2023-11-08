#include "shell.h"

/**
 * tokenizer - Tokenizes a string into an array of words.
 * @line: The string to tokenize.
 *
 * Return: A null-terminated array of words, or NULL on failure.
 */
char **tokenizer(char *line)
{
	char *tmp, *token;
	char **cmd;
	int counter = 0, i = 0;

	/* Dup the line so we can use strtok on it without modifying the original */
	tmp = _strdup(line);
	/* Get the first token from the line */
	token = strtok(tmp, DELIM);

	/* If there are no tokens, clean up and return NULL */
	if (token == NULL)
	{
		free(tmp);
		free(line);
		return (NULL);
	}
	while (token)	/* Count the number of tokens in the line */
	{
		counter++;
		token = strtok(NULL, DELIM);
	}
	free(tmp);	/* Clean up the temporary string */
	/* Allocate space for the command array */
	cmd = malloc(sizeof(char *) * (counter + 1));
	if (cmd == NULL) /* If the allocation failed, clean up and return NULL */
	{
		free(line);
		return (NULL);
	}
	/* Get the 1st token from the line again to store in the cmd array */
	token = strtok(line, DELIM);
	while (token) /* Store each token in the commad array */
	{
		cmd[i] = _strdup(token);
		token = strtok(NULL, DELIM);
		i++;
	}
	free(line); /* Clean up the line string */
	cmd[i] = NULL;	/* Null-terminate the commad array */
	return (cmd);	/* Return the command array */
}
