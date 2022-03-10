#include "../include/libft.h"

static int	check_format(va_list args, char *str, int i, int fd)
{
	int	out;

	out = 0;
	if (str[i] == 'c')
		out = ft_putchar_fd(va_arg(args, t_i32), fd);
	else if (str[i] == 's')
		out = ft_putstr_fd(va_arg(args, char *), fd);
	else if (str[i] == 'p')
	{
		out = ft_putstr_fd("0x", fd);
		out += ft_putnbr_base_fd(va_arg(args, t_u64), fd, HEX_LOWER);
	}
	else if (str[i] == 'd' || str[i] == 'i')
		out = ft_putnbr_fd(va_arg(args, int), fd);
	else if (str[i] == 'u')
		out = ft_putnbr_base_fd(va_arg(args, t_u32), fd, DECIMAL);
	else if (str[i] == 'x')
		out = ft_putnbr_base_fd(va_arg(args, t_u32), fd, HEX_LOWER);
	else if (str[i] == 'X')
		out = ft_putnbr_base_fd(va_arg(args, t_u32), fd, HEX_UPPER);
	else if (str[i] == '%')
		out = write(1, "%", fd);
	return (out);
}

int	ft_fprintf(int fd, const char *str, ...)
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
			out += check_format(args, (char *)str, i + 1, fd);
			i++;
		}
		else
			out += write(fd, &str[i], 1);
	}
	va_end(args);
	return (out);
}
