*This project has been created as part of the 42 curriculum by jsingh.*

## Description

Libft is my own version of a bunch of standard C library functions, plus some extra utility functions for strings, memory and linked lists. Every project after this one in the common core uses this library, so it's basically my toolbox from here on.

- Part 1: 23 reimplemented libc functions
- Part 2: 11 extra utility functions
- Bonus: 9 linked list functions

## Instructions

Compile with:

```
make
```

This builds `libft.a`.

- `make` / `make all` - builds the mandatory part
- `make bonus` - builds mandatory + bonus
- `make clean` - removes .o files
- `make fclean` - removes .o files and libft.a
- `make re` - fclean then rebuild

To use it in another project:

```c
#include "libft.h"
```

```
cc -Wall -Wextra -Werror your_program.c -L. -lft
```

## Resources

- man7.org for the man pages
- 42 subject pdf
- learn-c.org and Beej's guide when I got stuck on pointers

## Author

jsingh - 42 Warsaw

---

# Function notes

Below is my own cheat sheet for every function - the empty template I started from, the prototype, what the man page actually says, what it returns, and a quick test I ran to check it against the real function.

---