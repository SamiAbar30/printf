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
	int count = 0;

	va_list args;

	va_start(args, format);
	if (format)
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
						if (s == NULL)
						{
							s = "(null)";
						}
						while (*s != '\0')
						{
							write(1, s, 1);
							count++;
							s++;
						}
					}
					break;
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
	}
	va_end(args);
	return (count);
}
