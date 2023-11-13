#include "main.h"

/**
 * ret_path_line - identifies PATH variable from env
 * Return: pointer PATH variable
*/

char *ret_path_line()
{
	char *path = NULL;
	int i = 0;

	for (i = 0; env[i] != NULL; i++)
	{
		if (strchecker(env[i], "PATH") == 0)
		{
			path = malloc(sizeof(char *) * (strlarge(env[i])));
			if (path == NULL)
			{
				freedom(1, path);
				exit(-1);
			}
			_strcpy(path, env[i]);
			break;
		}
	}
	return (path);
}

/**
 * modify_sig - Change from a given strings = to : character
 * @str:  string provided
 * Return: 0
*/

void modify_sig(char *str)
{
	char **ptr_str = NULL;
	int i = 0;

	ptr_str = &str;

	while ((*(*ptr_str + i)) != '=')
	{
		(*(*ptr_str + i)) = ':';
		i++;
	}
	(*(*ptr_stgr + i)) = ':';
}

/**
 * fix_path - fixes the directory into given command
 * @args: command given
 * @path: tokenized path enviroment
 * Return: path command or just a given command
*/

char *fix_path(char **args, char **path)
{
	char *cwd = getcwd(NULL, 0);
	struct stat verify;
	int counter = 0;
	int count_char = 0;
	char *tmp2 = NULL;
	char *dirpath = NULL;

	if (_strstr(args[0], "/") || _strstr(args[0], "."))
	{
		freedom(1, cwd);
		cwd = NULL;
		tmp2 = malloc(sizeof(char *) * (strbig(args[0])));
		_strcpy(tmp2, args[0]);
		return (tmp2);
	}
	else
	{
		while (path[counter] != NULL)
		{
			chdir(path[counter]);
			if (stat(args[0], &verify) == 0)
			{
				count_char = strbig(path[counter]) + 1 + strbig(args[0]);
				tmp2 = malloc(sizeof(char *) * count_char);
				_strcpy(tmp2, path[counter]);
				strconk(tmp2, "/"), strconk(tmp2, args[0]);
				break;
			}
			counter++;
		}
	}
	chdir(cwd);
	if (tmp2 == NULL)
	{
		freedom(1, cwd), cwd = NULL;
		freedom(1, tmp2), tmp2 = NULL;
		return (dirpath);
	}
	dirpath = tmp2, freedom(1, cwd), cwd = NULL;
	return (dirpath);
}

/**
 * get_env_path - create an array of pointers to the PATH directories
 * Return: Pointer to an array
 */

char **get_env_path()
{
	char *tmp = NULL;
	int size_args = 0;
	char **env_args;

	tmp = get_path_line();
	modify_sig(tmp); /*Change  PATH= for PATH:*/
	size_args = necklace_pearls(tmp);
	env_args = parsing(tmp, size_args);
	freedom(1, tmp);
	tmp =  NULL;
	return (env_args);
}

/**
 * space_finder - Creates an array of pointers to the PATH directories
 * @buffer: string provided
 * Return: Pointer to  array of token directories
*/

int space_finder(char *buffer)
{
	int i = 0;

	while (buffer[i] != '\0')
	{
		if (buffer[i] != 32)
		{
			return (0);
		}
	i++;
	}
	return (1);
}
