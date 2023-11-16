#include "shell.h"

/**
 * _strlen - THis function returns the length of a string
 * @leo_s: Represents the string whose length to check
 *
 * Return: length of string as integer
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
 * _strcmp - This function performs lexicogarphic comparison of two strangs.
 * @leo_s1: Represents the first strang
 * @leo_s2: Represents the second strang
 *
 * Return: s1 < s2 - negative, s1 > s2 - positive, s1 == s2 - zero
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
 * starts_with - This function checks if needle starts with haystack
 * @leo_haystack: Represents string to search
 * @leo_needle: Represents the substring to find
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
 * _strcat - This function concatenates two strings
 * @leo_dest: represents the destination buffer
 * @leo_src: represents the source buffer
 *
 * Return: a pointer to destination buffer
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
