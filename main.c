#include "monty.h"

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
	char commands[1024];

	if (argc < 2 || argc > 2)
	{
		perror("USAGE: monty file");
		exit(EXIT_FAILURE);
	}

	fileName = argv[1];
	filePointer = open_file_if_exist(fileName);

	return (read_commands_from_file(commands, filePointer));
}
