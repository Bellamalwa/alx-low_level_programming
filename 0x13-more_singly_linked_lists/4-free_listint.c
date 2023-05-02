#include <stdlib.h>
#include "lists.h"

/**
 * free_listint - frees a listint_t list.
 * @head: pointer to the head of the linked list.
 *
 * Return: void.
 */
void free_listint(listint_t *head)
{
listint_t *current_node;

while (head != NULL)
{
current_node = head;
head = head->next;
free(current_node);
}
}

