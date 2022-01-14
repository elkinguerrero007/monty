#include "monty.h"
/**
 * push_validate - validation for int value to push
 * @push_value: int to push
 * @line_n: line number of the .m file
 * Return: true if valid or false if not
 */

bool push_validate(char *push_value, int line_n)
{
  int i = 0;
  bool test = true;

  while (push_value[i])
    {

      if ((push_value[i] >= 48 && push_value[i] <= 57) || push_value[i] == 45)
	test = true;
      else
	{
	  test = false;
	  break;
	}
      i++;
    }

  if (test == false)
    {
      fprintf(stderr, "L%d: usage: push integer\12", line_n);
      exit(EXIT_FAILURE);
    }
  return (test);
}
