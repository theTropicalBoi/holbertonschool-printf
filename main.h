#ifndef MAIN_H
#define MAIN_H

/* Library: */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdarg.h>

/* Specifier Structure */
typedef struct specifier
{
	char specifier;
	int (*f)(va_list);
} specifier_t;


/**
 * <unistd> library can't be used:
 * "Squiggles are disabled for this translation unit"
 * NULL as been defined manually to be used.
*/
#define NULL ((void *)0);


/* Prototype: */
int _putchar(char c);
int _printf(const char *format, ...);

#endif
