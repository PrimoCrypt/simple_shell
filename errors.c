#include "shell.h"

/**
 *_eputs - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *leo_str)
{
	int leo_i = 0;

	if (!leo_str)
		return;
	while (leo_str[leo_i] != '\0')
	{
		_eputchar(leo_str[leo_i]);
		leo_i = leo_i + 1;
	}
}

/**
 * _eputchar - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char leo_c)
{
	static int leo_i;
	static char leo_buf[WRITE_BUF_SIZE];

	if (leo_c == BUF_FLUSH || leo_i >= WRITE_BUF_SIZE)
	{
		write(2, leo_buf, leo_i);
		leo_i = 0;
	}
	if (leo_c != BUF_FLUSH)
		buf[leo_i = leo_i + 1] = leo_c;
	return (1);
}
