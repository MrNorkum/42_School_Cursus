/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:43:29 by hkeles            #+#    #+#             */
/*   Updated: 2024/06/05 13:19:09 by hkeles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H 202405
/* **************************** [v] INCLUDES [v] **************************** */
# include <stdarg.h> /*
# typedef va_list;
#         */
# include <stdint.h> /*
# typedef u_int64_t;
#         */
/* **************************** [^] INCLUDES [^] **************************** */
/* *************************** [v] CONSTANTS [v] **************************** */
# define DEC "0123456789"
# define HEXLOW "0123456789abcdef"
# define HEXUP "0123456789ABCDEF"
/* *************************** [^] CONSTANTS [^] **************************** */
/* **************************** [v] STRUCTS [v] ***************************** */

#include <stdlib.h>
#include <stdio.h>
struct s_printf
{
	va_list		args;
	char		format;
	int			length;
	int			fd;
	char		chr;
	char		*str;
	u_int64_t	nbr;
	int			base;
	char		*base_str;
};
/* **************************** [^] STRUCTS [^] ***************************** */
/* **************************** [v] TYPEDEFS [v] **************************** */
typedef struct s_printf	t_printf;
/* **************************** [^] TYPEDEFS [^] **************************** */
/* *************************** [v] FUNCTIONS [v] **************************** */
extern int	ft_printf(const char *format, ...);
extern int	ft_fprintf(int fd, const char *format, ...);
extern int	convert_to_base(t_printf *x);
extern int	put_char(t_printf *x);
extern int	put_dec(t_printf *x);
extern int	put_hex(t_printf *x);
extern int	put_string(t_printf *x);
/* *************************** [^] FUNCTIONS [^] **************************** */
#endif /* FT_PRINTF_H */
