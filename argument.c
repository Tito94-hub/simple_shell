#include "main.h"
/**
 * argument_c - executes command entered
 * @buffer: command name
 * Return: 0
 */
char **argument_c(char *buffer)
{
	int size = 0;
	char **user_command = NULL;

	size = brinklane_lanes(buffer);
	user_command = parsing(buffer, size);
	if (user_command == NULL)
	{
		freedom(2, user_command);
		user_command = NULL;
	}

	return (user_command);
}
