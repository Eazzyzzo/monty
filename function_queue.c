#include "monty.h"
/**
	* func_queue - sets the format of the data to a queue (FIFO)
	* @head: stack head
	* @counter: line_number (unused)
	* Return: no return
	*/
void func_queue(stack_t **head, unsigned int counter)
{
	/*Silence compiler warnings for unused parameters*/
	(void)head;
	(void)counter;
	/*Set the format of the data to a queue (FIFO)*/
	operation_context.is_fifo = 1;
}

/**
	* addqueue - add node to the tail of the queue
	* @head: head of the queue
	* @n: new value
	* Return: no return
	*/
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *current_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
	/*If the queue is empty, set the new node as the head*/
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		/*Otherwise, traverse the queue to the last node*/
		current_node = *head;
		while (current_node->next != NULL)
		{
			current_node = current_node->next;
		}
	/*Add the new node to the end of the queue*/
		current_node->next = new_node;
		new_node->prev = current_node;
	}
}
