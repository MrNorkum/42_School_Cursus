
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
```c
int ft_atoi(const char *str);
```
Converts a string to an integer.
```c
char *ft_itoa(int n);
```
Converts an integer to a string.
```c
int ft_toupper(int c);
```
Converts a character to uppercase.
```c
int ft_tolower(int c);
```
Converts a character to lowercase.
