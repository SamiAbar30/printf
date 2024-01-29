#include "main.h"

int _printf(const char *format, ...);
{
	int num_chara_print = 0;
	va_list list_of_arg;

	if (format == NULL)
		return (-1);
	va_start(list_of_arg, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			num_chara_print++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
				num_chara_print++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(list_of_arg, int);

				write(1, &c, 1);
				num_chara_print++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(list_of_arg, char*);
				int str_len = 0

				while (str[str_len] != '\0')
				str_len++;
				write(1, str, str_len);
				num_chara_print += str_len;
			}
		}
	format++;
	}
		va_end(list_of_arg);
		return (num_chara_print);
}
