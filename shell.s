#include "main.h"
/**
 * main - entry point of Shell
 * @ac: arguments counter
 * @av: argument values
 * Return: if success = 0
*/

int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{

	int int_mode = 1;
	int errorcode = 0;


	errorcode = errcode + 0;

	int_mode = isatty(STDIN_FILENO);
	if (int_mode == 0)
	{
		noutty(av);
	}
	else
	{

		_interactive(av);
	}
	return (0);
}
