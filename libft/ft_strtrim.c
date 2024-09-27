/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:12:13 by hkeles            #+#    #+#             */
/*   Updated: 2024/05/23 20:12:14 by hkeles           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdlib.h> /*
# define NULL
#typedef size_t;
#   void *malloc(size_t);
#        */
#include "libft.h" /*
# size_t ft_strlen(const char *);
#    int ft_strchr(const char *, int);
# size_t ft_strlcpy(char *, const char *, size_t);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

char
	*ft_strtrim(char const *s1, char const *set)
{
	register size_t	len;
	const char		*start;
	const char		*end;
	char			*trim;

	start = s1;
	end = s1 + ft_strlen(s1) - 1;
	while (*start && !!ft_strchr(set, *start))
		start++;
	while (end > start && !!ft_strchr(set, *end))
		end--;
	len = end - start + 1;
	trim = (char *)malloc(len + 1);
	if (!trim)
		return (NULL);
	ft_strlcpy(trim, start, len + 1);
	trim[len] = '\0';
	return (trim);
}
