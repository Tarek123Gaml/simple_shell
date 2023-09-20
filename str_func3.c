#include "shell.h"

/**
 * **strtow -  splits a string into an array of words based on a delimiter
 * @str: The input string that you want to split into words.
 * @delimiter: The delimiter character used to split the string.
 * @wordCount: A pointer to an integer where the function will store the count
 * Return: the splited words
 */

char **strtow(const char *str, const char *delimiter, int *wordCount)
{
	char **words = NULL;
	int count = 0;

	if (str == NULL)
	{
		*wordCount = 0;
		return (NULL);
	}
	char *strCopy = strdup(str);

	if (strCopy == NULL)
	{
		*wordCount = 0;
		return (NULL);
	}
	char *token = strtok(strCopy, delimiter);

	while (token != NULL)
	{
		words = (char **)realloc(words, (count + 1) * sizeof(char *));
		words[count] = strdup(token);
		if (words[count] == NULL)
		{
			for (int i = 0; i < count; i++)
			{
				free(words[i]);
			}
		free(words);
		free(strCopy);
		*wordCount = 0;
		return (NULL);
		}
	count++;
	token = strtok(NULL, delimiter);
	}
	free(strCopy);
	*wordCount = count;
	return (words);
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

