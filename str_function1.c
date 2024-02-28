#include "header.h"
/**
 * my_strchr - Locate the first occurrence of a character in a string
 * @string: The string to search
 * @c: The character to search for
 * Return: A pointer to the first occurrence of the character in the string.
 * - NULL if the character is not found.
 */
char *my_strchr(const char *string, int c)
{
	const char *ptr = string;

	while (*ptr != '\0')
	{
		if (*ptr == c)
			return ((char *)ptr);
		ptr++;
	}
	return (NULL);
}
/**
 * _strcpy - Copy a string
 * @dest: Pointer to the destination buffer
 * @src: Pointer to the source string
 * Return: A pointer to the destination buffer (dest).
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
/**
 * _atoi - Convert a string to an integer
 * @s: Pointer to the string to convert
 * Return: The converted integer value.
 */
int _atoi(char *s)
{
	int i, num = 0;

	for (i = 0; s[i]; i++)
	{
		num *= 10;
		num += (s[i] - '0');
	}
	return (num);
}
/**
 * _itoa - Convert an integer to a string
 * @n: The integer to convert
 * Return: A pointer to a dynamically allocated string containing the string
 *   representation of the integer @n. The caller is responsible for freeing
 *   the allocated memory.
 */

char *_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buffer[i] = '\0';

	reverse_string(buffer, i);

	return (_strdup(buffer));
}
/**
 * is_positive_num - Check if a string represents a positive number
 * @str: Pointer to the string to check
 * Return:1 if the string represents a positive number.
 * - 0 if the string does not represent a positive number.
 */
int is_positive_num(char *str)
{
	int i;

	if (!str)
		return (0);
	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

