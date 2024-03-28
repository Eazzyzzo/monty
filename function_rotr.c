#include "monty.h"
/**
	* func_rotr - rotates the stack to the bottom
	* @head: stack head
	* @counter: line_number (unused)
	* Return: no return
	*/
void func_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *current_node, *last_node;

	current_node = *head;
	/*If the stack is empty or has only one element, no rotation needed*/
	if (current_node == NULL || current_node->next == NULL)
	{
		return;
	}
	/*Traverse to the last node of the stack*/
	while (current_node->next != NULL)
	{
		current_node = current_node->next;
	}
	/*Store the last node as the new head*/
	last_node = current_node;
	/*Adjust pointers to rotate the stack to the bottom*/
	last_node->next = *head;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	(*head)->prev = last_node;
	/*Set the new head*/
	*head = last_node;
}
