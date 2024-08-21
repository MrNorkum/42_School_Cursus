# ft_printf - Custom `printf` Implementation

## Overview
`ft_printf` is a custom implementation of the standard C `printf` function. It provides formatted output conversion and is designed to mimic the behavior of the standard `printf` function while being fully compatible with the custom library.

## Table of Contents
- [Installation](#installation)
- [Usage](#usage)
    - [%s](#s)
    - [%d-%i](#d-i)
    - [%u](#u)
    - [%x-%X](#x-x)
    - [%p](#p)
    - [%%](#-1)
- [Supported Formats](#supported-formats)
- [Constants](#constants)
- [License](#license)

## Installation

To use `ft_printf` in your project, simply clone the repository and include the `ft_printf.h` header file in your C source files. Compile the source files along with your project.

```bash
git clone <repository_url>
```

## Usage

To use the ft_printf function, make sure to include the ft_printf.h header file in your C files with its path:
```c
#include "./ft_printf.h"
```

```c
int main(void)
{
	int res;

	res = ft_printf("Hello World!\n");
	if (res == -1)
		return (res);
	return (0);
}
```

### \%s

```c
int main(void)
{
	int res;
	
	char *str = "";
	res = ft_printf("[%s]", str);
	if (res == -1)
		return (res);
	return (0);
}
```

### %d-%i

```c
int main(void)
{
	int res;
	
	int nbr = -13;
	res = ft_printf("[%d]", nbr);
	if (res == -1)
		return (res);
	return (0);
}
```

### %u
```c
int main(void)
{
	int res;
	
	unsigned int unbr = -1;
	res = ft_printf("[%u]", unbr);
	if (res == -1)
		return (res);
	return (0);
}
```

### %x-%X

```c
int main(void)
{
	int res;
	
	unsigned int xnbr = 13;
	res = ft_printf("[%X][%x]", xnbr);
	if (res == -1)
		return (res);
	return (0);
}
```

### %p
```c
int main(void)
{
	int res;
	
	void *ptr = &res;
	res = ft_printf("[%p]", ptr);
	if (res == -1)
		return (res);
	return (0);
}
```

### %%
```c
int main(void)
{
	int res;
	
	res = ft_printf("[%%]");
	if (res == -1)
		return (res);
	return (0);
}
```

