#include "monty.h"
/**
	* func_stack - sets the format of the data to a stack (LIFO)
	* @head: stack head
	* @counter: line_number (unused)
	* Return: no return
	*/
void func_stack(stack_t **head, unsigned int counter)
{
	/*Silence compiler warnings for unused parameters*/
	(void)head;
	(void)counter;
	/*Set the format of the data to stack (LIFO)*/
	operation_context.is_fifo = 0;
}
