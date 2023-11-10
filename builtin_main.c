#include "main.h"
/**
**builtin_main -  finds whether user's command is a builtin
** @user_input: user's command
**Return: pointer to a function builtin or NULL if doesn't exists
**/
int (*builtin_main(char *user_input))()
{
	int counter = 0, stru_size = 0;

	builtin_struct my_builtins[] = {
		{"exit", exit_main},
		{"env", env_main},
	};

	str_size = (sizeof(my_builtins) / sizeof(builtin_struct));
	if (user_input != NULL)
	{
		while (counter < str_size)
		{
			if (strcomparer(my_builtins[counter].b_name, user_input) == 0)
				return (my_builtins[counter].b_func);
			counter++;
		}
	}
	return (NULL);
}

