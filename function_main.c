#include <stdio.h>

/**
 * check - check and compare two strings at a given position
 * @x: string to check and compare
 * @y: string to check and compare
 * Return: 0
*/
int check_compare(char *x, char *y)
{
	while (*x && *y)
	{
		if (*x != *y)
			return (0);

		x++;
		y++;
	}

	return (*y == '\0');
}

/**
 * strstr_ - compares two strings at a given position
 * @y: string to be check and compare
 * @x: string to compare
 * Return: pointer first result
*/
char *_strstr(char *x, char *y)
{
	while (*x != '\0')


	if ((*x == *y) && _compare(x, y))
		return (x);
		x++;

		return (NULL);
}


/**
 * _strcpy - copies the string pointed to by src
 *@dest: char
 *@src:_ char
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0, j;

	while (src[i] != '\0')
	{
		i++;
	}
	for (j = 0; j <= i; j++)
	{
		dest[j] = src[j];
	}
	return (dest);
}
