#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

extern int info;

/**
 * struct cmd_s - cmd
 * @fd: file descriptor
 * @line: line
 */

typedef struct cmd_s
{
	FILE *fd;
	char *line;
} cmd_t;

/*extern cmd_t cmd;*/
extern int value;



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

void process_line(stack_t **stack, char *line, int current_line);
void execute(char *montyfile);
int find_opc(stack_t **stack, char *instruction, char *value_str, int line_num);
void usage_error(void);
void open_error(char *file);
void push_error(FILE *fd, char *buf, stack_t *stack, int line_number);
void unknown_ins(FILE *fd, char *buf, stack_t *stack, char *val, int line_num);
int is_digit(const char *str);

stack_t *createNode(int n);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
void clean_stack(stack_t **stack);













#endif
