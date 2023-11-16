#include "shell.h"

/**
 * emptyArrayOfStrings - Frees a 2D array.
 * @array: The array to free.
 *
 * Return: void
 */
void emptyArrayOfStrings(char **array)
{
	int i;

	/* If the array is NULL, return immediately */
	if (!array)
	{
		return;
	}

	/* Loop over each string in the array */
	for (i = 0; array[i]; i++)
	{
		/* Free the string */
		free(array[i]), array[i] = NULL;
	}

	/* Free the array itself */
	free(array), array = NULL;
}

/**
 * _itoa - Converts an integer to a string.
 * @n: The integer to convert.
 *
 * Return: A new string containing the integer.
 */
char *_itoa(int n)
{
	char buffer[15];
	int i = 0;

	/* If the integer is 0, return a string containing '0' */
	if (n == 0)
		buffer[i++] = '0';
	else
	{
		/* Convert the int to a string by taking the remainder of n divided by 10 */
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}

	/* Null-terminate the string */
	buffer[i] = '\0';

	/* Reverse the string */
	rev_string(buffer, i);

	/* Return a duplicate of the string */
	return (_strdup(buffer));
}

/**
 * rev_string - Reverses a string.
 * @string: The string to reverse.
 * @length: The length of the string.
 *
 * Return: void
 */
void rev_string(char *string, int length)
{
	char temp;
	int start = 0;
	int end = length - 1;

	/*Swap the chars at the start & end of the string, moving towards the middle*/
	while (start < end)
	{
		temp = string[start];
		string[start] = string[end];
		string[end] = temp;
		start++;
		end--;
	}
}

/**
 * print_error - Prints an error message to standard error.
 * @shellName: The name of the shell.
 * @command: The command that caused the error.
 * @i: The index of the command.
 *
 * Return: void
 */
void print_error(char *shellName, char *command, int i)
{
	char *index, errMsg[] = ": not found\n";

	/* Convert the index to a string */
	index = _itoa(i);

	/* Print the error message */
	write(STDERR_FILENO, shellName, _strlen(shellName));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, errMsg, _strlen(errMsg));

	/* Free the index string */
	free(index);
}
