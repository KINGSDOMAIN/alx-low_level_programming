#include "lists.h"

/**
* free_listint - Releases memory allocated for a linked list
* @head: Pointer to the beginning of the list to be freed
*/
void free_listint(listint_t *head)
{
listint_t *temp;

for (; head != NULL; head = temp)
{
temp = head->next;
free(head);
}
}
