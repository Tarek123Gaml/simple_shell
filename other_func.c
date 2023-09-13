#include "shell.h"

/**
 * _atoi - convert a string into an integer.
 * @str: the string to use.
 *
 * Return: integer
 */

int _atoi(char *str)
{
	int i, d, n, length, f, digit;

	n = 0;
	d = 0;
	i = 0;
	length = 0;
	f = 0;
	digit = 0;

	while (str[length] != '\0')
		length++;
	while (i < length && f == 0)
	{
		if (str[i] == '-')
			++d;
		if (str[i] >= '0' && str[i] <= '9')
		{
			digit = str[i] - '0';
			if (d % 2)
				digit = -digit;
			n = n * 10 + digit;
			f = 1;
			if (str[i + 1] < '0' || str[i + 1] > '9')
				break;
			f = 0;
		}
		i++;
	}
	if (f == 0)
		return (0);

	return (n);
}

/**
 * inter_active - returns true when shell is in interactive mode
 * @info: struct address
 * Return: 1 for interactive mode, otherwise 0
 */

int inter_active(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_alpha - checks for alphabetic character
 * @ch: The character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int is_alpha(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * is_a_delim - checks where a character is a delimeter
 * @ch: the character to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */

int is_a_delim(char ch, char *delim)
{
	while (*delim)
		if (*delim++ == ch)
			return (1);
	return (0);
}
