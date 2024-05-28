/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:42:58 by hkeles            #+#    #+#             */
/*   Updated: 2024/05/23 20:03:20 by hkeles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H 202405
/* **************************** [v] INCLUDES [v] **************************** */
# include <stdlib.h> /*
#typedef size_t;
#        */
/* **************************** [^] INCLUDES [^] **************************** */
/* **************************** [v] STRUCTS [v] ***************************** */
struct s_list
{
	void			*content;
	struct s_list	*next;
};
/* **************************** [^] STRUCTS [^] ***************************** */
/* **************************** [v] TYPEDEF [v] ***************************** */
typedef struct s_list	t_list;
/* **************************** [^] TYPEDEF [^] ***************************** */
/* *********************** [v] CONVERT FUNCTIONS [v] ************************ */
extern int          ft_atoi(const char *str);
extern char         *ft_itoa(register int n);
extern int          ft_toupper(int c);
extern int          ft_tolower(int c);
/* *********************** [^] CONVERT FUNCTIONS [^] ************************ */
/* ************************* [v] BOOL FUNCTIONS [v] ************************* */
extern int          ft_isalpha(int c);
extern int          ft_isdigit(int c);
extern int          ft_isalnum(int c);
extern int          ft_isascii(int c);
extern int          ft_isprint(int c);
/* ************************* [^] BOOL FUNCTIONS [^] ************************* */
/* ************************ [v] MEMORY FUNCTIONS [v] ************************ */
extern void         ft_bzero(void *s, register size_t n);
extern void         *ft_memset(void *b, register int c, register size_t len);
extern int          ft_memcmp(const void *s1, const void *s2,
                        register size_t n);
extern void         *ft_memchr(const void *s, register int c,
                        register size_t n);
extern void         *ft_memcpy(void *dst, const void *src, register size_t n);
extern void         *ft_memmove(void *dst, const void *src,
                        register size_t len);
/* ************************ [^] MEMORY FUNCTIONS [^] ************************ */
/* ************************ [v] STRING FUNCTIONS [v] ************************ */
extern size_t       ft_strlen(const char *s);
extern int          ft_strncmp(const char *s1, const char *s2,
                        register size_t n);
extern char         *ft_strchr(const char *s, register int c);
extern char         *ft_strrchr(const char *s, register int c);
extern size_t       ft_strlcpy(char *dst, const char *src,
                        register size_t dstsize);
extern size_t       ft_strlcat(char *dst, const char *src,
                        register size_t dstsize);
extern char         *ft_strnstr(const char *haystack, const char *needle,
                        register size_t len);
extern void         ft_striteri(char *s, void (*f)(unsigned int, char *));
/* ************************ [^] STRING FUNCTIONS [^] ************************ */
/* ************************ [v] MALLOC FUNCTIONS [v] ************************ */
extern void         *ft_calloc(register size_t count, register size_t size);
extern char         *ft_strdup(const char *s1);
extern char         *ft_substr(char const *s, register unsigned int start,
                        register size_t len);
extern char         *ft_strjoin(char const *s1, char const *s2);
extern char         *ft_strtrim(char const *s1, char const *set);
extern char         **ft_split(char const *s, register char c);
extern char         *ft_strmapi(char const *s, char (*f)(unsigned int, char));
/* ************************ [^] MALLOC FUNCTIONS [^] ************************ */
/* ************************ [v] PRINT FUNCTIONS [v] ************************* */
extern void         ft_putchar_fd(char c, register int fd);
extern void         ft_putstr_fd(char *s, register int fd);
extern void         ft_putendl_fd(char *s, register int fd);
extern void         ft_putnbr_fd(register int n, register int fd);

extern void         ft_putchar(char c);
extern void         ft_putstr(char *s);
extern void         ft_putendl(char *s);
extern void         ft_putnbr(register int n);
/* ************************ [^] PRINT FUNCTIONS [^] ************************* */
/* ************************* [v] LIST FUNCTIONS [v] ************************* */
extern t_list       *ft_lstnew(void *content);
extern void         ft_lstadd_front(t_list **lst, t_list *new);
extern int          ft_lstsize(t_list *lst);
extern t_list       *ft_lstlast(t_list *lst);
extern void         ft_lstadd_back(t_list **lst, t_list *new);
extern void         ft_lstdelone(t_list *lst, void (*del)(void *));
extern void         ft_lstclear(t_list **lst, void (*del)(void *));
extern void         ft_lstiter(t_list *lst, void (*f)(void *));
extern t_list       *ft_lstmap(t_list *lst, void *(*f)(void *),
                        void (*del)(void *));
/* ************************* [^] LIST FUNCTIONS [^] ************************* */
#endif /* LIBFT_H */
