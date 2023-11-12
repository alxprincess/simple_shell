#include "shell.h"

/**
 **_strncpy - this copies a string
 *@dest: this is the destination string to be copied to
 *@src: this is the source string
 *@n: this is the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int k, l;
	char *s = dest;

	k = 0;
	while (src[k] != '\0' && k < n - 1)
	{
		dest[k] = src[k];
		k++;
	}
	if (k < n)
	{
		l = k;
		while (l < n)
		{
			dest[l] = '\0';
			l++;
		}
	}
	return (s);
}

/**
 **_strncat - this concatenates two strings
 *@dest: this is the first string
 *@src: this is the second string
 *@m: this is the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int m)
{
	int k, l;
	char *s = dest;

	k = 0;
	l = 0;
	while (dest[k] != '\0')
		k++;
	while (src[l] != '\0' && l < m)
	{
		dest[k] = src[l];
		k++;
		l++;
	}
	if (l < m)
		dest[k] = '\0';
	return (s);
}

/**
 **_strchr - this locates a character in a string
 *@t: this is the string to be parsed
 *@e: this is the character to look for
 *Return: (t) a pointer to the memory area t
 */
char *_strchr(char *t, char e)
{
	do {
		if (*t == e)
			return (t);
	} while (*t++ != '\0');

	return (NULL);
}
