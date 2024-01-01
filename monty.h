#ifndef MONTY_H_
#define MONTY_H_
#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
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

FILE *open_file_if_exist(const char *fileName);
void read_commands_from_file(char *commands, FILE *filePointer);
void (*get_op_function(char *opcode))(stack_t **stack, unsigned int line_number);
void execute_command_if_exist(char *command, stack_t **stack, unsigned int lineNumber);
void pushOP(stack_t **stack, unsigned int line_number);
void pallOP(stack_t **stack, unsigned int line_number);
void pintOP(stack_t **stack, unsigned int line_number);
void popOP(stack_t **stack, unsigned int line_number);
void swapOP(stack_t **stack, unsigned int line_number);
void addOP(stack_t **stack, unsigned int line_number);
void nopOP(stack_t **stack, unsigned int line_number);

#endif