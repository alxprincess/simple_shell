#include "shell.h"

/**
 * _strlen - this returns the length of a string
 * @l: this is the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *l)
{
	int i = 0;

	if (!l)
		return (0);

	while (*l++)
		i++;
	return (i);
}

/**
 * _strcmp - this performs lexicogarphic comparison of two strangs.
 * @s1: this is the first strang
 * @s2: this is the second strang
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - this checks if needle starts with haystack
 * @haystack: this is the string to search
 * @needle: this is the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - this concatenates two strings
 * @dest: this is the destination buffer
 * @src: this is the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
