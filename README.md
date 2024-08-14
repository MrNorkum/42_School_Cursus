
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

Include the library header in your C files:

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




