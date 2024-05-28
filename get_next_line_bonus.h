/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 02:37:23 by hkeles            #+#    #+#             */
/*   Updated: 2024/05/24 03:07:07 by hkeles           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H 202405
/* *************************** [v] CONSTANTS [v] **************************** */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 13
# endif /* BUFFER_SIZE */
/* *************************** [^] CONSTANTS [^] **************************** */
/* **************************** [v] INCLUDES [v] **************************** */
# include <stdlib.h> /*
# typedef size_t;
#         */
/* **************************** [^] INCLUDES [^] **************************** */
/* ***************** [v] ./get_next_line_utils_bonus.c [v] ****************** */
extern size_t	ft_strlen(const char *s);
extern char		*ft_strdup(const char *s1);
extern char		*ft_strjoin(char const *s1, char const *s2);
extern char		*ft_substr(char const *s, register unsigned int start,
					register size_t len);
extern void		*ft_free_stash(char **stash, register int create_line);
extern char		*get_next_line(int fd);
/* ***************** [^] ./get_next_line_utils_bonus.c [^] ****************** */
#endif /* GET_NEXT_LINE_BONUS_H */
