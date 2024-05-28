/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:09:02 by hkeles            #+#    #+#             */
/*   Updated: 2024/05/23 20:07:07 by hkeles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdlib.h> /*
# define NULL
#typedef size_t;
#typedef u_int8_t;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	*ft_memmove(void *dst, const void *src, register size_t len)
{
	register size_t	i;
	u_int8_t		*d;
	const u_int8_t	*s;

	if (!dst && !src)
		return (0);
	i = -1;
	d = (u_int8_t *)dst;
	s = (const u_int8_t *)src;
	if (d < s)
		while (++i < len)
			d[i] = s[i];
	else if (d > s)
		while (len--)
			d[len] = s[len];
	return (dst);
}
