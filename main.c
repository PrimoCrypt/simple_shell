#include "shell.h"

/**
 * main - The main function entry point
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 success, 1 error
 */

int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int leo_fd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (leo_fd)
		: "r" (leo_fd));

	if (ac == 2)
	{
		leo_fd = open(av[1], O_RDONLY);
		if (leo_fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = leo_fd;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}
