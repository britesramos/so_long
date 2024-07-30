/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printfextra.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/10 16:47:41 by sramos        #+#    #+#                 */
/*   Updated: 2024/07/05 11:23:42 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_write_upperx(unsigned int c)
{
	int		count;
	int		temp;
	int		i;
	char	hexadecimal[100];

	count = 0;
	i = 0;
	if (c == 0)
		count += write(1, "0", 1);
	while (c != 0)
	{
		temp = c % 16;
		if (temp < 10)
			temp += 48;
		else
			temp += 55;
		hexadecimal[i++] = temp;
		c /= 16;
	}
	while (i > 0)
	{
		i--;
		count += write(1, &hexadecimal[i], 1);
	}
	return (count);
}

int	ft_write_lowerx(unsigned int c)
{
	int		count;
	int		temp;
	int		i;
	char	hexadecimal[100];

	count = 0;
	i = 0;
	if (c == 0)
		count += write(1, "0", 1);
	while (c != 0)
	{
		temp = c % 16;
		if (temp < 10)
			temp += 48;
		else
			temp += 87;
		hexadecimal[i++] = temp;
		c /= 16;
	}
	while (i > 0)
	{
		i--;
		count += write(1, &hexadecimal[i], 1);
	}
	return (count);
}

int	ft_write_pp(size_t c)
{
	int		count;
	int		temp;
	int		i;
	char	hexadecimal[100];

	count = 0;
	i = 0;
	if (c == 0)
		count += write(1, "0", 1);
	while (c != 0)
	{
		temp = c % 16;
		if (temp < 10)
			temp += 48;
		else
			temp += 87;
		hexadecimal[i++] = temp;
		c /= 16;
	}
	while (i > 0)
	{
		i--;
		count += write(1, &hexadecimal[i], 1);
	}
	return (count);
}

int	ft_write_p(long long c)
{
	int		count;
	size_t	ptr;

	count = 0;
	ptr = (size_t)c;
	if (c == 0)
		count += write(1, "(nil)", 5);
	else
	{
		count += write(1, "0x", 2);
		count += ft_write_pp(ptr);
	}
	return (count);
}

int	ft_write_u(unsigned int c)
{
	int				count;
	unsigned int	num;

	count = 0;
	if (c >= 10)
		count += ft_write_u(c / 10);
	num = c % 10 + '0';
	count += write (1, &num, 1);
	return (count);
}
