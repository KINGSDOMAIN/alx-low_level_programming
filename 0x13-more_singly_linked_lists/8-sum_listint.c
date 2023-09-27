#include "lists.h"

/**
* sum_listint - Computes the sum of all the data in a listint_t list
* @head: Pointer to the first node in the list
*
* Return: The resulting sum
*/
int sum_listint(listint_t *head)
{
int sum = 0;
listint_t *temp;

for (temp = head; temp; temp = temp->next)
{
sum += temp->n;
}

return (sum);
}
