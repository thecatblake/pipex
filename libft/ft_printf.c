/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaga     <k222ryousuke@gmail.com   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:47:58 by rkaga             #+#    #+#             */
/*   Updated: 2024/11/04 20:53:30 by rkaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print(char specifier, va_list args)
{
	int	num;

	num = 0;
	if (specifier == 'c')
		num = pf_putchar(va_arg(args, int));
	else if (specifier == 's')
		num = pf_putstr(va_arg(args, char *));
	else if (specifier == 'p')
		num = pf_putpointer(va_arg(args, void *));
	else if (specifier == 'd' || specifier == 'i')
		num = pf_putnbr(va_arg(args, int));
	else if (specifier == 'u')
		num = pf_putnbr(va_arg(args, unsigned int));
	else if (specifier == 'x')
		num = pf_puthexlow(va_arg(args, unsigned int));
	else if (specifier == 'X')
		num = pf_puthexup(va_arg(args, unsigned int));
	else if (specifier == '%')
		num = pf_putpercent();
	return (num);
}

int	parse(char *format, va_list args, bool isprint, int num)
{
	if (*format == '\0')
		return (num);
	if (isprint)
		return (parse(format + 1, args, false, num + print(*format, args)));
	if (*format == '%')
		return (parse(format + 1, args, true, num));
	return (parse(format + 1, args, false, num + pf_putchar(*format)));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		result;

	va_start(args, (char *)format);
	result = parse((char *)format, args, false, 0);
	va_end(args);
	return (result);
}
