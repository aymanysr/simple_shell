#include "shell.h"

/**
 * *_strdup - retrun a pointer to a newly allocated space in memory
 * which contains a copy of the string given as a parameter.
 * @str: string
 * Return: 0
 */

char *_strdup(const char *str)
{
	char *m;
	int i, size = 0;

	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		size++;
		str++;
	}
	str = str - size;
	/* +1 on the size puts the end of string character*/
	m = malloc(sizeof(char) * (size + 1));
	if (m == NULL)
		return (NULL);
	for (i = 0; i <= size; i++)
		m[i] = str[i];
	return (m);
}

/**
 * _strcmp - compares two strings
 * @s1: first string to be compared
 * @s2: second string to be compared
 *
 * Return: 1 if true 0 if false
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}

	return (s1[i] - s2[i]);

}

/**
 * _strlen - returns the length of a string
 *
 * @s: string parameter input
 *
 * Return: length of string
 */

int _strlen(char *s)
{
	int counter;

	for (counter = 0; *s != ('\0'); s++)
		counter++;

	return (counter);
}

/**
 * _strcat - Concatenates two strings
 * @dest: The destination string
 * @src: The source string
 *
 * Return: A pointer to the resulting string (dest)
 */

char *_strcat(char *dest, char *src)
{
	int dest_len = 0;
	int i = 0;

	/*find the length of dest*/
	while (dest[dest_len] != '\0')
		dest_len++;

	/*append src to dest*/
	while (src[i] != '\0')
	{
		dest[dest_len] = src[i];
		dest_len++;
		i++;
	}

	/*Null-terminate the concatenated string*/
	dest[dest_len] = '\0';

	return (dest);
}

/**
 * *_strcpy - copies the string pointed to by src
 * @dest: char type string
 * @src: char type string
 * Description: Copy the string pointed to by pointer 'src' to the
 *		buffer pointed to by 'dest'
 * Return: Pointer to 'dest'
 */

char *_strcpy(char *dest, char *src)
{
	int i = -1;

	do {
		i++;
		dest[i] = src[i];
	} while (src[i] != '\0');

	return (dest);
}
