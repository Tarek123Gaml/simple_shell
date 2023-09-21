#include "shell.h"

/**
 * _strlen - function that return length of string
 *
 * @s: takes input as string
 *
 * Return: length of string
 */

int _strlen(char *s)
{
	int count = 0;

	if (!s)
		return (0);

	while (*s++)
		count++;
	return (count);
}

/**
 * _strcmp - that function comparison tow string
 *
 * @s: takes first string
 * @s1: takes second string
 *
 * Return: 1 or -1 or 0
 */

int _strcmp(char *s, char *s1)
{
	while (*s && *s1)
	{
		if (*s != *s1)
			return (*s - *s1);
		s++;
		s1++;
	}
	if (*s == *s1)
		return (0);
	else
		return (*s < *s1 ? -1 : 1);
}

/**
 * start_with - checks if s1 starts with s
 * @s: string to search
 * @s1: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */

char *start_with(const char *s, const char *s1)
{
	while (*s1)
		if (*s1++ != *s++)
			return (NULL);
	return ((char *)s);
}

/**
 * _strcat - concatenates two strings
 * @s: takes fist string
 * @s1: takes second string
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *s, char *s1)
{
	char *ret = s;

	while (*s)
		s++;
	while (*s1)
		*s++ = *s1++;
	*s = *s1;
	return (ret);
}
