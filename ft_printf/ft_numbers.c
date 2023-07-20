/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucar <alucar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:01:31 by alucar            #+#    #+#             */
/*   Updated: 2023/07/20 12:12:55 by alucar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_number(int number, int *length)
{
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*length) += 11;
		return ;
	}
	if (number < 0)
	{
		ft_putchar_len('-', length);
		ft_number(number * -1, length);
	}
	else
	{
		if (number > 9)
			ft_number(number / 10, length);
		ft_putchar_len(number % 10 + '0', length);
	}
}

void	ft_unsigned_int(unsigned int u, int *length)
{
	if (u >= 10)
		ft_unsigned_int(u / 10, length);
	ft_putchar_len(u % 10 + '0', length);
}

void	ft_hexadecimal(unsigned int x, int *length, char sx_or_bx)
{
	char	string[25];
	char	*base_char;
	int		i;

	if (sx_or_bx == 'X')
		base_char = "0123456789ABCDEF";
	else
		base_char = "0123456789abcdef";
	i = 0;
	if (x == 0)
	{
		ft_putchar_len('0', length);
		return ;
	}
	while (x != 0)
	{
		string[i] = base_char [x % 16];
		x = x / 16;
		i++;
	}
	while (i--)
	{
		ft_putchar_len(string[i], length);
	}
}

void	ft_pointer(size_t pointer, int *length)
{
	char	string[25];
	char	*base_char;
	int		i;

	base_char = "0123456789abcdef";
	i = 0;
	write(1, "0x", 2);
	(*length += 2);
	if (pointer == 0)
	{
		ft_putchar_len('0', length);
		return ;
	}
	while (pointer != 0)
	{
		string[i] = base_char [pointer % 16];
		pointer = pointer / 16;
		i++;
	}
	while (i--)
	{
		ft_putchar_len(string[i], length);
	}
}
