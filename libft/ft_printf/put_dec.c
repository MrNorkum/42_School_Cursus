/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_dec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:03:51 by hkeles            #+#    #+#             */
/*   Updated: 2024/06/05 13:16:50 by hkeles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../ft_printf.h" /*
#typedef t_printf;
#    int put_char(t_printf *);
#    int convert_to_base(t_printf *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

int
	put_dec(t_printf *x)
{
	if ((int)x->nbr < 0)
	{
		x->nbr = 1 + ~x->nbr;
		x->chr = '-';
		if (put_char(x) == -1)
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
