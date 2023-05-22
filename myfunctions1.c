#include "main.h"

/**
 * handle_argument - handles various input arguments
 *
 * @argc: number of arguments
 * @argv: components of the argument
 *
 * Return: nothing
 */

void handle_arguments(int argc, char *argv[])
{
	int i;
	for (i = 1; i < argc; i++)
	{
		main_function(argv[i]);
	}
}

/**
 * find_arguments - searches for arguments in commandline
 *
 * @command: command entered in the commandline
 *
 * Return: nothing
 */

void find_arguments(char *command)
{
	char *token;
	char *command_copy;
	char *arguments[10];
	int i;

	command_copy = strdup(command);
	token = strtok(command_copy, " ");
	i = 0;

	while (token != NULL)
	{
		arguments[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	arguments[i] = NULL;
	execute_command(arguments[0]);
	free(command_copy);
}

/**
 * env_built_in - prints environment
 *
 * Return: Nothing
 */

void env_built_in(void)
{
	char **environ = NULL;
	int i;

	for (i = 0; ((environ[i]) != NULL); i++)
	{
		_puts(environ[i]);
		_putchar('\n');
	}
}

/**
 * exit_built_in - Implements the exit built-in command
 *
 * Return: Nothing
 */

void exit_built_in(int argc, char *argv[])
{
	int status, i = 0;

	if (argc > 2)
	{
		_puts("exit: too many arguments\n");
		return;
	}
	if (argc == 1)
		exit(EXIT_SUCCESS);
	status = _atoi(argv[i]);
	exit(status);
}
