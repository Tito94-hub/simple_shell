#include "main.h"
/**
 * valid-getline - execute commands entered by pipe
 * @buffer: program description
 * @len: length buffer
 * @args: argument 1
 * @env_args: env argument
 * Return: 0
*/
void valid_getline(char *buffer, int len, char **args, char **env_args)
{
	if (len == EOF)
	{
		printf("salida EOF\n");
		write(STDOUT_FILENO, "\n", 1);
		if (buffer != NULL)
		{
			freedom(1, buffer);
			buffer = NULL;
		}
		if (args != NULL)
		{
			freedom(2, args);
			args = NULL;
		}
		if (env_args != NULL)
		{
			freedom(2, env_args);
			env_args = NULL;
		}
		ext(0);
	}
}
