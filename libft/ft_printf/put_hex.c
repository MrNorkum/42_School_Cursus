/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:30:56 by hkeles            #+#    #+#             */
/*   Updated: 2024/05/26 17:30:58 by hkeles           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../ft_printf.h" /*
#typedef t_printf;
#    int put_string(t_printf *);
#    int put_char(t_printf *);
#    int convert_to_base(t_printf *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

int
	put_hex(t_printf *x)
{
	if (x->format == 'p')
	{
		x->str = "0x";
		if (put_string(x) == -1)
			return (-1);
	}
	if (!x->nbr)
	{
		x->chr = '0';
		if (put_char(x) == -1)
			return (-1);
	}
	return (convert_to_base(x));
}