#include "monty.h"
/**
	* addnode - add node to the head of the stack
	* @head: pointer to the head of the stack
	* @n: value to be added to the new node
	* Return: no return
	*/
void addnode(stack_t **head, int n)
{
	stack_t *new_node;
	/*Allocate memory for the new node*/
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	/*Assign values to the new node*/
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;
	/*Update the previous pointer of the old head, if it exists*/
	if (*head != NULL)
	{
		(*head)->prev = new_node;
	}
	/*Update the head pointer to point to the new node*/
	*head = new_node;
}
