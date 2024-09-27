#include "libft.h"
#include <unistd.h>
#include <stdint.h>

static inline int	my_putchar(char c, t_printf *x)
{
	return (x->len++, write(1, &c, 1));
}

static inline int	my_putstring(char *s, t_printf *x)
{
	if (!s)
		s = "(null)";
	while (*s)
		if (my_putchar(*s++, x) == -1)
			return (-1);
	return (1);
}

static inline int	my_itoa(uintptr_t n, int base, char *s, t_printf *x)
{
	int	tab[50];
	int	mod;
	int	i;

	mod = (x->f == 'd' || x->f == 'i') + 2 * (x->f == 'p');
	i = 0;
	if (mod == 1 && (int)n < 0)
	{
		n = -n;
		if (my_putchar('-', x) == -1)
			return (-1);
	}
	if (mod == 2 && my_putstring("0x", x) == -1)
		return (-1);
	if (!n)
		return (my_putchar('0', x));
	while (n)
	{
		tab[i++] = n % base;
		n /= base;
	}
	while (i--)
		if (my_putchar(s[tab[i]], x) == -1)
			return (-1);
	return (1);
}

static inline int	my_format(t_printf *x)
{
	if (x->f == 'c')
		return (my_putchar(va_arg(x->args, int), x));
	else if (x->f == 's')
		return (my_putstring(va_arg(x->args, char *), x));
	else if (x->f == 'u')
		return (my_itoa(va_arg(x->args, unsigned int), 10, DEC, x));
	else if (x->f == 'd' || x->f == 'i')
		return (my_itoa(va_arg(x->args, int), 10, DEC, x));
	else if (x->f == 'p')
		return (my_itoa(va_arg(x->args, uintptr_t), 16, HEXLOW, x));
	else if (x->f == 'x')
		return (my_itoa(va_arg(x->args, unsigned int), 16, HEXLOW, x));
	else if (x->f == 'X')
		return (my_itoa(va_arg(x->args, unsigned int), 16, HEXUP, x));
	else if (x->f == '%')
		return (my_putchar('%', x));
	return (-1);
}

int	ft_printf(const char *s, ...)
{
	t_printf	x;

	x.len = 0;
	va_start(x.args, s);
	while (*s)
	{
		if (*s == '%')
		{
			x.f = *++s;
			if (my_format(&x) == -1)
				return (-1);
		}
		else if (my_putchar(*s, &x) == -1)
			return (-1);
		s++;
	}
	return (va_end(x.args), x.len);
}
