/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:01:07 by hkeles            #+#    #+#             */
/*   Updated: 2024/05/26 17:01:09 by hkeles           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../ft_printf.h" /*
#typedef t_printf;
#        */
#include "../libft.h" /*
#    int ft_putstr_fd(char *, int);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

int
	put_string(t_printf *x)
{
	int	len;

	if (!x->str)
		x->str = "(null)";
	if (*x->str)
	{
		len = ft_putstr_fd(x->str, x->fd);
		if (len == -1)
			return (-1);
		x->length += len;
	}
	return (1);
}
