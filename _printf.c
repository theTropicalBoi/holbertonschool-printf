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

	int count = 0;

	for (int i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i + 1] == '%')
			{
				_putchar('%');
				count++;
			}
			else if (format[i + 1] == 'c')
			{
				char res = va_arg(arg_list, int);
				_putchar(res);
				count++;
			}
			else if (format[i + 1] == 's')
			{
				char *res = va_arg(arg_list, char *);
				for (int j = 0; res[j] != '\0'; j++)
					_putchar(res[j]);
					count++;
			}
			else
			{
				return (-1);
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
	}

	va_end(arg_list);
	return (count);
}
