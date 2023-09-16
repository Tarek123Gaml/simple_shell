#include "shell.h"

/**
 * _eput_char - writes the character c to stderr
 * @ch: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eput_char(char ch)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (ch != BUF_FLUSH)
		buf[i++] = ch;
	return (1);
}

/**
 * eput_str - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void eput_str(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eput_char(str[i]);
		i++;
	}
}

/**
 * _put_fdis - writes the character c to given fd
 * @ch: The character to print
 * @fdis: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _put_fdis(char ch, int fdis)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fdis, buf, i);
		i = 0;
	}
	if (ch != BUF_FLUSH)
		buf[i++] = ch;
	return (1);
}

/**
 * _put_str_fdis - prints an input string
 * @str: the string to be printed
 * @fdis: the file descriptor to be written
 *
 * Return: the number of chars put
 */
int _put_str_fdis(char *str, int fdis)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _put_fdis(*str++, fdis);
	}
	return (i);
}

