#include "monty.h"
/**
	* func_add - adds the top two elements of the stack
	* @head: stack head
	* @counter: line_number
	* Return: no return
	*/
void func_add(stack_t **head, unsigned int counter)
{
	stack_t *current_node = *head;
	int len = 0, sum;
	/*Calculate the number of elements in the stack*/
	while (current_node != NULL)
	{
		current_node = current_node->next;
		len++;
	}
	/*Check if the stack has at least two elements*/
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(operation_context.file_ptr);
		free(operation_context.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	/*Calculate the sum of the top two elements*/
	sum = (*head)->n + (*head)->next->n;
	/*Update the value of the second element with the sum*/
	(*head)->next->n = sum;
	/*Remove the first element from the stack*/
	current_node = *head;
	*head = (*head)->next;
	free(current_node);
}
