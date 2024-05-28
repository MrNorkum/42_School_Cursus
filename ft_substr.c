/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:20:21 by hkeles            #+#    #+#             */
/*   Updated: 2024/05/23 20:20:22 by hkeles           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdlib.h> /*
# define NULL
#typedef size_t;
#        */
#include "libft.h" /*
# size_t ft_strlen(const char *);
#   void *ft_calloc(size_t, size_t);
# size_t ft_strlcpy(char *, const char *, size_t);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

char
	*ft_substr(char const *s, register unsigned int start, register size_t len)
{
	register size_t	i;
	char			*substr;

	if (!s)
		return (NULL);
	i = len;
	if (start >= ft_strlen(s) || len == 0)
		return ((char *)ft_calloc(sizeof(char), 1));
	if (len > ft_strlen(s + start))
		i = ft_strlen(s + start);
	substr = (char *)ft_calloc(sizeof(char), i + 1);
	if (!substr)
		return (NULL);
	return (ft_strlcpy(substr, s + start, i + 1), substr);
}
