#include "monty.h"

/**
 * add - adds top two elements of the stacks
 * @stack: pointer to the head of the stack
 * @line_number: line number
 */
void add(stack_t **stack, unsigned int line_number)
{
  int a, b, r;

  if ((*stack) == NULL || (*stack)->next == NULL)
    {
      fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
      exit(EXIT_FAILURE);
    }

  a = (*stack)->n;
  b = (*stack)->next->n;

  r = a + b;
  (*stack)->next->n = r;
  pop(stack, line_number);
}
