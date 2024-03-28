#include "monty.h"
/**
	* func_rotl - rotates the stack to the top
	* @head: stack head
	* @counter: line_number (unused)
	* Return: no return
	*/
void func_rotl(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *current_node;
	stack_t *second_node;

	if (*head == NULL || (*head)->next == NULL)
	{
		/*If the stack is empty or has only one element, no rotation needed*/
		return;
	}
	/*Declare temporary pointers for manipulation*/
	current_node = *head;
	/*Traverse to the last node of the stack*/
	while (current_node->next != NULL)
	{
		current_node = current_node->next;
	}
	/*Make the second node the new head*/
	second_node = (*head)->next;
	second_node->prev = NULL;
	/*Link the last node to the current head*/
	current_node->next = *head;
	(*head)->prev = current_node;
	/*Set next of the current head to NULL*/
	(*head)->next = NULL;
	/*Set the new head*/
	*head = second_node;
}
