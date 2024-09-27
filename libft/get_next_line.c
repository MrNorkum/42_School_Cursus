/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 05:35:14 by hkeles            #+#    #+#             */
/*   Updated: 2024/05/26 05:35:15 by hkeles           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "libft.h" /*
# define BUFFER_SIZE
#   char *ft_strjoin(char const *, char const *);
#   char *ft_strchr(const char *, int);
#   void *ft_free(void **);
#   char *ft_strdup(const char *);
#        */
#include <stdlib.h> /*
# define NULL
#   void *malloc(size_t);
#        */
#include <unistd.h> /*
#ssize_t read(int, void *, size_t);
#        */
#include <sys/syslimits.h> /*
# define OPEN_MAX
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ void	*ft_free_stash(char **stash, register int mod);
extern __inline__ char	*ft_extract_line(char *stash);
extern __inline__ char	*ft_recreate_stash(char *stash);
/* *************************** [^] PROTOTYPES [^] *************************** */

char
	*get_next_line(register int fd)
{
	char			buf[BUFFER_SIZE + 1];
	static char		*stash = NULL;
	register long	ret;
	char			*line;
	char			*res;

	ret = BUFFER_SIZE;
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if ((ret == 0 && !stash) || ret == -1)
			return (ft_free_stash(&stash, 0));
		buf[ret] = '\0';
		res = ft_strjoin(stash, buf);
		ft_free_stash(&stash, 0);
		stash = res;
		if (ft_strchr(stash, '\n'))
		{
			line = ft_extract_line(stash);
			if (!line)
				return (ft_free_stash(&stash, 0));
			return (stash = ft_recreate_stash(stash), line);
		}
	}
	return (ft_free_stash(&stash, 1));
}

char
	*get_next_line_bonus(register int fd)
{
	char			buf[BUFFER_SIZE + 1];
	static char		*stash[OPEN_MAX];
	register long	ret;
	char			*line;
	char			*res;

	ret = BUFFER_SIZE;
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if ((ret == 0 && !stash[fd]) || ret == -1)
			return (ft_free_stash(&stash[fd], 0));
		buf[ret] = '\0';
		res = ft_strjoin(stash[fd], buf);
		ft_free_stash(&stash[fd], 0);
		stash[fd] = res;
		if (ft_strchr(stash[fd], '\n'))
		{
			line = ft_extract_line(stash[fd]);
			if (!line)
				return (ft_free_stash(&stash[fd], 0));
			return (stash[fd] = ft_recreate_stash(stash[fd]), line);
		}
	}
	return (ft_free_stash(&stash[fd], 1));
}

extern __inline__ void
	*ft_free_stash(char **stash, register int mod)
{
	char	*line;

	if (*stash && !mod)
		return (ft_free((void **)stash));
	else if (*stash && mod)
	{
		line = ft_strdup(*stash);
		ft_free((void **)stash);
		return (line);
	}
	return (NULL);
}

extern __inline__ char
	*ft_extract_line(char *stash)
{
	register size_t	i;
	register size_t	j;
	char			*line;

	if (!stash)
		return (NULL);
	i = ft_strchr(stash, '\n') - stash;
	line = (char *)malloc(i + 2);
	if (!line)
		return (NULL);
	j = -1;
	while (++j < i + 1)
		line[j] = stash[j];
	line[j] = '\0';
	return (line);
}

extern __inline__ char
	*ft_recreate_stash(char *stash)
{
	char	*res;

	if (!stash)
		return (NULL);
	if (!*(ft_strchr(stash, '\n') + 1))
		return (ft_free_stash(&stash, 0));
	res = ft_strdup(ft_strchr(stash, '\n') + 1);
	ft_free_stash(&stash, 0);
	return (res);
}
