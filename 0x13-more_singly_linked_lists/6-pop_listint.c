#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list.
 * @head: pointer to a pointer to the head of the linked list.
 *
 * Return: the value of the deleted node's data (n), or 0 if the list is empty.
 */
int pop_listint(listint_t **head)
{
listint_t *current_node;
int deleted_value;

if (*head == NULL)
return (0);

current_node = *head;
*head = (*head)->next;
deleted_value = current_node->n;
free(current_node);

return (deleted_value);
}

