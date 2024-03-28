#include "monty.h"

/**
	* func_pint - prints the top element of the stack
	* @head: stack head
	* @counter: line_number
	* Return: no return
	*/
void func_pint(stack_t **head, unsigned int counter)
{
	/*Check if the stack is empty*/
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(operation_context.file_ptr);
		free(operation_context.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
		/*Print the value of the top element of the stack*/
	printf("%d\n", (*head)->n);
}
