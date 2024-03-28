#include "monty.h"

/**
	* func_push - add node to the stack
	* @head: stack head
	* @counter: line_number
	* Return: no return
	*/
void func_push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (!operation_context.argument)
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(operation_context.file_ptr);
		free(operation_context.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	if (operation_context.argument[0] == '-')
	j++;

	for (; operation_context.argument[j] != '\0'; j++)
	{
		if (!isdigit(operation_context.argument[j]))
		{
			flag = 1;
			break;
		}
	}

	if (flag == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(operation_context.file_ptr);
		free(operation_context.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(operation_context.argument);
	if (operation_context.is_fifo == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
