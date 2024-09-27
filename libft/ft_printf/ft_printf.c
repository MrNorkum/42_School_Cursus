/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 07:49:39 by hkeles            #+#    #+#             */
/*   Updated: 2024/06/05 13:20:42 by hkeles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../ft_printf.h" /*
#typedef t_printf;
#    int put_char(t_printf *);
#    int put_string(t_printf *);
#    int put_dec(t_printf *);
#    int put_hex(t_printf *);
#        */
#include <stdarg.h> /*
# define va_start(ap, param)
# define va_end(ap)
# define va_arg(ap, type)
#        */
#include <stdint.h> /*
#typedef u_int64_t;
#        */
/* **************************** [^] INCLUDES [^] **************************** */
/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ void	init_printf(t_printf *x);
extern __inline__ int	check_format(t_printf *x);
/* *************************** [v] PROTOTYPES [v] *************************** */

int	ft_printf(const char *format, ...)
{
	t_printf	x;

	init_printf(&x);
	va_start(x.args, format);
	while (*format)
	{
		if (*format == '%')
		{
			x.format = *++format;
			if (check_format(&x) == -1)
				return (-1);
		}
		else
		{
			x.chr = *format;
			if (put_char(&x) == -1)
				return (-1);
		}
		format++;
	}
	return (va_end(x.args), x.length);
}

int	ft_fprintf(int fd, const char *format, ...)
{
	t_printf	x;

	init_printf(&x);
	x.fd = fd;
	va_start(x.args, format);
	while (*format)
	{
		if (*format == '%')
		{
			x.format = *++format;
			if (check_format(&x) == -1)
				return (-1);
		}
		else
		{
			x.chr = *format;
			if (put_char(&x) == -1)
				return (-1);
		}
		format++;
	}
	return (va_end(x.args), x.length);
}


extern __inline__ void
	init_printf(t_printf *x)
{
	x->format = '\0';
	x->length = 0;
	x->fd = 1;
	x->chr = '\0';
	x->str = ((void *)0);
	x->nbr = 0;
	x->base = 10;
	x->base_str = DEC;
}

extern __inline__ int
	check_format(t_printf *x)
{
	if (x->format == 'c')
		return (x->chr = va_arg(x->args, int), put_char(x));
	else if (x->format == 's')
		return (x->str = va_arg(x->args, char *), put_string(x));
	else if (x->format == '%')
		return (x->chr = '%', put_char(x));
	else if (x->format == 'd' || x->format == 'i')
		return (x->nbr = va_arg(x->args, int), put_dec(x));
	else if (x->format == 'u')
		return (x->nbr = va_arg(x->args, unsigned int), put_dec(x));
	x->base = 16;
	x->base_str = HEXLOW;
	if (x->format == 'x')
		x->nbr = va_arg(x->args, unsigned int);
	else if (x->format == 'X')
	{
		x->nbr = va_arg(x->args, unsigned int);
		x->base_str = HEXUP;
	}
	else if (x->format == 'p')
		x->nbr = va_arg(x->args, uint64_t);
	return (put_hex(x));
}
