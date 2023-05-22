#include "main.h"

/**
 * set_env_built_in - implements setenv built-in command
 *
 * @argc: number of arguments
 * @argv: components of arguments
 *
 * Return: nothing
 */

void setenv_built_in(int argc, const char *argv[])
{
	if (argc == 1 || argc > 3)
	{
		_puts("setenv: Invalid number of arguments\n");
		return;
	}
	if (argc == 2)
	{
		if (setenv(argv[1], "", 1) != 0)
			perror("setenv");
	}
	else
	{
		if (setenv(argv[1], argv[2], 1) != 0)
			perror("setenv");
	}
}

/**
 * unsetenv_built_in - Implements unsetenv built-in
 *
 * @argc: number of arguments
 * @argv: components of arguments
 *
 * Return: nothing
 */

void unsetenv_built_in(int argc, const char *argv[])
{
	int i;

	if (argc == 1)
	{
		_puts("unsetenv: Too few arguments\n");
		return;
	}
	for (i =1; i < argc; i++)
	{
		if (unsetenv(argv[i]) != 0)
			perror("unsetenv");
	}
}

/**
 * logical_operators - handles the logical operators, && and ||
 *
 * @commands: commands passed by the user
 *
 * Return: nothing
 */

void logical_operators(const char *command)
{
	int status;
	char *token;
	char *command_copy;
	int previous_status = 1;

	command_copy = strdup(command);
	token = strtok(command_copy, "&|");
	while (token != NULL)
	{
		status = execute_command(token);

		if (token[_strlen(token) - 1] == '&')
		{
			if (previous_status == 0 && status == 0)
				previous_status = 0;
			else
				previous_status = 1;
		}
		else if (token[strlen(token) - 1]  == '|')
		{
			if (previous_status == 0 || status == 0)
				previous_status = 0;
			else
				previous_status = 1;
		}
		token = strtok(NULL, "&|");
	}
	free(command_copy);
}

/**
 * alias_built_in - Implements alias built-in command
 *
 * @argc: number of arguments
 * @argv: components of arguments
 *
 * Return: nothing
 */

void alias_built_in(int argc)
{
	if (argc == 1)
	{
		_puts("alias: Too few arguments\n");
		return;
	}
}
