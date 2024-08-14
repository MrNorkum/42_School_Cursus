
# Libft - C Standard Library Extension

## Overview
`libft` is a custom C library that extends the functionalities of the standard C library. It includes a collection of approximately 40 functions that handle string manipulation, memory management, linked lists, and more. This library is designed to be a foundational toolset for C developers, providing commonly needed utilities in a reusable format.

## Table of Contents
- [Installation](#installation)
- [Usage](#usage)
- [Functions](#functions)
  - [Convert Functions](#convert-functions)
  - [Boolean Functions](#boolean-functions)
  - [Memory Functions](#memory-functions)
  - [String Functions](#string-functions)
  - [Memory Allocation Functions](#memory-allocation-functions)
  - [Print Functions](#print-functions)
  - [List Functions](#list-functions)
- [License](#license)

## Installation

To use `libft` in your project, simply clone the repository and include the `libft.h` header file in your C source files. Compile the source files along with your project.

```bash
git clone <repository_url>
```

## Usage

To use the library, make sure to include the libft.h header file in your C files with its path:
```c
#include "./libft.h"
```

## Functions

### Convert Functions

Converts a string to an integer.
```c
int ft_atoi(const char *str);
```
Converts an integer to a string.
```c
char *ft_itoa(int n);
```
Converts a character to uppercase.
```c
int ft_toupper(int c);
```
Converts a character to lowercase.
```c
int ft_tolower(int c);
```

### Boolean Functions

Checks if the character is alphabetic.
```c
int ft_isalpha(int c);
```
Checks if the character is a digit.
```c
int ft_isdigit(int c);
```
Checks if the character is alphanumeric.
```c
int ft_isalnum(int c);
```
Checks if the character is an ASCII character.
```c
int ft_isprint(int c);
```
Checks if the character is printable.
```c
int ft_isascii(int c);
```

### Memory Functions

Sets the first n bytes of the memory area pointed to by s to zero.
```c
void ft_bzero(void *s, size_t n);
```
Fills the first len bytes of the memory area pointed to by b with the constant byte c.
```c
void *ft_memset(void *b, int c, size_t len);
```
Compares the first n bytes of two memory areas.
```c
int ft_memcmp(const void *s1, const void *s2, size_t n);
```
Scans the initial n bytes of the memory area pointed to by s for the first instance of c.
```c
void *ft_memchr(const void *s, int c, size_t n);
```
Copies n bytes from memory area src to memory area dst.
```c
void *ft_memcpy(void *dst, const void *src, size_t n);
```
Copies len bytes from memory area src to memory area dst, handling overlap.
```c
void *ft_memmove(void *dst, const void *src, size_t len);
```

### String Functions

Calculates the length of a string.
```c
size_t ft_strlen(const char *s);
```
Compares at most the first n bytes of two strings.
```c
int ft_strncmp(const char *s1, const char *s2, size_t n);
```
Locates the first occurrence of c in the string s.
```c
char *ft_strchr(const char *s, int c);
```
Locates the last occurrence of c in the string s.
```c
char *ft_strrchr(const char *s, int c);
```
Copies up to dstsize - 1 characters from the string src to dst, null-terminating the result.
```c
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);
```
Appends the string src to the end of dst, ensuring that the result is null-terminated.
```c
size_t ft_strlcat(char *dst, const char *src, size_t dstsize);
```
Locates the first occurrence of the null-terminated string needle in the string haystack, where not more than len characters are searched.
```c
char *ft_strnstr(const char *haystack, const char *needle, size_t len);
```
Applies the function f to each character of the string passed as argument, and passing its index as the first argument to f.
```c
void ft_striteri(char *s, void (*f)(unsigned int, char *));
```

### Memory Allocation Functions

Allocates memory for an array of count elements of size bytes each and returns a pointer to the allocated memory.
```c
void *ft_calloc(size_t count, size_t size);
```
Duplicates the string s1, allocating memory for it.
```c
char *ft_strdup(const char *s1);
```
Allocates and returns a substring from the string s.
```c
char *ft_substr(char const *s, unsigned int start, size_t len);
```
Allocates and returns a new string, which is the result of the concatenation of s1 and s2.
```c
char *ft_strjoin(char const *s1, char const *s2);
```
Allocates and returns a copy of s1 with the characters specified in set removed from the beginning and the end of the string.
```c
char *ft_strtrim(char const *s1, char const *set);
```
Allocates and returns an array of strings obtained by splitting s using the character c as a delimiter.
```c
char **ft_split(char const *s, char c);
```
Applies the function f to each character of the string s to create a new string resulting from successive applications of f.
```c
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
```

### Print Functions

Outputs the character c to the given file descriptor.
```c
void ft_putchar_fd(char c, int fd);
```
Outputs the string s to the given file descriptor.
```c
void ft_putstr_fd(char *s, int fd);
```
Outputs the string s to the given file descriptor, followed by a newline.
```c
void ft_putendl_fd(char *s, int fd);
```
Outputs the integer n to the given file descriptor.
```c
void ft_putnbr_fd(int n, int fd);
```
Outputs the character c to the standard output.
```c
void ft_putchar(char c);
```
Outputs the string s to the standard output.
```c
void ft_putstr(char *s);
```
Outputs the string s to the standard output, followed by a newline.
```c
void ft_putendl(char *s);
```
Outputs the integer n to the standard output.
```c
void ft_putnbr(int n);
```

### List Functions

Allocates and returns a new element of the list. The variable content is initialized with the value of the parameter content.
```c
t_list *ft_lstnew(void *content);
```
Adds the element new at the beginning of the list.
```c
void ft_lstadd_front(t_list **lst, t_list *new);
```
Counts the number of elements in a list.
```c
int ft_lstsize(t_list *lst);
```
Returns the last element of the list.
```c
t_list *ft_lstlast(t_list *lst);
```
Adds the element new at the end of the list.
```c
void ft_lstadd_back(t_list **lst, t_list *new);
```
Takes as a parameter an element and frees the memory of the element's content using the function del.
```c
void ft_lstdelone(t_list *lst, void (*del)(void *));
```
Deletes and frees the given element and every successor of that element, using the function del and free.
```c
void ft_lstclear(t_list **lst, void (*del)(void *));
```
Iterates through the list lst and applies the function f to the content of each element.
```c
void ft_lstiter(t_list *lst, void (*f)(void *));
```
Iterates through the list lst and applies the function f to the content of each element, creating a new list resulting from the successive applications of f.
```c
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
```

## License

```
Bu taslağı ihtiyaçlarınıza göre düzenleyebiliriz. Herhangi bir ekleme veya çıkarma yapmak isterseniz, bana söylemeniz yeterli.
```
