#include "monty.h"

/**
	* func_pall - prints the stack
	* @head: stack head
	* @counter: not used
	* Return: no return
	*/
void func_pall(stack_t **head, unsigned int counter)
{
	stack_t *current_node;
	(void)counter;

	current_node = *head;
/*Check if the stack is empty*/
	if (current_node == NULL)
	{
		return;
	}
/*Traverse the stack and print each element*/
	while (current_node != NULL)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next; /*Move to the next node*/
	}
}
