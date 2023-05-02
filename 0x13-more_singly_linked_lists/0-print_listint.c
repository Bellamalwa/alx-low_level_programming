#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * print_listint - prints all the elements of a linked list of integers.
 * @head: pointer to the head of the linked list.
 *
 * Return: the number of nodes in the list.
 */
size_t print_listint(const listint_t *head)
{
size_t numb = 0;

while (head)
{
printf("%d\n", head->n);
numb++;
head = head->next;
}

return (numb);
}

