#include "lists.h"

/**
 * free_listint2 - Releases memory allocated for a linked list
 * @head: Pointer to the listint_t list to be freed
 */
void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (head == NULL)
		return;

	for (; *head != NULL; *head = temp)
	{
		temp = (*head)->next;
		free(*head);
	}

	*head = NULL;
}
