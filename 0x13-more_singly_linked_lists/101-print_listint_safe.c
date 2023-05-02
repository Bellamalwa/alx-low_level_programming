#include  <stdio.h>
#include "lists.h"

/**
 * print_listint_safe - Prints a linked list of integers.
 * @head: A pointer to the head of the linked list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
size_t count = 0;
const listint_t *curr = head, *temp;
while (curr != NULL)
{
printf("[%p] %d\n", (void *)curr, curr->n);
count++;
temp = curr;
curr = curr->next;
if (temp <= curr)
{
printf("-> [%p] %d\n", (void *)curr, curr->n);
exit(98);
}
}
return (count);
}

