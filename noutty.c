#include "main.h"
/**
 * noutty - executes commands entered by pipe
 * @av: program description
 * Return: 0
*/
int noutty(char **av __attribute__((unused)))
{
	size_t bufsiz;
	int len = 0;
	char *buffer = NULL;
	char **env_args = NULL;
	char **u_command = NULL;
	char *full_command = NULL;
	int (*b_func)() = NULL;

	while ((len = getline(&buffer, &bufsiz, stdin)) > 0)
	{
		valid_getline(buffer, len, u_command, env_args);
		if (buffer[0] == 10 || buffer[0] == 9)
			continue;
		u_command = args_construct(buffer);
		if (u_command == NULL)
			continue;
		b_func = builtin_main(*u_command);
		if (b_func)
		{
			if (b_func == exit_func)
				free_all(u_command, env_args, buffer, NULL);
			b_func();
			free_all(u_command, NULL, NULL, NULL);
			continue;
		}
		env_args = getenvpath();
		if (env_args == NULL)
			return (-1);
		full_command = fix_path(u_command, env_args);
		if (full_command == NULL)
			write(STDOUT_FILENO, "command NOT found\n", 18);
		else
			exec(full_command, u_command);
		freedom(1, buffer), buffer = NULL;
		freedom(2, u_command), u_command = NULL;
		freedom(2, env_args), env_args  = NULL;
	}
	freedom(1, buffer), buffer = NULL;
	return (0);
}
