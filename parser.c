#include "shell.h"

/**
 * is_cmd - This function determines if a file is an executable command
 * @info: This is the info struct
 * @leo_path: This is the path to the file
 *
 * Return: 1 true, 0 false
 */
int is_cmd(info_t *info, char *leo_path)
{
	struct stat leo_st;

	(void)info;
	if (!leo_path || stat(leo_path, &leo_st))
		return (0);

	if (leo_st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - This function duplicates characters int his program
 * @leo_pathstr: This is the PATH string
 * @start: This represents the starting index
 * @stop: This argument reresents the stopping index
 *
 * Return: a pointer to new buffer
 */
char *dup_chars(char *leo_pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (leo_pathstr[i] != ':')
			buf[k++] = leo_pathstr[i];
	buf[k] = 0;
	return (buf);
}

/**
 * find_path - this finds this cmd in the PATH string
 * @info: this is an info struct
 * @leo_pathstr: this is the PATH string
 * @cmd: represents the cmd to find
 *
 * Return: full path of the cmd, else NULL
 */
char *find_path(info_t *info, char *leo_pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!leo_pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!leo_pathstr[i] || leo_pathstr[i] == ':')
		{
			path = dup_chars(leo_pathstr, curr_pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!leo_pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
