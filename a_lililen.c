#include "monty.h"
/**
 * lililen - linked list length
 * @stack: the linked list head pointer
 * Return: the size of list
 **/
size_t lililen(stack_t **stack)
{
size_t counter = 0;
stack_t *tmp;

if (*stack == NULL)
{
return (0);
}
tmp = *stack;
while (tmp)
{
tmp = tmp->next;
counter++;
}
return (counter);
}
