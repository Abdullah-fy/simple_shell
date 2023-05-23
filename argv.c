#include "main.h"
/**
 * arg_value - allocates memory for an array of string
 * and fill it with a given data
 *
 * @head: structure pointer to the head of a linked list
 *
 * Return: pointer to pointer to an array of string
 */
char **arg_value(exec_arg *head)
{
	exec_arg *temp = NULL;
	int size = 0, i = 0;
	char **argv = NULL;

	temp = head;
	while (temp)
	{
		temp = temp->next;
		size++;
	}
	argv = malloc((size + 1) * sizeof(exec_arg));
	temp = head;
	while (temp->next)
	{
		argv[i] = temp->str;
		temp = temp->next;
		i++;
	}
	argv[i] = NULL;
	return (argv);
}
/**
 * arg_list - splits a string into substring and store them into a linked list
 *
 * @buf: The content to be split
 * @delim: delimiters that will split the @buf
 *
 * Return: pointer to the head of a linked list
 */
exec_arg *arg_list(char *buf, char *delim)
{

	char *str = NULL;
	exec_arg *head = NULL, *temp = NULL, *new_node = NULL;

	str = strtok(buf, delim);
	head = malloc(sizeof(exec_arg));
	if (head == NULL)
	{
		perror("Memory allocate");
		return (NULL);
	}

	head->str = str;
	head->next = NULL;
	temp = head;
	while (str)
	{
		str = strtok(NULL, delim);
		new_node = malloc(sizeof(exec_arg));
		if (new_node == NULL)
		{
			perror("Memory allocate");
			return (NULL);
		}
		new_node->str = str;
		new_node->next = NULL;
		temp->next = new_node;
		temp = temp->next;
		new_node = new_node->next;
	}
	return (head);
}
/**
 * free_argv - free memory allocate of a linked list
 *
 * @head: pointer to the head of a linked list
 */
void free_argv(exec_arg *head)
{
	exec_arg *temp = NULL;

	temp = head;
	while (head)
	{
		head = head->next;
		free(temp->str);
		free(temp);
		temp = head;
	}
}
