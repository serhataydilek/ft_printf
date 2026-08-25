*This project has been created as part of the 42 curriculum by saydilek.*

# ft_printf

## Description

`ft_printf` is a reimplementation of the standard C `printf()` function.

The goal of the project is to understand variadic functions in C, format-string parsing, type-specific argument handling, number conversion, and formatted output using low-level functions such as `write()`.

The implementation supports the mandatory conversions:

* `%c` — character
* `%s` — string
* `%p` — pointer in hexadecimal format
* `%d` — signed decimal integer
* `%i` — signed decimal integer
* `%u` — unsigned decimal integer
* `%x` — lowercase hexadecimal
* `%X` — uppercase hexadecimal
* `%%` — percent character

The function also returns the total number of characters written, matching the main behavior of the standard `printf()` function.

## Instructions

Compile the library with:

```bash
make
```

This creates:

```text
libftprintf.a
```

at the root of the repository.

Available Makefile rules:

```bash
make
make clean
make fclean
make re
```

To use the library in another C program:

```c
#include "ft_printf.h"

int	main(void)
{
	ft_printf("Hello %s! Number: %d\n", "world", 42);
	return (0);
}
```

Compile it with:

```bash
cc main.c libftprintf.a
```

## Implementation

The format string is read one character at a time.

Normal characters are written directly to standard output. When a `%` character is encountered, the following character is interpreted as a conversion specifier and dispatched to the appropriate helper function.

Variadic arguments are accessed using:

```text
va_list
va_start
va_arg
va_end
```

Each output helper returns the number of characters it writes. These values are accumulated by `ft_printf()` so that the final return value represents the total number of printed characters.

Decimal and hexadecimal numbers are printed recursively. Each recursive call processes the higher-order digits first, while the remainder operation selects the current digit.

For hexadecimal output, the implementation uses digit sets:

```text
0123456789abcdef
0123456789ABCDEF
```

This approach avoids buffering the output and keeps the conversion logic relatively small and reusable.

No complex data structure is required for this project. The main structures used are the format string and the `va_list` state used to access variadic arguments. This fits the sequential nature of format parsing and avoids unnecessary storage.

## Resources

References used while studying and implementing the project:

* `man 3 printf`
* `man 3 stdarg`
* `man 3 va_start`
* `man 3 va_arg`
* `man 3 va_end`
* `man 2 write`

### AI Usage

AI was used as a learning and debugging aid during the project.

It was used to:

* clarify how variadic arguments and default argument promotions work;
* reason about the types required by `va_arg`;
* understand character-count return values;
* debug format-string indexing and compiler warnings;
* discuss hexadecimal and pointer conversion logic;
* review edge cases and test ideas;
* discuss code organization, Makefile structure, and README requirements.

The implementation was developed iteratively and tested while working through the underlying concepts rather than treating AI output as a substitute for understanding the project.
