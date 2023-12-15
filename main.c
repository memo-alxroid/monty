#include "monty.h"

/**
 * main - the start point of the monty interperter
 *
 * @argc: arguments count
 * @argv: arguments list
 *
 * Return: 0 on success 1 on fail
 *
 */


int main(int argc, char *argv[])
{
	int fileDiscriptor;
	const char *fileName;
	char *commands[1024];
	ssize_t numberOfChars;

	if (argc < 2 || argc > 2)
	{
		perror("USAGE: monty file");
		exit (EXIT_FAILURE);
	}

	fileName = argv[1];

	if (fileName == NULL)
	{
                perror("USAGE: monty file");
                exit (EXIT_FAILURE);
	}
	fileDiscriptor = open(fileName, O_RDONLY);
	if (fileDiscriptor == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fileName);
		exit (EXIT_FAILURE);
	}

	numberOfChars = read(fileDiscriptor, commands, 1024);
	if (numberOfChars == -1)
	{
		fprintf(stderr, "Error: Can't read file %s\n", fileName);
                exit (EXIT_FAILURE);
	}
	return (0);
}
