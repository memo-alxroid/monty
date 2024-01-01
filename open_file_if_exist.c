#include "monty.h"

/**
 * open_file_if_exist - open file if exist
 *
 * @fileName: file name
 *
 * Return: file pointer or NULL
 */

FILE *open_file_if_exist(const char *fileName)
{
	FILE *filePointer;

	if (fileName == NULL)
	{
		perror("USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	filePointer = fopen(fileName, "r");
	if (filePointer == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fileName);
		exit(EXIT_FAILURE);
	}
	return (filePointer);
}
