#include "shell.h"
#include <stddef.h>

/**
 **_strncpy - this copies a string
 *@dest: this is the destination string to be copied to
 *@src: this is the source string
 *@n: this is the amount of characters to be copied
 *Return: this is the concatenated string
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
 *@n: this is the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (n > 0 && *src)
	{
		*dest++ = *src++;
		n--;
	}
	*dest = '\0';

	return (ret);
}

/**
 **_strchr - this locates a character in a string
 *@p: this is the string to be parsed
 *@l: this is the character to look for
 *Return: (p) a pointer to the memory area s
 */
char *_strchr(char *p, char l)
{
	do {
		if (*p == l)
			return (p);
	} while (*p++ != '\0');

	return (NULL);
}
