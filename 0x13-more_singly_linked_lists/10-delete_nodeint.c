#include <stdio.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at a given index
 * @head: pointer to pointer to the head node of the list
 * @index: index of the node to delete
 *
 * Return: 1 if successful, -1 otherwise
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
listint_t *current, *prev;
unsigned int i;
if (head == NULL || *head == NULL)
return (-1);
if (index == 0)
{
current = *head;
*head = (*head)->next;
free(current);
return (1);
}
prev = NULL;
current = *head;
for (i = 0; i < index; i++)
{
if (current == NULL)
return (-1);
prev = current;
current = current->next;
}

if (prev != NULL)
prev->next = current->next;
free(current);
return (1);
}

