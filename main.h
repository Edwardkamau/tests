#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stddef.h>
#include <ctype.h>

int execute_command(const char *command);

void handle_file(const char *filename);

void handle_arguments(int argc, char *argv[]);

void find_arguments(char *command);

void env_built_in();

void exit_built_in(int argc, char *argv[]);

void setenv_built_in(int argc, const char *argv[]);

void unsetenv_built_in(int argc, const char *argv[]);

void handle_cd(const char *directory_path);

void command_separator(const char *command);

void logical_operators(const char *command);

void alias_built_in(int argc);

void variable_replacement(char *command);

void _comments(char *command);

int _strlen(char *s);

void _puts(char *str);

int _putchar(char c);

void print_array(int *a, int n);

char *_strcpy(char *dest, char *src);

int _atoi(char *s);

char *_strcat(char *dest, char *src);

char *_strchr(char *s, char c);

void main_function(char *command);

#endif

