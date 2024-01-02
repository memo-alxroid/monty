#include "monty.h"

stack_t **global_head;

/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	FILE *filePointer;
	const char *fileName;
	stack_t *head;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	
	head = NULL;
	global_head = &head;
	
	fileName = argv[1];
	filePointer = open_file_if_exist(fileName);
	read_commands_from_file(filePointer, &head);
	atexit(global_free);
	exit(EXIT_SUCCESS);
}
