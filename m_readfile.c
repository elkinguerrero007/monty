#include "monty.h"
/**
 * readfile - read a monty file
 */

void readfile(void)
{
char *buffer = NULL, *push_value = NULL;
size_t size = 0;
unsigned int line_n = 0;
int push_int = 0;
char *opcode = NULL;
stack_t *stack = NULL;

while (getline(&buffer, &size, globales.fp) != -1)
{
line_n++;
opcode = strtok(buffer, DELIM);
if (opcode == NULL)
continue;
if (strchr(opcode, '#') != NULL)
continue;
if (strcmp(opcode, "push") == 0)
{
push_value = strtok(NULL, DELIM);
if (push_value == NULL)
{
fprintf(stderr, "L%d: usage: push integer\n", line_n);
free_stack(stack), free(buffer), fclose(globales.fp);
exit(EXIT_FAILURE);
}
if (push_validate(push_value, line_n) == true)
{
push_int = atoi(push_value);
push(&stack, line_n, push_int);
}
}
else
{
get_opcode(opcode, &stack, line_n);
}
}
free_stack(stack);
free(buffer);
}
