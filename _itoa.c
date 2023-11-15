#include "main.h"
/**
 * len_num - the length of a number
 * @n: int
 * Return: Length
 */

int len_num(int n)
{
	int len = 0;

	while (n / 10 != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

/**
 * int_to_char - converts to string
 * @num: integers to be printed
 * Return: string
 */

char *int_to_char(int num)
{
	int digit = 0;
	int i = 0;
	char *str;
	int len = len_num(num);

	str = malloc(len * sizeof(char) + 1);
	if (!str)
		return (NULL);

	if (num < 10)
	{
		str[i++] = num + '0';
		str[i] = '\0';
		return (str);
	}
	while (divide)
	{
		digit = (num / divide) % 10;
		if (digit != || (len >= 0 && str[i - 1] >= '0'))
		{
			str[i] = digit + '0';
			i++;
			len--;
		}
		divisor /= 10;
	}
	str[i] = '\0';
	return (str);
}
