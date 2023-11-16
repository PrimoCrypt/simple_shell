#include "shell.h"

/**
 * _myenv - FUNCTION thst prints the current environment
 * @info: a Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: 0 success
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - A function to get the value of an environ variable
 * @info: This is the Structure containing potential arguments. Used to maintain
 * @name: Represents the environmental variable name
 *
 * Return: the resulting value of the code
 */
char *_getenv(info_t *info, const char *leo_name)
{
	list_t *node = info->env;
	char *leo_p;

	while (node)
	{
		leo_p = starts_with(node->str, leo_name);
		if (leo_p && *leo_p)
			return (leo_p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - This is a function to Initialize a new environment variable,
 *             or modify an existing one
 * @info: The Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int leo_i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (leo_i = 1; leo_i <= info->argc; leo_i++)
		_unsetenv(info, info->argv[leo_i]);

	return (0);
}

/**
 * populate_env_list - populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *my_node = NULL;
	size_t leo_n;

	for (leo_n = 0; environ[leo_n]; leo_n++)
		add_node_end(&my_node, environ[leo_n], 0);
	info->env = my_node;
	return (0);
}
