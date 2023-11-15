#include "main.h"
/**
 * main - entry point of Shell
 * @ac: arguments counter
 * @av: argument values
 * Return: if success = 0
*/

int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{

	int int_mod = 1;
	int errorcode = 0;


	errorcode = errcode + 0;

	int_mod = isatt(STDIN_FILENO);
	if (int_mod == 0)
	{
		noutty(av);
	}
	else
	{

		_interactive(av);
	}
	return (0);
}
