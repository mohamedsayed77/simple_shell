#include "header.h"
/**
 * _strdup - Duplicate a string
 * @str: Pointer to the string to duplicate
 * Return: A pointer to a newly allocated copy of the input string.
 * - NULL if the input string is NULL or if memory allocation fails.
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}
/**
 * _strcmp - Compare two strings
 * @s1: Pointer to the first string to compare
 * @s2: Pointer to the second string to compare
 * Return:An integer less than, equal to,
 *  or greater than 0 if the first string is
 *   lexicographically less than, equal to, or greater than the second string,
 *   respectively.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}
/**
 * _strlen - Calculate the length of a string
 * @s: Pointer to the string to measure
 * Return: The number of characters in the string pointed
 * to by @s (excluding the null
 *   terminator), or 0 if the string is NULL (empty).
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}
/**
 * _strcat - Concatenate two strings
 * @dest: Pointer to the destination string
 * @src: Pointer to the source string
 *
 * Return: A pointer to the beginning of the destination string
 *  after concatenation.
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
/**
 * reverse_string - Reverse the characters in a string
 * @str: Pointer to the string to reverse
 * @len: Length of the string
 * Return: None. The string is modified in place.
 */

void reverse_string(char *str, int len)
	{
		char tmp;
		int start = 0;
		int end = len - 1;

		while (start < end)
		{
			tmp = str[start];
			str[start] = str[end];
			str[end] = tmp;
			start++;
			end--;
		}
	}
