#include <stdlib.h>
#include "lists.h"

/**
 * free_list - frees a linked list and let them go
 * @head: list_t list to be freed from memory
 */
void free_list(list_t *head)
{
	list_t *temp;

	while (head)
	{
		temp = head->next;
		free(head->str);
		free(head);
		head = temp;
	}
}

