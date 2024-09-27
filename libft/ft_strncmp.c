/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:33:14 by hkeles            #+#    #+#             */
/*   Updated: 2024/05/23 20:08:39 by hkeles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdlib.h> /*
#typedef size_t;
#typedef u_int8_t;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

int
	ft_strncmp(const char *s1, const char *s2, register size_t n)
{
	register size_t	idx;

	idx = 0;
	if (!n)
		return (0);
	while (s1[idx] && s2[idx] && s1[idx] == s2[idx] && idx < n - 1)
		idx++;
	return ((u_int8_t)s1[idx] - (u_int8_t)s2[idx]);
}
