#include "monty.h"
/**
 * free_stack - Function to free the stack
 * @stack: pointer to the stack to be freed
 * Return: nothing
 */
void free_stack(stack_t *stack)
{
  stack_t *tmp = NULL;

  while (stack != NULL)
    {
      tmp = stack;
      stack = stack->next;
      free(tmp);
    }
  free(stack);
}
