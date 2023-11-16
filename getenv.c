#include "shell.h"

/**
 * _getenv - Gets the value of an environment variable.
 * @envVariable: The name of the environment variable to get.
 *
 * Return: The value of the environment variable, or NULL if not found.
 */
char *_getenv(char *envVariable)
{
	int i;
	char *temp, *key, *value, *env;

	/* Loop over each string in the environ array */
	for (i = 0; environ[i]; i++)
	{
		/* Dup the strng so we can use strtok on it without modifying the original */
		temp = _strdup(environ[i]);

		/* Get the key from the string */
		key = strtok(temp, "=");

		/* If the key matches the requested environment variable */
		if (_strcmp(key, envVariable) == 0)
		{
			/* Get the value from the string */
			value = strtok(NULL, "\n");

			/* Duplicate the value */
			env = _strdup(value);

			/* Clean up the temporary string */
			free(temp);

			/* Return the duplicated value */
			return (env);
		}

		/* Clean up the temporary string */
		free(temp);
	}

	/* If the environment variable was not found, return NULL */
	return (NULL);
}
