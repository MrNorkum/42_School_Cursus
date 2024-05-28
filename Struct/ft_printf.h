/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 07:43:52 by hkeles            #+#    #+#             */
/*   Updated: 2024/05/24 07:43:53 by hkeles           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H 202405
/* *************************** [v] CONSTANTS [v] **************************** */
# define DEC "0123456789"
# define HEXLOW "0123456789abcdef"
# define HEXUP "0123456789ABCDEF"
/* *************************** [^] CONSTANTS [^] **************************** */
/* **************************** [v] INCLUDES [v] **************************** */
# include <stdarg.h> /*
# typedef va_list; 
#         */
/* **************************** [^] INCLUDES [^] **************************** */
/* **************************** [v] STRUCTS [v] ***************************** */
struct s_printf
{
	va_list		args;
	char		f;
	int			len;
};
/* **************************** [^] STRUCTS [^] ***************************** */
/* **************************** [v] TYPEDEF [v] ***************************** */
typedef struct s_printf	t_printf;
/* **************************** [^] TYPEDEF [^] ***************************** */
/* ************************* [v] ./ft_printf.c [v] ************************** */
extern int	ft_printf(const char *format, ...);
/* ************************* [^] ./ft_printf.c [^] ************************** */
#endif /* FT_PRINTF_H */
