/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucar <alucar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:13:43 by alucar            #+#    #+#             */
/*   Updated: 2023/07/20 14:22:44 by alucar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printcheck(char s, va_list *args, int *len)
{
	if (s == 'c')
		ft_putchar_len(va_arg(*args, int), len);
	else if (s == 's')
		ft_string(va_arg(*args, char *), len);
	else if (s == '%')
		ft_putchar_len('%', len);
	else if (s == 'd' || s == 'i')
		ft_number(va_arg(*args, int), len);
	else if (s == 'u')
		ft_unsigned_int(va_arg(*args, unsigned int), len);
	else if (s == 'x')
		ft_hexadecimal(va_arg(*args, unsigned int), len, 'x');
	else if (s == 'X')
		ft_hexadecimal(va_arg(*args, unsigned int), len, 'X');
	else if (s == 'p')
		ft_pointer(va_arg(*args, size_t), len);
	else
		return ;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		length;
	int		i;

	length = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_printcheck(str[i], &args, &length);
			i++;
		}
		else
		{
			ft_putchar_len((char)str[i], &length);
			i++;
		}
	}
	va_end(args);
	return (length);
}
