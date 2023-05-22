#include "main.h"

#define BUFFER_SIZE 1024

/**
 * main - entry point
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char input[BUFFER_SIZE];
	while (1)
	{
		_puts("$ ");
		if (fgets(input, BUFFER_SIZE,stdin) == NULL)
		{
			break;
		}

		input[strspn(input, "\n")] = '\0';
		execute_command(input);
	}
	return (0);
}
