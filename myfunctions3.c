#include "main.h"
#define BUFFER_SIZE 1024

/**
 * variable_replacement - handles variable replacement ($ and $$)
 *
 * @command: command passed by user
 *
 * Return: nothing
 */

void variable_replacement(char *command)
{
	char *dollar_sign;
	char *variable_name;
	char *variable_value;

	dollar_sign = strchr(command, '$');
	while (dollar_sign != NULL)
	{
		variable_name = dollar_sign + 1;
		variable_value = getenv(variable_name);

		if (variable_value != NULL)
		{
			memmove(dollar_sign, variable_value, _strlen(variable_value));
			dollar_sign += strlen(variable_value);
		}
		else
		{
			printf("variable not found: %s\n", variable_name);
			dollar_sign++;
		}
	
		dollar_sign = _strchr(dollar_sign, '$');
	}
}

/**
 * _comments - removes everything after the #
 *
 * @command: argument passed by user
 *
 * Return: nothing
 */

void _comments(char *command)
{
	char *comment_pos;

	comment_pos = strchr(command, '#');
	if (comment_pos != NULL)
	{
		*comment_pos = '\0';
	}
}

/**
 * handle_cd - changes current directory
 *
 * @directory_path: path to new current directory
 *
 * Return: nothing
 */

void handle_cd(const char *directory_path)
{
	char current_dir[BUFFER_SIZE];

	if (directory_path == NULL)
	{
		directory_path = getenv("HOME");
		if (directory_path == NULL)
		{
			_puts("cd: No home directory found\n");
			return;
		}
	}
	if (chdir(directory_path) == 0)
	{
		if (getcwd(current_dir, sizeof(current_dir)) != NULL)
			_puts(current_dir);
		else
			perror("getcwd");
	}
	else
	{
		perror("chdir");
	}
}

/**
 * command_separator - handles the command separator
 *
 * @command: command passed
 *
 * Return: nothing
 */

void command_separator(const char *command)
{
	char *token;
	char *command_copy;

	command_copy = strdup(command);
	token = strtok(command_copy, ";");
	while (token != NULL)
	{
		main_function(token);
		token = strtok(NULL, ";");
	}
	free(command_copy);
}
