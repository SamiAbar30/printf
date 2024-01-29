#include "main.h"
/**
 * _printf - the number of characters printed.
 * @format: is a character string.
 * @...: A variable number of parameters to calculate the sum of.
 *
 * Return: counter for the number of characters written
 */
int _printf(const char *format, ...)
{

	int count = 0;

	va_list args;

	va_start(args, format);

	if (format != NULL || strlen(format) != 0)
	{
	while (*format != '\0')
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else
		{
			format++;
			switch (*format)
			{
				case 'd':
				case 'i':
					{
						int d = va_arg(args, int);
						char buffer[20];

						sprintf(buffer, "%d", d);

						write(1, buffer, strlen(buffer));
						count += strlen(buffer);
					}
						break;
				default:
					{
						write(2, "Invalid format specifier: %", 27);
						write(2, format, 1);
						write(2, "\n", 1);
						return (-1);
					}
			}
		}
		format++;
	}
	}
	else
	{
		fprintf(stderr, "Invalid format string: %s\n", format);
		exit(1);
	}
	va_end(args);
	return (count);
}
