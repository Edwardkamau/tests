#include "main.h"

/**
 * _strlen - returns the length of a string
 *
 * @s: The string
 * 
 * Return: length of a string
 */

int _strlen(char *s)
{
        int i;

        for (i = 0; s[i] != '\0'; i++)
				                ;
        return (i);
}

/**
 * _puts - prints a string
 *
 * @str: the string
 *
 * Return: length of the string
 */

void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}

}


/**
 * print_array - prints n times the elements of an array
 * @a: the pointer to the elements
 * @n: times to print elements
 */

void print_array(int *a, int n)
{
	int i;

	for (i = 0 ; i < n ; i++)
	{
		printf("%d", a[i]);
		if (i < n - 1)
		{
			printf(", ");
		}
	}
	putchar('\n');
}

/**
 * _strcpy - copie the string
 * @dest: array that returns
 * @src: the pointer that receive the string
 *
 * Return: the parameter dest.
 */

char *_strcpy(char *dest, char *src)
{
	int n = 0;
	int i;

	while (src[n] != '\0')
	{
		n++;
	}

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	i = i;
	while (i <= n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/**
 * _atoi - function with one argument
 * @s: char type pointer argument
 *
 * Description: convert a string to an integer
 * Return: value of s
 */

int _atoi(char *s)
{
	int i, sign, numb;

	i = 0;
	sign = 1;
	numb = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			while (s[i] >= '0' && s[i] <= '9')
			{
				numb = (s[i] - '0') * sign + numb * 10;
				i++;
			}
			break;
		}
		i++;
	}
	return (numb);
}


