/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucar <alucar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:13:03 by alucar            #+#    #+#             */
/*   Updated: 2023/07/19 14:42:26 by alucar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_putchar_len(char c, int *len);
void	ft_printcheck(char s, va_list *args, int *len);
void	ft_string(char *args, int *length);
void	ft_number(int number, int *length);
void	ft_unsigned_int(unsigned int u, int *length);
void	ft_hexadecimal(unsigned int x, int *length, char sx_or_bx);
void	ft_pointer(size_t pointer, int *length);

#endif