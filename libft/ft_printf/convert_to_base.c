/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:10:51 by hkeles            #+#    #+#             */
/*   Updated: 2024/06/05 13:20:27 by hkeles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../ft_printf.h" /*
#typedef t_printf;
#    int put_char(t_printf *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

int
	convert_to_base(t_printf *x)
{
	register int	idx;
	int				arr[30];

	idx = 0;
	while (!!x->nbr)
	{
		arr[idx++] = x->nbr % x->base;
		x->nbr /= x->base;
	}
	while (idx--)
	{
		x->chr = x->base_str[arr[idx]];
		if (put_char(x) == -1)
			return (-1);
	}
	return (1);
}
