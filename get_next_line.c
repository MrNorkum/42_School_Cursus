/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 01:51:25 by hkeles            #+#    #+#             */
/*   Updated: 2024/05/24 01:51:27 by hkeles           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <unistd.h> /*
#ssize_t read(int, void *, size_t);
#        */
#include <stdlib.h> /*
# define NULL
#typedef size_t;
#   void *malloc(size_t);
#        */
#include "get_next_line.h" /*
# define BUFFER_SIZE
#   void *ft_free_stash(char **, int);
#   char *ft_strdup(const char *);
#   char *ft_strjoin(char const *, char const *);
#   char *ft_substr(char const *, unsigned int, size_t);
# size_t ft_strlen(const char *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ char	*ft_copy_to_stash(char *stash, char *buf);
extern __inline__ int	ft_have_nl(char *s);
extern __inline__ char	*ft_extract_line(char *stash);
extern __inline__ char	*ft_recreate_stash(char *stash);
/* *************************** [^] PROTOTYPES [^] *************************** */

char
	*get_next_line(int fd)
{
	char			buf[BUFFER_SIZE + 1];
	register long	ret;
	static char		*stash = NULL;
	char			*line;

	line = NULL;
	ret = BUFFER_SIZE;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free_stash(&stash, 0));
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if ((ret == 0 && !stash) || ret == -1)
			return (ft_free_stash(&stash, 0));
		buf[ret] = '\0';
		stash = ft_copy_to_stash(stash, buf);
		if (ft_have_nl(stash))
		{
			line = ft_extract_line(stash);
			if (!line)
				return (ft_free_stash(&stash, 0));
			return (stash = ft_recreate_stash(stash), line);
		}
	}
	return (ft_free_stash(&stash, 1));
}

extern __inline__ char
	*ft_copy_to_stash(char *stash, char *buf)
{
	char	*res;

	res = NULL;
	if (!stash && buf)
		return (ft_strdup(buf));
	res = ft_strjoin(stash, buf);
	ft_free_stash(&stash, 0);
	return (res);
}

extern __inline__ int
	ft_have_nl(char *s)
{
	register size_t	idx;

	if (!s)
		return (0);
	idx = -1;
	while (s[++idx] != '\0')
		if (s[idx] == '\n')
			return (1);
	return (0);
}

extern __inline__ char
	*ft_extract_line(char *stash)
{
	register size_t	i;
	register size_t	j;
	char			*line;

	i = 0;
	if (!stash)
		return (ft_free_stash(&stash, 0));
	while (stash[i] != '\n')
		i++;
	line = (char *)malloc(i + 2);
	if (!line)
		return (ft_free_stash(&line, 0));
	j = 0;
	while (j < i + 1)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

extern __inline__ char
	*ft_recreate_stash(char *stash)
{
	register size_t	idx;
	char			*res;

	idx = 0;
	if (!stash)
		return (NULL);
	while (stash[idx] != '\n')
		idx++;
	if (stash[idx + 1] == '\0')
		return (ft_free_stash(&stash, 0));
	res = ft_substr(stash, idx + 1, ft_strlen(stash));
	ft_free_stash(&stash, 0);
	return (res);
}
