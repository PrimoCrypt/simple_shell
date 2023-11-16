#include "shell.h"

/**
 * _myexit - A function that exits the shell
 * @info: Represents the Struct containing arguments. Used to maintain
 *          constant function prototype.
 *  Return: exits with exit status
 *         (0) if info.argv[0] != "exit"
 */
int _myexit(info_t *info)
{
	int leo_exitcheck;

	if (info->argv[1])  /* If exit argument is present */
	{
		leo_exitcheck = _erratoi(info->argv[1]);
		if (leo_exitcheck == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _mycd(info_t *info)
{
	char *leo_s, *leo_dir, buffer[1024];
	int leo_chdir_ret;

	leo_s = getcwd(buffer, 1024);
	if (!leo_s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		leo_dir = _getenv(info, "HOME=");
		if (!leo_dir)
			leo_chdir_ret = /* TODO: what should this be? */
				chdir((leo_dir = _getenv(info, "PWD=")) ? leo_dir : "/");
		else
			leo_chdir_ret = chdir(leo_dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(leo_s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		leo_chdir_ret = /* TODO: what should this be? */
			chdir((leo_dir = _getenv(info, "OLDPWD=")) ? leo_dir : "/");
	}
	else
		leo_chdir_ret = chdir(info->argv[1]);
	if (leo_chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - THis function changes the current directory of the process
 * @info: Represents the structure containing arguments. Used to maintain
 *          constant function prototype.
 *  Return: 0
 */
int _myhelp(info_t *info)
{
	char **leo_arg_array;

	leo_arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*leo_arg_array); /* temp att_unused workaround */
	return (0);
}
