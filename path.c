#include "main.h"

#define MAX_PATH_LENGTH 100
#define BUFFER_SIZE 1024
#define MAX_COMMAND_LENGTH 100

/**
 * execute_command - handles the path
 *
 * @command: command input by user
 *
 * Return (0);
 */

int execute_command(const char *command)
{
	char *path_token;
	char command_path[MAX_PATH_LENGTH + MAX_COMMAND_LENGTH];
	const char *path_env;

	path_env =getenv("PATH");
	if (path_env == NULL)
	{
		printf("Error: PATH environmentvariable not found\n");
		return(0);
	}
	path_token = strtok((char *)path_env, ":");
	while (path_token != NULL)
	{
		sprintf(command_path, "%.*s/%s", MAX_PATH_LENGTH, path_token, command);
		if (access(command_path, X_OK) == 0)
		{
			printf("Executing command: %s\n", command_path);
			system(command_path);
			return (0);
		}
		path_token = strtok(NULL, ":");
	}
	printf("command not found: %s\n", command);
	return (0);
}

/**
 * handle_file - handles file input
 *
 * @filename: name of the file
 *
 * Return: nothing
 */

void handle_file(const char *filename)
{
	FILE *file;
	char input[BUFFER_SIZE];

	file = fopen(filename, "r");
	if (file == NULL)
	{
		perror("fopen");
		return;
	}
	while (fgets(input, BUFFER_SIZE, file))
	{
		input[strcspn(input, "\n")] = '\0';
		main_function(input);
	}
	fclose(file);

}

/**
 * main_function - handles main functionality
 *
 * Return: nothing
 */

void main_function(char *command)
{
	char *command_token;
	char *arguments[2];
	int i;

	command_token = strtok(command, " ");
	i = 0;

	while (command_token != NULL)
	{
		arguments[i] = command_token;
		i++;
	}
	
	execute_command(arguments[0]);
	free(command);
}
