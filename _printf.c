#include "main.h"
/**
 * _printf - the number of characters printed.
 * @format: is a character string.
 * @...: A variable number of paramters to calculate the sum of.
 *
 * Return: counter for the number of characters written
 */
int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int count = 0;

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
				case 'c':
					{
						char c = (char)va_arg(args, int);

						write(1, &c, 1);
						count++;
					}
					break;
				case 's':
					{
						char *s = va_arg(args, char *);

						while (*s != '\0')
						{
							write(1, s, 1);
							count++;
							s++;
						}
					}
					break;
				case '%':
					{
						write(1, "%", 1);
						count++;
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
	va_end(args);
	return (count);
}
