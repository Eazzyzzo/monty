#include "monty.h"
/**
	* func_mul - multiplies the top two elements of the stack
	* @head: stack head
	* @counter: line_number
	* Return: no return
	*/
void func_mul(stack_t **head, unsigned int counter)
{
	stack_t *current_node = *head;
	int len = 0, multiplication;
	/*Count the number of nodes in the stack*/
	while (current_node != NULL)
	{
		current_node = current_node->next;
		len++;
	}
	/*Check if the stack has at least two elements*/
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(operation_context.file_ptr);
		free(operation_context.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	/*Retrieve the top element of the stack*/
	current_node = *head;
	/*Perform the multiplication operation*/
	multiplication = current_node->next->n * current_node->n;
	/*Update value of second top element with the result*/
	current_node->next->n = multiplication;
	/*Remove the first element from the stack*/
	current_node = *head;
	*head = (*head)->next;
	free(current_node);
}
