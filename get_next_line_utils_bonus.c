/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 02:20:35 by hkeles            #+#    #+#             */
/*   Updated: 2024/05/24 02:59:57 by hkeles           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdlib.h> /*
# define NULL
#typedef size_t;
#   void *malloc(size_t);
#   void free(void *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

size_t
	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		++len;
	return (len);
}

char
	*ft_strdup(const char *s1)
{
	register size_t	idx;
	char			*res;

	res = (char *)malloc(ft_strlen(s1) + 1);
	if (!res)
		return (NULL);
	idx = -1;
	while (s1[++idx] != '\0')
		res[idx] = s1[idx];
	res[idx] = '\0';
	return (res);
}

char
	*ft_strjoin(char const *s1, char const *s2)
{
	register size_t	i;
	register size_t	j;
	char			*res;

	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

char
	*ft_substr(char const *s, register unsigned int start, register size_t len)
{
	register size_t	i;
	register size_t	j;
	register size_t	calc_len;
	char			*res;

	if (!s || len <= 0)
		return (NULL);
	calc_len = ft_strlen(s);
	if (len > calc_len)
		len = calc_len;
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	i = start;
	j = 0;
	while (i < calc_len && j < len)
	{
		res[j] = s[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}

void
	*ft_free_stash(char **stash, register int create_line)
{
	char	*line;

	line = NULL;
	if (!*stash)
		return (NULL);
	if (create_line == 1)
		line = ft_strdup(*stash);
	free(*stash);
	*stash = NULL;
	return (line);
}
