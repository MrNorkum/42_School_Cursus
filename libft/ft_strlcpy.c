/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:24:10 by hkeles            #+#    #+#             */
/*   Updated: 2024/05/23 19:24:11 by hkeles           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdlib.h> /*
#typedef size_t;
#        */
#include "libft.h" /*
# size_t ft_strlen(const char *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

size_t
	ft_strlcpy(char *dst, const char *src, register size_t dstsize)
{
	register size_t	idx;

	idx = -1;
	if (!!dstsize)
	{
		while (src[++idx] && idx < dstsize - 1)
			dst[idx] = src[idx];
		dst[idx] = '\0';
	}
	return (ft_strlen(src));
}
