#include "shell.h"

/**
 * split_string - exactly what it says on the tin
 * @string_to_split: the string we are breaking up
 * @delimiter: where we are breaking the string up
 * Return: A double pointer which is a list of strings split up
 */
char **split_string(char *string_to_split, char *delimiter)
{
	char **ret_array;
	int i = 0;
	long int length = num_of_spaces(string_to_split, delimiter);
	char copy_of_string[255];
	char *save_pointer;
	char *grabtok;

	snprintf(copy_of_string, 255, "%s", string_to_split);

	ret_array = malloc(sizeof(char *) * (length + 1));
	save_pointer = copy_of_string;

	for (i = 0; i < length; i++)
	{
		grabtok = strtok_r(save_pointer, delimiter, &save_pointer);
		ret_array[i] = malloc(sizeof(char) * 255);
		snprintf(ret_array[i], 255, "%s", grabtok);
	}
	ret_array[i] = NULL;

	return (ret_array);
}
/**
 * num_of_spaces - Counts the number of buckets to allocate to store the data
 *               when given a string delimiter of the data
 * @string: The string to evaluate
 * @delimiter: The string that is breaking up str
 * Return: The number of spaces to store the data, trailing NULL excluded
 */
int num_of_spaces(char *string, char *delimiter)
{
	int i = 0;
	int count = 1;
	int has_space = TRUE;
	char delim = delimiter[0];

	if (string[i] == '\0' || string == NULL)
		return (0);

	while (string[i] != '\0')
	{
		if (string[i] == delim)
		{
			if (has_space == 0)
			{
				count++;
				has_space = TRUE;
			}
		}
		else
			has_space = FALSE;
		i++;
	}
	return (count);
}

