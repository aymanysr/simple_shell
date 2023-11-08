#include "shell.h"
/**
 * emptyArrayOfStrings - frees 2D array
 * @array: array to free
 *
 * Return: void
 */
void emptyArrayOfStrings(char **array)
{
	int i;

	if (!array)
	{
		return;
	}
	for (i = 0; array[i]; i++)
	{
		/* printf("%s\n", array[i]); */
		free(array[i]), array[i] = NULL;
	}
	free(array), array = NULL;
}
