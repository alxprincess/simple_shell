#include "shell.h"

/**
 * list_len - this determines the length of linked list
 * @p: this is the pointer to first node
 *
 * Return: size of list
 */
size_t list_len(const list_t *p)
{
	size_t i = 0;

	while (p)
	{
		p = p->next;
		i++;
	}
	return (i);
}

/**
 * list_to_strings - this returns an array of strings of the list->str
 * @head: this is the pointer to the first node
 *
 * Return: array of strings
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * print_list - this prints all elements of a list_t linked list
 * @p: this is the pointer to the first node
 *
 * Return: size of list
 */
size_t print_list(const list_t *p)
{
	size_t i = 0;

	while (p)
	{
		_puts(convert_number(p->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(p->str ? p->str : "(nil)");
		_puts("\n");
		p = p->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with - this returns node whose string starts with prefix
 * @node: this is the pointer to list head
 * @prefix: this is the string to match
 * @k: this is the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char k)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((k == -1) || (*p == k)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - this gets the index of a node
 * @head: this is the pointer to the list head
 * @node: this is the pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
