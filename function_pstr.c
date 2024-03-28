#include "monty.h"
/**
	* func_pstr - prints string starting at the top of the stack, then newline
	* @head: stack head
	* @counter: line_number
	* Return: no return
	*/
void func_pstr(stack_t **head, unsigned int counter)
{
	stack_t *current_node;

	(void) counter;
	current_node = *head;
	/*Iterate stack and print characters*/
       /*until null byte or out-of-range ASCII value is met*/
	while (current_node && current_node->n > 0 && current_node->n <= 127)
	{
		printf("%c", current_node->n);
		current_node = current_node->next;
	}
	/*Print a new line after printing the string*/
	printf("\n");
}
