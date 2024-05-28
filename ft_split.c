/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:31:07 by hkeles            #+#    #+#             */
/*   Updated: 2024/05/23 18:31:09 by hkeles           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdlib.h> /*
# define NULL
#typedef size_t;
#   void *malloc(size_t);
#   void free(void *);
#        */
#include "libft.h" /*
#   char *ft_substr(char const *, unsigned int, size_t);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ int	word_count(char const *s, register char c);
extern __inline__ int	word_len(char const *s, register char c);
extern __inline__ char	**ft_free_array(char **arr);
/* *************************** [^] PROTOTYPES [^] *************************** */

char
	**ft_split(char const *s, register char c)
{
	register int	arg;
	register int	idx;
	register int	w_count;
	char			**res;

	arg = -1;
	idx = 0;
	w_count = word_count(s, c);
	res = (char **)malloc(sizeof(char *) * (w_count + 1));
	if (!res)
		return (NULL);
	while (++arg < w_count)
	{
		while (s[idx] && s[idx] == c)
			idx++;
		res[arg] = ft_substr(s, idx, word_len(&s[idx], c));
		if (!res[arg])
			return (ft_free_array(res));
		idx += word_len(&s[idx], c);
	}
	return (res[arg] = NULL, res);
}

extern __inline__ int
	word_count(char const *s, register char c)
{
	int	i;

	i = 0;
	while (!!*s)
	{
		if (*s == c)
			s++;
		else
		{
			while (!!*s && *s != c)
				s++;
			i++;
		}
	}
	return (i);
}

extern __inline__ int
	word_len(char const *s, register char c)
{
	int	len;

	len = 0;
	if (!*s)
		return (0);
	while (*s && *s++ != c)
		len++;
	return (len);
}

extern __inline__ char
	**ft_free_array(char **arr)
{
	register size_t	i;

	i = -1;
	while (!!arr[++i])
		free(arr[i]);
	return (free(arr), NULL);
}
