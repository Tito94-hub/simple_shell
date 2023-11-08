#include "main.c"
/**
 * env_main - prints environment variables
 * Return: 0 on success
 */

int env_main(void)
{
	int counter = 0, length = 0;

	while (env[counter] != NULL)
	{
		length = strlarge(env[counter]);
		write(STDOUT_FILENO, env[counter], length);
		write(STDOUT_FILENO, "\n", 1);
		counter++;
	}
	return (0);
}
