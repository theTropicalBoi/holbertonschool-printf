#include <main.h>
#include <stdarg.h>

/**
 * _printf - function that produces output according to a format
 * @format: list of types of arguments passed to the function
 *
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
				putchar('%');
				count++;
			}
			else if (format[i + 1] == 'c')
			{
				char res = va_arg(arg_list, int);
				putchar(res);
				count++;
			}
			else if (format[i + 1] == 's')
			{
				char *res = va_arg(arg_list, char *);
				for (int j = 0; res[j] != '\0'; j++)
					putchar(res[j]);
					count++;
			}
			else
			{
				return (-1);
			}
		}
		else
		{
			putchar(format[i]);
			count++;
		}
	}

	va_end(arg_list);
}
