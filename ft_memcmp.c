/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:56:58 by hkeles            #+#    #+#             */
/*   Updated: 2024/05/23 20:06:20 by hkeles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdlib.h> /*
#typedef size_t;
#typedef u_int8_t;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

int
	ft_memcmp(const void *s1, const void *s2, register size_t n)
{
	register size_t	i;
	const u_int8_t	*str1;
	const u_int8_t	*str2;

	i = -1;
	str1 = (const u_int8_t *)s1;
	str2 = (const u_int8_t *)s2;
	while (++i < n)
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
	return (0);
}
