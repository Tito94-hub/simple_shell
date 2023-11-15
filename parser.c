#include "main.h"
/**
 * sh_cmd - counts commands and options entered
 * @buffer: commands provided
 * Return: arguments
*/
int sh_cmd(char *buffer)
{
	int cmd = 0;
	char *delimit = " =:'\n''\t'";
	int i = 0;
	int j = 0;

	while (buffer[i] != '\0')
	{
		for (j = 0; delimit[j] != '\0'; j++)
		{
			if (buffer[i] == delimit[j])
			{
				cmd++;
				break;
			}
		}
		i++;
	}
	return (cmd + 1);
}

/**
 * parser - splits a given string
 * @buffer: string provided
 * @characters: number of elements
 * Return: tokened string
*/

char **parser(char *buffer, int characters)
{
	int count = 0;
	char *token = NULL;
	char *delimit = " :'\n''\t'";
	char **token_cmd = malloc(sizeof(char *) * characters);

	if (token_cmd == NULL)
	{
		return (NULL);
	}
	token = strtok(buffer, delimit);
	while (token != NULL)
	{
		token_cmd[count] = strduplicate(token);
		if (token_cmd[count] == NULL)
		{
			freedom(2, token_cmd);
			return (NULL);
		}
		token = strtok(NULL, delimit);
		count++;
	}
	token_cmd[count] = NULL;
	return (token_cmd);
}
