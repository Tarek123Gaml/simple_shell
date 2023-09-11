#include "shell.h"

/**
 * _atoi - convert a string into an integer.
 * @s: the string to use.
 *
 * Return: integer
 */

int _atoi(char *s)
{
	int i, d, n, length, f, digit;

	n = 0;
	d = 0;
	i = 0;
	length = 0;
	f = 0;
	digit = 0;

	while (s[length] != '\0')
		length++;
	while (i < length && f == 0)
	{
		if (s[i] == '-')
			++d;
		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			if (d % 2)
				digit = -digit;
			n = n * 10 + digit;
			f = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
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
* interactive - returns true when shell is in interactive mode
* @info: struct address
*
* Return: 1 for interactive mode, otherwise 0
*/

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
* is_delim - checks if a character is a delimeter
* @c: the character to check
* @delim: the delimeter string
* Return: 1 if true, 0 if false
*/

int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
* _isalpha - checks for alphabetic characters
* @c: inputed char
* Return: 1 if  c is alphabetic, otherwise 0
*/

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >=  'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
