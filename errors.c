#include "shell.h"

/**
 * _eputs - this prints an input string
 * @str: this is the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int j = 0;

	if (!str)
		return;
	while (str[j] != '\0')
	{
		_eputchar(str[j]);
		j++;
	}
}

/**
 * _eputchar - this writes the character c to stderr
 * @e: this is the character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char e)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (e == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(2, buf, j);
		j = 0;
	}
	if (e != BUF_FLUSH)
		buf[j++] = e;
	return (1);
}

/**
 * _putfd - this writes the character c to given fd
 * @e: this is the character to print
 * @fd: this is the file descriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char e, int fd)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (e == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(fd, buf, j);
		j = 0;
	}
	if (e != BUF_FLUSH)
		buf[j++] = e;
	return (1);
}

/**
 * _putsfd - this prints an input string
 * @str: this is the string to be printed
 * @fd: this is the file descriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int j = 0;

	if (!str)
		return (0);
	while (*str)
	{
		j += _putfd(*str++, fd);
	}
	return (j);
}
