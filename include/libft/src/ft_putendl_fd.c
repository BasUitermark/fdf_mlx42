#include "../include/libft.h"

size_t	ft_putendl_fd(char *s, int fd)
{
	size_t	out;

	out = 0;
	out += ft_putstr_fd(s, fd);
	out += ft_putchar_fd('\n', fd);
	return (out);
}
