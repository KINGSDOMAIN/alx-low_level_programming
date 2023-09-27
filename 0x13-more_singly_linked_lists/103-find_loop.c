#include "lists.h"

/**
* find_listint_loop - Locates a loop in a linked list.
* @head: Pointer to the head of the linked list.
*
* Return: Address of the node where the loop starts, or NULL if no loop exists.
*/
listint_t *find_listint_loop(listint_t *head)
{
listint_t *slow = head;
listint_t *fast = head;

if (head == NULL)
return NULL;

for (; slow && fast && fast->next;)
{
fast = fast->next->next;
slow = slow->next;

if (fast == slow)
{
slow = head;
for (; slow != fast;)
{
slow = slow->next;
fast = fast->next;
}
return fast;
}
}

return NULL;
}
