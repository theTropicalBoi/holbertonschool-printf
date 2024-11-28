#ifndef MAIN_H
#define MAIN_H

/* Library: */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdarg.h>
#include <unistd.h>


/* Specifier Structure */
typedef struct specifier
{
	char specifier;
	int (*f)(va_list);
} specifier_t;


/**
 * "Squiggles are disabled for this translation unit"
 * NULL as been defined manually to be used.
*/
#define NULL ((void *)0);


/* Prototype: */
int _putchar(char c);
int _printf(const char *format, ...);

/* Prototype for _printf function: */
int format_char(va_list args); /* print the char format */
int format_string(va_list args); /* print the string format */
int format_percent(va_list args); /* print the percent */
int format_int(va_list args); /* print the int format */
int conv_int_to_str(); /* convert int to string */

#endif
