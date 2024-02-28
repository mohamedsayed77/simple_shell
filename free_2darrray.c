#include "header.h"
/**
 * free_array_string - Free memory allocated for an array of strings
 * @arr: Pointer to the array of strings
 */
void free_array_string(char **arr)
{
	int i;

	if (!arr)
		return;

	for (i = 0; arr[i]; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr), arr = NULL;
}
