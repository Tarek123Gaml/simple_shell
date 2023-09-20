#include "shell.h"

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

#include "shell.h"

/**
 * **strtowOne - it splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @dilm: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtowOne(char *str, char *dilm)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!dilm)
		dilm = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!is_a_delim(str[i], dilm) && (is_a_delim(str[i + 1], dilm) || !str[i + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (is_a_delim(str[i], dilm))
			i++;
		k = 0;
		while (!is_a_delim(str[i + k], dilm) && str[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * **strtowTow - splits a string into words
 * @str: the input string
 * @dilm: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtowTow(char *str, char dilm)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != dilm && str[i + 1] == dilm) ||
		    (str[i] != dilm && !str[i + 1]) || str[i + 1] == dilm)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (str[i] == dilm && str[i] != dilm)
			i++;
		k = 0;
		while (str[i + k] != dilm && str[i + k] && str[i + k] != dilm)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
