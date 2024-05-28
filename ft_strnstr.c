/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:38:40 by hkeles            #+#    #+#             */
/*   Updated: 2024/05/23 20:08:58 by hkeles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdlib.h> /*
# define NULL
#typedef size_t;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

char
	*ft_strnstr(const char *haystack, const char *needle, register size_t len)
{
	register size_t	h_len;
	register size_t	n_len;

	h_len = -1;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[++h_len] && h_len < len)
	{
		n_len = 0;
		while (haystack[h_len + n_len] == needle[n_len]
			&& haystack[h_len + n_len] && h_len + n_len < len)
			n_len++;
		if (!needle[n_len])
			return ((char *)haystack + h_len);
	}
	return (NULL);
}
