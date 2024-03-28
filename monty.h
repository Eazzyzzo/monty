#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
	* struct stack_s - doubly linked list representation of a stack (or queue)
	* @n: integer
	* @prev: points to the previous element of the stack (or queue)
	* @next: points to the next element of the stack (or queue)
	*
	* Description: doubly linked list node structure
	* for stack, queues, LIFO, FIFO
	*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
	* struct OperationContext - context variables for operations
	* @argument: Value argument for the operation
	* @file_ptr: Pointer to the Monty file being processed
	* @line_content: Content of the current line being processed
	* @is_fifo: Flag whether the operation follows FIFO behavior
	* Description: Carries context variables through the program
	*/
typedef struct OperationContext
{
				char *argument;
				FILE *file_ptr;
				char *line_content;
				int is_fifo;
} OperationContext_t;

extern OperationContext_t operation_context;

/**
	* struct instruction_s - opcode and its function
	* @opcode: the opcode
	* @f: function to handle the opcode
	*
	* Description: opcode and its function
	* for stack, queues, LIFO, FIFO
	*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
void func_push(stack_t **head, unsigned int counter);
void func_pall(stack_t **head, unsigned int counter);
void func_pint(stack_t **head, unsigned int counter);
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void free_stack(stack_t *head);
void func_pop(stack_t **head, unsigned int counter);
void func_swap(stack_t **head, unsigned int counter);
void func_add(stack_t **head, unsigned int counter);
void func_nop(stack_t **head, unsigned int counter);
void func_sub(stack_t **head, unsigned int counter);
void func_div(stack_t **head, unsigned int counter);
void func_mul(stack_t **head, unsigned int counter);
void func_mod(stack_t **head, unsigned int counter);
void func_pchar(stack_t **head, unsigned int counter);
void func_pstr(stack_t **head, unsigned int counter);
void func_rotl(stack_t **head, unsigned int counter);
void func_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void func_queue(stack_t **head, unsigned int counter);
void func_stack(stack_t **head, unsigned int counter);
#endif
