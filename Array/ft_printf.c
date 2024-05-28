/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 06:51:02 by hkeles            #+#    #+#             */
/*   Updated: 2024/05/24 06:51:03 by hkeles           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdarg.h> /*
# define va_start(ap, param)
# define va_end(ap)      
# define va_arg(ap, type)
#typedef va_list;
#        */
#include <stdint.h> /*
#typedef u_int64_t;
#        */
#include <unistd.h> /*
#ssize_t write(int, const void *, size_t);
#        */
#include "ft_printf.h" /*
# define DEC
# define HEXLOW
# define HEXUP
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ int	ft_format(va_list args, char f);
extern __inline__ int	ft_putstr(char *str);
extern __inline__ int	ft_itoa(register u_int64_t n, register int base,
							char *str, register int mod);
extern __inline__ int	ft_itoa_two(register u_int64_t n, register int base,
							char *str, int len);
/* *************************** [^] PROTOTYPES [^] *************************** */

int
	ft_printf(const char *format, ...)
{
	int					len;
	register int		tmp;
	va_list				args;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		tmp = 1;
		if (*format == '%')
			tmp = ft_format(args, *++format);
		else if (write(1, format, 1) == -1)
			return (-1);
		if (tmp == -1)
			return (-1);
		len += tmp;
		format++;
	}
	return (va_end(args), len);
}

extern __inline__ int
	ft_format(va_list args, char f)
{
	if (f == 'c')
		return (f = va_arg(args, int), write(1, &f, 1));
	else if (f == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (f == 'u')
		return (ft_itoa(va_arg(args, unsigned int), 10, DEC, 0));
	else if (f == 'd' || f == 'i')
		return (ft_itoa(va_arg(args, int), 10, DEC, 1));
	else if (f == 'p')
		return (ft_itoa(va_arg(args, u_int64_t), 16, HEXLOW, 2));
	else if (f == 'x')
		return (ft_itoa(va_arg(args, unsigned int), 16, HEXLOW, 0));
	else if (f == 'X')
		return (ft_itoa(va_arg(args, unsigned int), 16, HEXUP, 0));
	else if (f == '%')
		return (write(1, "%", 1));
	return (-1);
}

extern __inline__ int
	ft_putstr(char *str)
{
	register int	len;

	len = -1;
	if (!str)
		str = "(null)";
	while (str[++len])
		if (write(1, &str[len], 1) == -1)
			return (-1);
	return (len);
}

extern __inline__ int
	ft_itoa(register u_int64_t n, register int base, char *str,
		register int mod)
{
	register int	len;

	len = 0;
	if (mod == 1 && (int)n < 0)
	{
		n *= -1;
		if (write(1, "-", 1) == -1)
			return (-1);
		len++;
	}
	if (mod == 2)
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		len += 2;
	}
	if (n == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (len + 1);
	}
	return (ft_itoa_two(n, base, str, len));
}

extern __inline__ int
	ft_itoa_two(register u_int64_t n, register int base, char *str, int len)
{
	register int	idx;
	int				arr[30];

	idx = 0;
	while (n)
	{
		arr[idx++] = n % base;
		n /= base;
	}
	while (idx--)
	{
		if (write(1, &str[arr[idx]], 1) == -1)
			return (-1);
		len++;
	}
	return (len);
}
