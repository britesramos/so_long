/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/29 15:04:52 by sramos        #+#    #+#                 */
/*   Updated: 2024/07/05 11:23:36 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"
#include <limits.h>

int	ft_write_c(va_list args, int count)
{
	int	c;

	c = va_arg(args, int);
	count += write(1, &c, 1);
	return (count);
}

int	ft_write_s(va_list args, int count)
{
	char	*arg_next;

	arg_next = va_arg (args, char *);
	if (arg_next == NULL)
		count += write(1, "(null)", 6);
	if (arg_next)
		count += write(1, arg_next, ft_strlen(arg_next));
	return (count);
}

int	ft_write_di(va_list args)
{
	int		arg_next_int;
	int		count;
	long	c;

	count = 0;
	arg_next_int = va_arg(args, int);
	c = arg_next_int;
	ft_putnbr_fd(c, 1);
	if (c < 0)
	{
		c = c * (-1);
		count++;
	}
	if (c == 0)
		count++;
	while (c > 0)
	{
		count++;
		c /= 10;
	}
	return (count);
}

int	ft_printftwo(const char *format, int i, int count, va_list args)
{
	if (format[i] == '%')
		count += write(1, &format[i], 1);
	if (format[i] == 'c')
		count += ft_write_c(args, count);
	if (format[i] == 's')
		count += ft_write_s(args, count);
	if (format[i] == 'd')
		count += ft_write_di(args);
	if (format[i] == 'i')
		count += ft_write_di(args);
	if (format[i] == 'p')
		count += ft_write_p(va_arg(args, long long));
	if (format[i] == 'u')
		count += ft_write_u(va_arg(args, unsigned int));
	if (format[i] == 'X')
		count += ft_write_upperx(va_arg(args, unsigned int));
	if (format[i] == 'x')
		count += ft_write_lowerx(va_arg(args, unsigned int));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		counttwo;
	int		i;

	va_start(args, format);
	count = 0;
	counttwo = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			count += write(1, &format[i], 1);
		else if (format[i] == '%')
		{
			i++;
			count += ft_printftwo(format, i, counttwo, args);
		}
		i++;
	}
	va_end(args);
	return (count);
}
// int	main(void)
// {
// 			/*Test no conversions.*/
// 	// printf("This is count of printf: %i.\n", printf("Hello World\n"));
// 	// printf("This is count of ft_printf: %i.\n", ft_printf("Hello World\n"));
// 			/*Test %%*/
// 	// printf("This is count of printf: %i.\n", printf("Hello %%\n"));
// 	// printf("This is count of ft_printf: %i.\n", ft_printf("Hello %%\n"));
// 			/*Test %i*/
// 	// int c;
// 	// c = -67687;
// 	// printf("This is count of printf: %i.\n", printf("%i\n", c));
// 	// printf("This is count of ft_printf: %i.\n", ft_printf("%i\n", c));
// 			/*Test %d*/
// 	int c;
// 	c = 0;
// 	printf("This is count of printf: %i.\n", printf("%d\n", c));
// 	printf("This is count of ft_printf: %i.\n", ft_printf("%d\n", c));
// 			/*Test %c*/
// 	// char c;
// 	// c = 'a';
// 	// printf("This is count of printf: %i.\n", printf("%d\n", c));
// 	// printf("This is count of ft_printf: %i.\n", ft_printf("%d\n", c));
// 			/*Test %s*/
// 	// char *str;
// 	// str = "HO";
// 	// printf("This is count of printf: %i.\n", printf("%s\n", str));
// 	// printf("This is count of ft_printf: %i.\n", ft_printf("%s\n", str));
// 			/*Test %x*/
// 	// int a;
// 	// a = 0;
// 	// printf("Count printf: %i.\n", printf("a: Hex: %x, Dec: %d\n",a,a));
// 	// printf("Count ft_printf: %i.\n", ft_printf("a: Hex: %x, Dec: %d\n",a,a));
// 			/*Test %p*/
// 	// char *ptr;
// 	// ptr = -9223372036854775808;
// 	// printf("Count printf: %i.\n", printf("Adress of ptr: %p.\n", ptr));
// 	// printf("Count ft_printf: %i.\n", ft_printf("Adress of ptr: %p.\n", ptr));
// 			/*Test %u*/
// 	// int i;
// 	// i = -1;
// 	// printf("Count printf: %i.\n", printf("This is i: %u.\n", i));
// 	// printf("Count ft_printf: %i.\n", ft_printf("This is i: %u.\n", i));
// 	return (0);
// }