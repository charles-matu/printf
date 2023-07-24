#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: Pointer to keep track of the current position in the format string.
 * @list: List of arguments to be printed.
 *
 * Return: Width.
 *
 * Description: This function calculates and returns the width for printing
 * based on the format specifier.
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_i;
	int width = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(list, int);
			break;
		}
		else
		{
			break;
		}
	}

	*i = curr_i - 1;

	return (width);
}

