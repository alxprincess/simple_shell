#include "shell.h"

/**
 * interactive - It returns true if shell is interactive mode
 * @stru: struct address
 *
 * Return: 1 if interactive mode, 0 if otherwise
 */
int interactive(info_t *stru)
{
	return (isatty(STDIN_FILENO) && stru->readfd <= 2);
}

/**
 * is_delim -  to check if character is a delimeter
 * @k: char to check
 * @delime: delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char k, char *delime)
{
	while (*delime)
		if (*delime++ == k)
			return (1);
	return (0);
}

/**
 * _isalpha - this checks for alphabetic character
 * @k: character to input
 * Return: 1 if k is alphabetic, 0 if otherwise
 */

int _isalpha(int k)
{
	if ((k >= 'a' && k <= 'z') || (k >= 'A' && k <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - this converts a string to an integer
 * @x: string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *x)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; x[i] != '\0' && flag != 2; i++)
	{
		if (x[i] == '-')
			sign *= -1;

		if (x[i] >= '0' && x[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
