#include "shell.h"

/**
 * _myhistory - this displays the history list, one command by line, preceded
 * with line numbers, starting at 0.
 * @info: Structure containing potential arguments. 
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *r, k;
	int ret;

	r = _strchr(str, '=');
	if (!r)
		return (1);
	k = *r;
	*r = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*r = k;
	return (ret);
}

/**
 * set_alias - this sets alias to string
 * @info: this is the parameter struct
 * @str: this is the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *r;

	r = _strchr(str, '=');
	if (!r)
		return (1);
	if (!*++r)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - this prints an alias string
 * @node: this is the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *r = NULL, *f = NULL;

	if (node)
	{
		r = _strchr(node->str, '=');
		for (f = node->str; f <= r; r++)
		_putchar(*f);
		_putchar('\'');
		_puts(r + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - this mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *  constant function prototype.
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
	int j = 0;
	char *r = NULL;
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
	for (j = 1; info->argv[j]; j++)
	{
		r = _strchr(info->argv[j], '=');
		if (r)
			set_alias(info, info->argv[j]);
		else
			print_alias(node_starts_with(info->alias, info->argv[j], '='));
	}

	return (0);
}
