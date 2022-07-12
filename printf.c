#include "main.h"
/**
 * _printf - Kolobetso and Banele version of printf function
 * @format: String formatted with all identifiers
 * Return: number of strings printed expanded
 */

int _printf(const char *format, ...)
{
	/*expressions*/

	int i = 0;
	int count = 0;
	int value = 0;
	va_list args;
	va_start(args, format);
	int (*f)(va_list);

	/*prevent parsing a null pointer*/
	if(format == NULL)
		return (-1);

	/*printing ech character of string*/

	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1,&format[i],1);
			count = count + value;
			i++;
			continue;
		}

		if (format[i] == '%')
		{
			/*expressions here*/
			f = check_specifier(&format[i] + 1);

			if (f != NULL)
			{
				value = f(args);
				count = count + value;
				i = i + 2;
				continue;
			}

			if (format[i + 1] == '\0')
			{
				break;
			}

			if (format[i + 1] != '\0')
			{
				value =f(args);
				count = count + value;
				i++;
				continue;

			}
			
		}
	}


	return (0);
}
