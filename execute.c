#include "monty.h"
/**
	* execute - executes the opcode
	* @content: line content
	* @stack: head linked list - stack
	* @counter: line_counter
	* @file: pointer to monty file
	* Return: no return
	*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
								{"push", func_push}, {"pall", func_pall}, {"pint", func_pint},
								{"pop", func_pop},
								{"swap", func_swap},
								{"add", func_add},
								{"nop", func_nop},
								{"sub", func_sub},
								{"div", func_div},
								{"mul", func_mul},
								{"mod", func_mod},
								{"pchar", func_pchar},
								{"pstr", func_pstr},
								{"rotl", func_rotl},
								{"rotr", func_rotr},
								{"queue", func_queue},
								{"stack", func_stack},
								{NULL, NULL}
				};
	unsigned int i = 0;
	char *operation;

	operation = strtok(content, " \n\t");
	if (operation && operation[0] == '#')
		return (0);
	operation_context.argument = strtok(NULL, " \n\t");
	while (opst[i].opcode && operation)
	{
		if (strcmp(operation, opst[i].opcode) == 0)
		{
			opst[i].f(stack, counter);
			return (0);
		}
			i++;
	}
	if (operation && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, operation);
		fclose(file);
		free(operation_context.line_content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
return (1);
}

