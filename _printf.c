#include "main.h"
/**
 * _printf - Print to the standard output according to a format
 * @format: list of types of arguments passed to the function
 * Return: Count 
 */

int _printf(const char *format, ...)
{
	va_list arg_list;
	va_start(arg_list, format);

	int count_index = 0;

	for (int i = 0; format[i] != '\0'; i++)
	{
		/* Check "%" to know if format or print need to print "%" */
		if (format[i] == '%')
		{
			i++;
			/* Print % sign if the next index is "%" or "\" */
			if (format[i + 1] == '%' || format[i + 1] == '\\' )
			{
				_putchar('%');
				count_index++;
			}
			/* Print a char: */
			else if (format[i + 1] == 'c')
			{
				char res = va_arg(arg_list, int);
				_putchar(res);
				count_index++;
			}
			/* Print a string: */
			else if (format[i + 1] == 's')
			{
				char *res = va_arg(arg_list, char *);
				for (int j = 0; res[j] != '\0'; j++)
					_putchar(res[j]);
					count_index++;
			}
			else
			{
				return (-1);
			}
		}
		/* Print the rest of the printf content: */
		else
		{
			_putchar(format[i]);
			count_index++;
		}
	}

	va_end(arg_list);
	return (count_index);
}
