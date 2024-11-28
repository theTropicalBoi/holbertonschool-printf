#include "main.h"
/**
 * _printf - Print to the standard output according to a format
 * @format: list of types of arguments passed to the function
 * Return: count_index
 */

int _printf(const char *format, ...)
{
	int count_index = 0; /* Var used to use the for % if/else loop */
	int i;

	va_list arg_list;

	if (!format)
		return (-1);

	va_start(arg_list, format);

	/*  Check format until the null bytes */
	for (i = 0; format[i] != '\0'; i++)
	{
		/* Check "%" to know if format or print need to print "%" */
		if (format[i] == '%')
		{
			i++; /* Increment to check the next character */

			/* If format is the null byte return -1 */
			if (format[i] == '\0')
			{
				return (-1);
			}

			/* Print percentage if the next index is "%" or "\" */
			if (format[i] == '%' || format[i] == '\\' )
			{
				count_index = count_index + format_percent(arg_list);
			}
			/* Print char: */
			else if (format[i] == 'c')
			{
				count_index = count_index + format_char(arg_list);
			}
			/* Print string: */
			else if (format[i] == 's')
			{
				count_index = count_index + format_string(arg_list);
			}
			/* Print int: */
			else if (format[i] == 'd' || format[i] == 'i')
			{
				count_index = count_index + format_int(arg_list);
			}
		}
		else /* If [i] is not % write the char and incrmenent */
		{
			write(1, &format[i], 1);
			count_index++;
		}
	}
	va_end(arg_list);
	return (count_index);
}
