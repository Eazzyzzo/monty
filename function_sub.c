#include "monty.h"

/**
	* func_sub - subtracts the top element from the second top element
	* @head: stack head
	* @counter: line_number
	* Return: no return
	*/
void func_sub(stack_t **head, unsigned int counter)
{
	stack_t *current_node = *head;
	int nodes, subtraction;
	/*Count the number of nodes in the stack*/
	for (nodes = 0; current_node != NULL; nodes++)
		current_node = current_node->next;
	/*Check if the stack has at least two elements*/
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(operation_context.file_ptr);
		free(operation_context.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	/*Subtract the top element from the second top element*/
	current_node = *head;
	subtraction = current_node->next->n - current_node->n;
	/*Update the value of the second top element with the result*/
	current_node->next->n = subtraction;
	/*Remove the first element from the stack*/
	current_node = *head;
	*head = (*head)->next;
	free(current_node);
}
