#include "main.h"
/**
 * exec_c - executes a given command
 * @command: command provided
 * @args: command argument
 * Return: exit to 0 or return error number
*/
int exec_c(char *command, char **args)
{
	int status;
	pid_t pid;
	int error = 0;

	pid = fork();
	if (!pid)
	{
		if (exec_c(command, args, environ) == -1)
		{
			freedom(1, command);
			command = NULL;
			errorcode = errorno;
			error_message(args);
			exit(errorcode);
		}
		else
		{
			freedom(1, command);
			command = NULL;
			exit(errorcode);
		}
	}
	else
		wait(&status);

	freedom(1, command);
	command = NULL;
	errorcode = 0;
	return (errorcode);
}
