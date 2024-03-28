#include "monty.h"

/**
	* func_swap - swaps the top two elements of the stack
	* @head: stack head
	* @counter: line_number
	* Return: no return
	*/
void func_swap(stack_t **head, unsigned int counter)
{
	stack_t *current_node = *head;
	int len = 0, temp;
	/*Calculate the number of elements in the stack*/
	while (current_node != NULL)
	{
		current_node = current_node->next;
		len++;
	}

	/*Check if the stack has at least two elements*/
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(operation_context.file_ptr);
		free(operation_context.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	/*Swap the values of the top two elements*/
	temp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = temp;
}
