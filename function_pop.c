#include "monty.h"
/**
	* func_pop - removes the top element of the stack
	* @head: stack head
	* @counter: line_number
	* Return: no return
	*/
void func_pop(stack_t **head, unsigned int counter)
{
	stack_t *temp;
/*Check if the stack is empty*/
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(operation_context.file_ptr);
		free(operation_context.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;/*Store the address of the top element in temp*/
	*head = (*head)->next;/*Move head to the next element*/
	free(temp);/*Free the memory allocated for the top element*/
}
