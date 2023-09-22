#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - adds a new node at the start of a linked list
 * @head: double pointer to the list_t list
 * @str: new string to add in the node of the list
 *
 * Return: the address of the new element, or NULL if it fails
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *newvar;
	unsigned int len = 0;

	while (str[len])
		len++;

	new = malloc(sizeof(list_t));
	if (!newvar)
		return (NULL);

	newvar->str = strdup(str);
	newvar->len = len;
	newvar->next = (*head);
	(*head) = newvar;

	return (*head);
}

