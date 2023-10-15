#include "shell.h"

/**
 * _printf - print formarted input.
 * @format: format specifier.
 * Return: void.
 */
void _printf(const char *format, ...)
{
	va_list args;
	char *arg;
	int argInt;
	double argDouble;
	int divisor;
	int digit;
	int wholePart;
	int fractionalPart;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
			case 'd':
			{
				argInt = va_arg(args, int);
				divisor = 1;
				if (argInt < 0)
				{
					putchar('-');
					argInt = -argInt;
				}
				while (argInt / divisor >= 10)
					divisor *= 10;
				while (divisor != 0)
				{
					digit = argInt / divisor;
					putchar('0' + digit);
					argInt %= divisor;
					divisor /= 10;
				}
				break;
			}
			case 'f':
			{
				argDouble = va_arg(args, double);
				if (argDouble < 0)
				{
					putchar('-');
					argDouble = -argDouble;
				}
				wholePart = (int)argDouble;
				fractionalPart = (int)((argDouble - wholePart) * 1000000);
				divisor = 100000;
				while (divisor != 0)
				{
					digit = wholePart / divisor;
					putchar('0' + digit);
					wholePart %= divisor;
					divisor /= 10;
				}
				putchar('.');
				divisor = 100000;
				while (divisor != 0)
				{
					digit = fractionalPart / divisor;
					putchar('0' + digit);
					fractionalPart %= divisor;
					divisor /= 10;
				}
				break;
			}
			case 's':
			{
				arg = va_arg(args, char *);
				while (*arg != '\0')
				{
					putchar(*arg);
					arg++;
				}
				break;
			}
			default:
				putchar(*format);
				break;
			}
		}
		else
		{
			putchar(*format);
		}

		format++;
	}

	va_end(args);
}