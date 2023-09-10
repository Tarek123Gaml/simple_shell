#include "shell.h"

/**
 * _strchr - locates a character in a string.
 * @s: pointer to the string content the character 'c' to search
 * @c: character you want to search for in the string 's'
 * Return: pointer to the first occurence of 'c' in the string
 * or NULL if 's' isn't found
 */

char *_strchr(char *s, char c)

{
	if (*s == '\0')
		return (s);
	while (*s)
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}
	if (c == '\0')
		return (s);
	return ('\0');
}

/**
 * _strncpy - copies a string.
 * @dest: A pointer to the buffer where the copied string will be stored.
 * @src: A pointer to the source string that you want to copy.
 * @n: number of characters to be copied from the src.
 * Return: A pointer to the distination buffer dest
 */

char *_strncpy(char *dest, char *src, int n)

{
	int j = 0;

	while (j < n && src[j] != '\0')
	{
		dest[j] = src[j];
		j++;
	}
	for (j = 0; j < n; j++)
	{
		dest[j] = '\0';
	}
	return (dest);
}

/**
 * _strncat - is a function that concatenates two strings.
 * @dest: pointer to the string to which the char willbe appended
 * @src:pointer to the string from char will be concatenated
 * @n: numbers of char to concatenate from src
 * Return: pointer to dest
 */

char *_strncat(char *dest, char *src, int n)

{
	int i, j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (j < n && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';
	return (dest);
}
