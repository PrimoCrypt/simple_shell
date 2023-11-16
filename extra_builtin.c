#include "shell.h"

/**
 * _myhistory - This function displays the history list, one command by line,
 *	preceded with line numbers, starting at 0.
 * @info: represents Structure containing arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - This function sets alias to string
 * @info: parameter struct
 * @leo_str: the string alias
 *
 * Return: Success 0, error 1
 */
int unset_alias(info_t *info, char *leo_str)
{
	char *leo_p, leo_c;
	int leo_ret;

	leo_p = _strchr(leo_str, '=');
	if (!leo_p)
		return (1);
	leo_c = *leo_p;
	*leo_p = 0;
	leo_ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias,
			node_starts_with(info->alias, leo_str, -1)));
	*leo_p = leo_c;
	return (leo_ret);
}

/**
 * set_alias - THis function sets alias to string
 * @info: Represents parameter struct
 * @leo_str: represents the string alias
 *
 * Return: Success 0, error 1
 */
int set_alias(info_t *info, char *leo_str)
{
	char *leo_p;

	leo_p = _strchr(leo_str, '=');
	if (!leo_p)
		return (1);
	if (!*++leo_p)
		return (unset_alias(info, leo_str));

	unset_alias(info, leo_str);
	return (add_node_end(&(info->alias), leo_str, 0) == NULL);
}

/**
 * print_alias - this function prints an alias string
 * @node: represents the alias node
 *
 * Return: Success 0, error 1
 */
int print_alias(list_t *node)
{
	char *leo_p = NULL, *leo_a = NULL;

	if (node)
	{
		leo_p = _strchr(node->str, '=');
		for (leo_a = node->str; leo_a <= leo_p; leo_a++)
			_putchar(*leo_a);
		_putchar('\'');
		_puts(leo_p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - this function mimics the alias builtin (man alias)
 * @info: Represents Structure containing arguments. Used to maintain
 *          constant function prototype.
 *  Return: 0
 */
int _myalias(info_t *info)
{
	int leo_i = 0;
	char *leo_p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (leo_i = 1; info->argv[leo_i]; leo_i++)
	{
		leo_p = _strchr(info->argv[leo_i], '=');
		if (leo_p)
			set_alias(info, info->argv[leo_i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[leo_i], '='));
	}

	return (0);
}
