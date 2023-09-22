#include <stdio.h>
#include "lists.h"

/**
 * prints all the elements of a linked list
 * @h: pointer to the list to print
 *
 * Return: number of nodes printes
 */
size_t print_list(const list_t *h)
{
	size_t a = 0;

	while (h)
	{
		if (!h->str)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);
		h = h->next;
		a++;
	}

	return (a);
}
