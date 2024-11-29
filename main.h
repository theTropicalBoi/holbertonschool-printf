#ifndef MAIN_H
#define MAIN_H

/* Library: */
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


/* Prototype: */
int _putchar(char c);
int _printf(const char *format, ...);

/* Prototype for _printf function: */
int format_char(va_list arg_list); /* print the char format */
int format_string(va_list arg_list); /* print the string format */
int format_percent(va_list arg_list); /* print the percent */
int format_int(va_list arg_list); /* print the int format */

#endif
