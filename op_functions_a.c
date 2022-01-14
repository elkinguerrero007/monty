#include "monty.h"
/**
 * push - Adds a new node at the beginning of a stack_t list.
 * @stack: pointer to stack
 * @line_number: line number of .m file
 * @push_value: value to push
 */
void push(stack_t **stack, unsigned int line_number, int push_value)
{
  stack_t *new_node;

  (void)line_number;

  if (!stack)
    {
      exit(EXIT_FAILURE);
    }
  new_node = malloc(sizeof(stack_t));
  if (!new_node)
    {
      fprintf(stderr, "Error: malloc failed\n");
      exit(EXIT_FAILURE);
    }
  new_node->n = push_value;
  if (*stack)
    {
      (*stack)->prev = new_node;
      new_node->next = *stack;
      new_node->prev = NULL;
    }
  *stack = new_node;
}
/**
 * pall - Function that prints all the elements of a stack_t list.
 * @stack: pointer to the head of the stack_t list
 * @line_number: line number of .m file
 * Return: Number of nodes
 */
void pall(stack_t **stack, unsigned int line_number)
{
  stack_t *tmp = *stack;
  (void)line_number;

  while (tmp)
    {
      printf("%d\n", tmp->n);
      tmp = tmp->next;
    }
}
/**
 * pint - Function that prints the value at the top of the stack.
 * @line_number: node value
 * @stack: pointer to the head of the stack_t list
 */
void pint(stack_t **stack, unsigned int line_number)
{
  int value;

  if (*stack == NULL)
    {
      fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
      exit(EXIT_FAILURE);
    }
  value = (*stack)->n;
  printf("%d\n", value);
}
/**
 * pop - deletes the node at the top of te stack
 * @stack: A pointer to the head of the stack_t.
 * @line_number: index of the node that should be deleted.
 */
void pop(stack_t **stack, unsigned int line_number)
{
  stack_t *tmp = *stack;

  if (*stack == NULL || stack == NULL)
    {
      fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
      exit(EXIT_FAILURE);
    }
  tmp = (*stack)->next;
  free(*stack);
  *stack = tmp;

}
