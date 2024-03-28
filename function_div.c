#include "monty.h"
/**
	* func_div - divides the second top element of the stack by the top element
	* @head: stack head
	* @counter: line_number
	* Return: no return
	*/
void func_div(stack_t **head, unsigned int counter)
{
	stack_t *current_node = *head;
	int len = 0, division;
	/*Count the number of nodes in the stack*/
	while (current_node != NULL)
	{
		current_node = current_node->next;
		len++;
	}
	/*Check if the stack has at least two elements*/
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(operation_context.file_ptr);
		free(operation_context.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
/*Retrieve the top element of the stack*/
	current_node = *head;
	/*Check if the divisor (top element) is zero*/
	if (current_node->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(operation_context.file_ptr);
		free(operation_context.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	/*Perform the division operation*/
	division = current_node->next->n / current_node->n;
	/*Update value of the second top element with the result*/
	current_node->next->n = division;
	/*Remove the first element from the stack*/
	current_node = *head;
	*head = (*head)->next;
	free(current_node);
}
