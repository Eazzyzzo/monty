#include "monty.h"
/**
	* func_pchar - prints the char at the top of the stack,then a new line
	* @head: stack head
	* @counter: line_number
	* Return: no return
	*/
void func_pchar(stack_t **head, unsigned int counter)
{
	stack_t *current_node = *head;
	/*Check if the stack is empty*/
	if (!current_node)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(operation_context.file_ptr);
		free(operation_context.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	/*Check if the value is in the ASCII range*/
	if (current_node->n > 127 || current_node->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(operation_context.file_ptr);
		free(operation_context.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	/*Print the character at the top of the stack*/
	printf("%c\n", current_node->n);
	/*Remove the first element from the stack*/
	*head = (*head)->next;
	free(current_node);
}
