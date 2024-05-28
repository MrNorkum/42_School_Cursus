/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:13:40 by hkeles            #+#    #+#             */
/*   Updated: 2024/05/23 19:13:42 by hkeles           ###   ########.tr       */
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
	ft_strlcat(char *dst, const char *src, register size_t dstsize)
{
	register size_t	idx;
	register size_t	d_len;
	register size_t	s_len;

	idx = -1;
	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (!dstsize || dstsize <= d_len)
		return (dstsize + s_len);
	dstsize -= (d_len + 1);
	while (src[++idx] && idx < dstsize)
		dst[d_len + idx] = src[idx];
	dst[d_len + idx] = '\0';
	return (d_len + s_len);
}
