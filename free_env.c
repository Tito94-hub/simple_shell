#include "main.h"
/**
* free_env - it frees PATH directories (tokenized) and users arguments
* @env_args: tokenized environment directories
* @args: tokenized users commands
* Return: nothing
*/

void free_env(char **env_args, char **args)
{
	if (env_args != NULL)
	{
		freedom(2, env_args);
	}
	freedom(2, args);
}
