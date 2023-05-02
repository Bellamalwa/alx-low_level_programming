#include "lists.h"
#include <stdio.h>

/**
 * free_listint_safe - frees a listint_t list
 * @h: pointer to pointer to the head of the list
 *
 * Return: the size of the list that was free'd
 */
size_t free_listint_safe(listint_t **h)
{
listint_t *temp;
size_t size = 0;
while (*h != NULL)
{
temp = (*h)->next;
free(*h);
size++;
*h = temp;
if (*h != NULL && *h >= temp)
{
*h = NULL;
exit(98);
}
}
*h = NULL;
return (size);
}

