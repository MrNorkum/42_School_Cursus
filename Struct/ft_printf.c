/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 07:49:39 by hkeles            #+#    #+#             */
/*   Updated: 2024/05/24 07:49:41 by hkeles           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdint.h> /*
#typedef u_int64_t;
#        */
#include <stdarg.h> /*
# define va_start(ap, param)
# define va_end(ap)
# define va_arg(ap, type)
#        */
#include <unistd.h> /*
#ssize_t write(int, const void *, size_t);
#        */
#include "ft_printf.h" /*
# define DEC
# define HEXLOW
# define HEXUP
#typedef t_printf;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ int	ft_format(t_printf *x);
extern __inline__ int	ft_putchar(char c, t_printf *x);
extern __inline__ int	ft_putstr(char *s, t_printf *x);
extern __inline__ int	ft_itoa(register u_int64_t n, register int base,
							char *s, t_printf *x);
/* *************************** [v] PROTOTYPES [v] *************************** */

int	ft_printf(const char *format, ...)
{
	t_printf	x;

	x.len = 0;
	va_start(x.args, format);
	while (*format)
	{
		if (*format == '%')
		{
			x.f = *++format;
			if (ft_format(&x) == -1)
				return (-1);
		}
		else if (ft_putchar(*format, &x) == -1)
			return (-1);
		format++;
	}
	return (va_end(x.args), x.len);
}

extern __inline__ int
	ft_format(t_printf *x)
{
	if (x->f == 'c')
		return (ft_putchar(va_arg(x->args, int), x));
	else if (x->f == 's')
		return (ft_putstr(va_arg(x->args, char *), x));
	else if (x->f == 'd' || x->f == 'i')
		return (ft_itoa(va_arg(x->args, int), 10, DEC, x));
	else if (x->f == 'u')
		return (ft_itoa(va_arg(x->args, unsigned int), 10, DEC, x));
	else if (x->f == 'x')
		return (ft_itoa(va_arg(x->args, unsigned int), 16, HEXLOW, x));
	else if (x->f == 'X')
		return (ft_itoa(va_arg(x->args, unsigned int), 16, HEXUP, x));
	else if (x->f == 'p')
		return (ft_itoa(va_arg(x->args, u_int64_t), 16, HEXLOW, x));
	else if (x->f == '%')
		return (ft_putchar('%', x));
	return (-1);
}

extern __inline__ int
	ft_putchar(char c, t_printf *x)
{
	return (x->len++, write(1, &c, 1));
}

extern __inline__ int
	ft_putstr(char *s, t_printf *x)
{
	if (!s)
		s = "(null)";
	while (*s)
		if (ft_putchar(*s++, x) == -1)
			return (-1);
	return (1);
}

extern __inline__ int
	ft_itoa(register u_int64_t n, register int base, char *s, t_printf *x)
{
	register int	mod;
	register int	idx;
	int				arr[30];

	mod = (x->f == 'd' || x->f == 'i') + 2 * (x->f == 'p');
	idx = 0;
	if (mod == 1 && (int)n < 0)
	{
		n = 1 + ~n;
		if (ft_putchar('-', x) == -1)
			return (-1);
	}
	if (mod == 2 && ft_putstr("0x", x) == -1)
		return (-1);
	if (!n && ft_putchar('0', x) == -1)
		return (-1);
	while (!!n)
	{
		arr[idx++] = n % base;
		n /= base;
	}
	while (idx--)
		if (ft_putchar(s[arr[idx]], x) == -1)
			return (-1);
	return (1);
}
