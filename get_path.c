#include "shell.h"
/**
 * _getpath - Gets the full path of a command.
 * @cmd: The command to get the full path of.
 *
 * Return: The full path of the command, or NULL if not found.
 */
char *_getpath(char *cmd)
{
	char *path_env, *whole_cmd, *directory;
	int i;
	struct stat st;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/') /* If the command starts with '/' */
		{
			if (stat(cmd, &st) == 0)/* check if it exists */
				return (_strdup(cmd));

			return (NULL);
		}
	}
	path_env = _getenv("PATH");/* Get the PATH environment variable */

	if (path_env == NULL)/* If the PATH environment var is not set, return NULL */
		return (NULL);

	directory = strtok(path_env, ":"); /* Split the PATH into directories */
	while (directory) /* Loop over each directory in the PATH */
	{
		whole_cmd = malloc(_strlen(directory) + _strlen(cmd) + 2);
		if (whole_cmd) /* If the allocation was successful */
		{	/* Construct the full command path */
			_strcpy(whole_cmd, directory);
			_strcat(whole_cmd, "/");
			_strcat(whole_cmd, cmd);
			/* If the command exists in this directory, return the full path */
			if (stat(whole_cmd, &st) == 0)
			{
				free(path_env);/* Clean up the PATH environment variable */
				return (whole_cmd);
			}
			free(whole_cmd), whole_cmd = NULL; /* Clean up the full command path */
			directory = strtok(NULL, ":"); /* Get the next directory in the PATH */
		}
	}
	free(path_env);/* Clean up the PATH environment variable */
	return (NULL);/* If the command was not found in any directory, return NULL */
}
