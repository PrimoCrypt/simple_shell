#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *leo_s)
{
	int leo_i = 0;

	if (!leo_s)
		return (0);

	while (*leo_s++)
		leo_i++;
	return (leo_i);
}

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @s1: the first strang
 * @s2: the second strang
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *leo_s1, char *leo_s2)
{
	while (*leo_s1 && *leo_s2)
	{
		if (*leo_s1 != *leo_s2)
			return (*leo_s1 - *leo_s2);
		leo_s1++;
		leo_s2++;
	}
	if (*leo_s1 == *leo_s2)
		return (0);
	else
		return (*leo_s1 < *leo_s2 ? -1 : 1);
}

/**
 * starts_with - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *leo_haystack, const char *leo_needle)
{
	while (*leo_needle)
		if (*leo_needle++ != *leo_haystack++)
			return (NULL);
	return ((char *)leo_haystack);
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *leo_dest, char *leo_src)
{
	char *return_value = leo_dest;

	while (*leo_dest)
		leo_dest++;
	while (*leo_src)
		*leo_dest++ = *leo_src++;
	*leo_dest = *leo_src;
	return (return_value);
}
