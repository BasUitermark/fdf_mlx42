/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/05 13:48:24 by buiterma      #+#    #+#                 */
/*   Updated: 2022/07/05 13:48:25 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	check_format(va_list args, char *str, int i)
{
	int	out;

	out = 0;
	if (str[i] == 'c')
		out = ft_putchar_fd(va_arg(args, t_i32), 1);
	else if (str[i] == 's')
		out = ft_putstr_fd(va_arg(args, char *), 1);
	else if (str[i] == 'p')
	{
		out = ft_putstr_fd("0x", 1);
		out += ft_putnbr_base_fd(va_arg(args, t_u64), 1, HEX_LOWER);
	}
	else if (str[i] == 'd' || str[i] == 'i')
		out = ft_putnbr_fd(va_arg(args, int), 1);
	else if (str[i] == 'u')
		out = ft_putnbr_base_fd(va_arg(args, t_u32), 1, DECIMAL);
	else if (str[i] == 'x')
		out = ft_putnbr_base_fd(va_arg(args, t_u32), 1, HEX_LOWER);
	else if (str[i] == 'X')
		out = ft_putnbr_base_fd(va_arg(args, t_u32), 1, HEX_UPPER);
	else if (str[i] == '%')
		out = write(1, "%", 1);
	return (out);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		out;
	va_list	args;

	va_start(args, str);
	i = -1;
	out = 0;
	if (!str)
		return (0);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			out += check_format(args, (char *)str, i + 1);
			i++;
		}
		else
			out += write(1, &str[i], 1);
	}
	va_end(args);
	return (out);
}
