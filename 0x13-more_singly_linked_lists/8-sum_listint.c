#include <stdio.h>
#include "lists.h"

/**
 * sum_listint - returns sum of all data (n) of a listint_t list.
 * @head: pointer to the head of the linked list.
 *
 * Return: sum of all data(n) in the linked list, or 0 if list is empty.
 */
int sum_listint(listint_t *head)
{
int sum = 0;
while (head != NULL)
{
sum += head->n;
head = head->next;
}

return (sum);
}

