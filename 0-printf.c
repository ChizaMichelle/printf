#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf - a custom printf fuction
 * @format: format
 * Return: printed characters
 */
int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int char_count = 0;
	const char *ptr = format;

	while (*ptr != '\0')
	{
		if (*ptr != '%')
		{
			write(1, ptr, 1);
			char_count++;
			}
		else
		{
			ptr++;
			switch (*ptr)
			{
				case 'c':
				{
				char c = va_arg(args, int);

				write(1, &c, 1);

				char_count++;
				break;
				}

				case 's':
				{
				const char *str = va_arg(args, const char *);

				while (*str != '\0')
				{
				write(1, str, 1);
				str++;
				char_count++;
				
				}
				break;
				
				}
				case '%':
				write(1, "%", 1);
				char_count++;
				break;
				default:
				break;
			}
		}
		ptr++;
		}
		va_end(args);

		return (char_count);
}
int main(void)
{
	const char *message = "Hello, World!";
	int num = 42;
	char character = 'A';

	_printf("Message: %s\nNumber: %d\nCharacter: %c\n", message, num, character);

	return (0);
}

