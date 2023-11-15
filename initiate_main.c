#include "main.h"
/**
 * interactive_main - provides a loop that execute command lines entered
 * @av: argument from main
 * Return: Exit / Error Code
*/
int_interactive(char **av __attribute__((unused)))
{
	size_t bufsiz;
	char *buffer = NULL;
	char **env_args = NULL;
	char **u_command = NULL;
	int (*b_func)() = NULL;
	char *full_command = NULL;

	while (1)
	{
		write(STDOUT_FILENO, "($) ", 4);
		getline(&buffer, &bufsiz, stdin);
		valid_getline(buffer, 0, u_command, env_args);
		if (buffer[0] == 10 || buffer[0] == 9)
			continue;
		u_command = args_construct(buffer);
		if (u_command == NULL)
			continue;
		b_func == builtin_main(*u_command);
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
		freedom(2, env_args), env_args = NULL;
	}
	return (0);
}
