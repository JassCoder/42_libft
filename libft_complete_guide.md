# How to Make Libft: All Functions — Prerequisites and Practice

### A Complete Field Guide for 42 Students

---

**Author's Note**

This book was written for one purpose: to make sure you never stare at a blank `.c` file wondering where to begin. Every function in Libft — all 43 of them — is dissected here. Not just what it does, but *why* it works, what can break it, and how to think about it.

You finished the Piscine. You know the basics. Now we go deeper.

Read this alongside your code. Build as you go. By the end, you will not just have a working Libft — you will understand every line you wrote.

---

## Table of Contents

- **Chapter 1** — Introduction to Libft
- **Chapter 2** — C Fundamentals You Must Know First
- **Chapter 3** — Makefile Mastery
- **Chapter 4** — Part 1: The 23 Libc Functions
- **Chapter 5** — Part 2: The 11 Additional Functions
- **Chapter 6** — Part 3: The 9 Bonus Linked-List Functions
- **Chapter 7** — Testing Your Library
- **Chapter 8** — Submission and Evaluation
- **Chapter 9** — Beyond Libft

---

# CHAPTER 1: Introduction to Libft

---

## 1.1 What Is Libft?

Libft is the first real project at 42. Its goal sounds simple: **write your own C standard library from scratch**. You will re-implement functions that already exist in `<string.h>`, `<ctype.h>`, `<stdlib.h>`, and `<stdio.h>` — but you will write every single line yourself, with no calls to the originals.

The result is a file called `libft.a` — a static library you will link against in almost every project that follows.

Why? Because 42 wants you to know how the tools you use actually work. A blacksmith does not just use a hammer; they know how to make one. After Libft, you will be able to look at `strlen` and understand it at the byte level. That understanding compounds into everything else.

```
┌─────────────────────────────────────────────────────┐
│                   YOUR FUTURE PROJECTS               │
│   get_next_line │ ft_printf │ push_swap │ minishell  │
└───────────────────────┬─────────────────────────────┘
                        │ links against
                        ▼
              ┌─────────────────┐
              │    libft.a      │  ← YOU BUILD THIS
              └─────────────────┘
                        │ built from
                        ▼
              ┌─────────────────┐
              │ ft_strlen.c     │
              │ ft_memcpy.c     │
              │ ft_split.c      │
              │ ft_lstnew.c     │
              │ ... 39 more ... │
              └─────────────────┘
```

## 1.2 The 42 Pedagogy

42 does not have teachers in the traditional sense. You learn by doing, by reading, and by explaining to peers. The Libft evaluation is peer-to-peer — a fellow student will sit down with you, read your code, run tests, and ask questions.

This means your code must be:

- **Readable** — not just correct
- **Explainable** — you will be asked "why did you do it this way?"
- **Norminette-compliant** — the linter is non-negotiable

**The Norm in brief:**

```
- Max 25 lines per function
- Max 80 characters per line
- Max 5 parameters per function
- No for loops (only while)
- No variable declarations after the first instructions
- Function names: snake_case with ft_ prefix
- One instruction per line
```

> **Tip:** Run `norminette` early and often. Do not write 100 lines and then try to fix norm errors — it is painful. Build one function, norm-check it, move on.

## 1.3 Project Structure

At the end of Libft, your directory should look like this:

```
libft/
├── Makefile
├── libft.h
├── ft_isalpha.c
├── ft_isdigit.c
├── ft_isalnum.c
├── ft_isascii.c
├── ft_isprint.c
├── ft_strlen.c
├── ft_memset.c
├── ft_bzero.c
├── ft_memcpy.c
├── ft_memmove.c
├── ft_strlcpy.c
├── ft_strlcat.c
├── ft_toupper.c
├── ft_tolower.c
├── ft_strchr.c
├── ft_strrchr.c
├── ft_strncmp.c
├── ft_memchr.c
├── ft_memcmp.c
├── ft_strnstr.c
├── ft_atoi.c
├── ft_calloc.c
├── ft_strdup.c
├── ft_substr.c
├── ft_strjoin.c
├── ft_strtrim.c
├── ft_split.c
├── ft_itoa.c
├── ft_strmapi.c
├── ft_striteri.c
├── ft_putchar_fd.c
├── ft_putstr_fd.c
├── ft_putendl_fd.c
├── ft_putnbr_fd.c
├── ft_lstnew.c          (bonus)
├── ft_lstadd_front.c    (bonus)
├── ft_lstsize.c         (bonus)
├── ft_lstlast.c         (bonus)
├── ft_lstadd_back.c     (bonus)
├── ft_lstdelone.c       (bonus)
├── ft_lstclear.c        (bonus)
├── ft_lstiter.c         (bonus)
└── ft_lstmap.c          (bonus)
```

## 1.4 Setting Up Your Environment

```bash
# Clone your 42 repository
git clone git@github.com:YOUR_42_LOGIN/libft.git
cd libft

# Create your header file
touch libft.h

# Create your Makefile
touch Makefile

# Start writing functions
touch ft_strlen.c
```

Your `libft.h` skeleton (we will fill this in):

```c
#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

/* ===== PART 1: LIBC FUNCTIONS ===== */

int     ft_isalpha(int c);
int     ft_isdigit(int c);
int     ft_isalnum(int c);
int     ft_isascii(int c);
int     ft_isprint(int c);
size_t  ft_strlen(const char *s);
void    *ft_memset(void *b, int c, size_t len);
void    ft_bzero(void *s, size_t n);
void    *ft_memcpy(void *dst, const void *src, size_t n);
void    *ft_memmove(void *dst, const void *src, size_t len);
size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t  ft_strlcat(char *dst, const char *src, size_t dstsize);
int     ft_toupper(int c);
int     ft_tolower(int c);
char    *ft_strchr(const char *s, int c);
char    *ft_strrchr(const char *s, int c);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
void    *ft_memchr(const void *s, int c, size_t n);
int     ft_memcmp(const void *s1, const void *s2, size_t n);
char    *ft_strnstr(const char *haystack, const char *needle, size_t len);
int     ft_atoi(const char *str);
void    *ft_calloc(size_t count, size_t size);
char    *ft_strdup(const char *s1);

/* ===== PART 2: ADDITIONAL FUNCTIONS ===== */

char    *ft_substr(char const *s, unsigned int start, size_t len);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_strtrim(char const *s1, char const *set);
char    **ft_split(char const *s, char c);
char    *ft_itoa(int n);
char    *ft_strmapi(char const *s, char (*f)(unsigned int, char));
void    ft_striteri(char *s, void (*f)(unsigned int, char*));
void    ft_putchar_fd(char c, int fd);
void    ft_putstr_fd(char *s, int fd);
void    ft_putendl_fd(char *s, int fd);
void    ft_putnbr_fd(int n, int fd);

/* ===== BONUS: LINKED LIST ===== */

typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;

t_list  *ft_lstnew(void *content);
void    ft_lstadd_front(t_list **lst, t_list *new);
int     ft_lstsize(t_list *lst);
t_list  *ft_lstlast(t_list *lst);
void    ft_lstadd_back(t_list **lst, t_list *new);
void    ft_lstdelone(t_list *lst, void (*del)(void *));
void    ft_lstclear(t_list **lst, void (*del)(void *));
void    ft_lstiter(t_list *lst, void (*f)(void *));
t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
```

---

### Chapter 1 Summary

- Libft is a static library of 43 re-implemented C functions
- It is the foundation for all future 42 projects
- The Norm is enforced — clean code is mandatory
- Peer evaluation means you must understand every line you write
- Structure: 23 libc functions + 11 additional + 9 bonus linked-list

### Chapter 1 Exercises

1. Create your `libft/` directory and initialize a git repository
2. Write out (by hand) all 43 function prototypes from memory
3. Run `norminette` on an empty file — make sure your environment is set up

---

# CHAPTER 2: C Fundamentals You Must Know First

---

Before writing a single function, you need to have a solid grip on these concepts. Every function in Libft uses at least one of them.

## 2.1 Memory: Stack vs. Heap

Think of memory as two different kinds of storage in your program.

```
┌─────────────────────────────────────────────┐
│                   MEMORY                    │
│                                             │
│  ┌──────────────┐    ┌──────────────────┐   │
│  │    STACK     │    │      HEAP        │   │
│  │              │    │                  │   │
│  │ Fast         │    │ Slower           │   │
│  │ Auto-freed   │    │ Manual free()    │   │
│  │ Fixed size   │    │ Dynamic size     │   │
│  │ Local vars   │    │ malloc() gives   │   │
│  └──────────────┘    └──────────────────┘   │
└─────────────────────────────────────────────┘
```

**Stack example — automatic:**
```c
void    example(void)
{
    char    buffer[100];  // Lives on the stack
    int     count;        // Lives on the stack
    // When the function returns, buffer and count are gone forever
}
```

**Heap example — manual:**
```c
void    example(void)
{
    char    *s;

    s = malloc(100);   // Asks the heap for 100 bytes
    if (!s)
        return ;
    // s survives after this function IF you return the pointer
    // YOU must call free(s) when done
}
```

**Why this matters for Libft:** Every function that returns a `char *` or `void *` that it allocated internally uses `malloc`. The caller is responsible for freeing it. This is documented in each function below.

## 2.2 Pointers and Pointer Arithmetic

A pointer is a variable that holds a memory address.

```c
char    str[] = "Hello";
char    *p;

p = str;      // p points to 'H' (address of str[0])
p++;          // p now points to 'e' (address of str[1])
p += 2;       // p now points to 'l' (address of str[3])
```

Visually:
```
str:  [ H ][ e ][ l ][ l ][ o ][ \0 ]
addr:  100   101  102  103  104   105

p = str    → p holds 100
p++        → p holds 101
p += 2     → p holds 103
```

**Dereferencing:** `*p` reads the value at the address p holds.

```c
char    *p = "Hello";
char    ch = *p;      // ch = 'H'
char    ch2 = *(p+1); // ch2 = 'e'
```

**Pointer to pointer:** Used in `ft_lstadd_front`, `ft_lstadd_back`, etc.

```c
void    modify(int **pp)
{
    **pp = 42;   // Change the int that the pointer-to-pointer points to
}

int main(void)
{
    int     n = 0;
    int     *p = &n;
    modify(&p);
    // n is now 42
}
```

## 2.3 The `size_t` Type

`size_t` is an **unsigned** integer type, defined in `<stddef.h>` (included via `<stdlib.h>`). It is guaranteed to be large enough to represent the size of any object in memory.

```c
size_t  len;
len = ft_strlen("Hello");  // len = 5
```

**Why not just use `int`?**

On a 64-bit system, `int` is 32 bits (max ~2 billion). `size_t` is 64 bits (max ~18 quintillion). For memory operations on large buffers, this matters. Also, `size_t` is **unsigned** — it cannot be negative, which matches the concept of a "size."

> **Warning:** Be careful when comparing `size_t` to negative integers.
>
> ```c
> size_t  n = 5;
> int     i = -1;
> if (i < n)  // This is FALSE! -1 gets converted to a huge unsigned number
>     printf("i is less");
> ```

## 2.4 Strings in C: Null-Termination

In C, a string is just an array of `char` values that ends with a null byte (`'\0'`, value 0).

```
"Hello"  stored as:  [ H ][ e ][ l ][ l ][ o ][ \0 ]
                       72   101  108  108  111    0
```

There is no hidden length field. Every function that works with strings must scan for `'\0'` to know where the string ends. This is why `strlen` works the way it does.

**Important:** If you allocate space for a string of n characters, you need **n + 1** bytes — one extra for the null terminator.

```c
char    *s = malloc(6);   // "Hello" = 5 chars + 1 null = 6 bytes
if (!s)
    return (NULL);
s[0] = 'H';
s[1] = 'e';
s[2] = 'l';
s[3] = 'l';
s[4] = 'o';
s[5] = '\0';  // CRITICAL — without this, your "string" is garbage
```

## 2.5 The `const` Qualifier

`const` tells the compiler (and the reader) that a value will not be modified through that pointer or variable.

```c
size_t  ft_strlen(const char *s);
//                ^^^^^ s points to characters that we won't change
```

If you try to modify through a `const` pointer, the compiler errors. This is a safety mechanism.

```c
void    ft_strlen(const char *s)
{
    *s = 'X';  // COMPILER ERROR: cannot write through const pointer
}
```

**Why functions take `const char *`:** It lets you pass both non-const strings AND string literals safely:
```c
ft_strlen("Hello");        // string literal — const char *
ft_strlen(my_buffer);      // modifiable buffer — also fine
```

## 2.6 The Header File

The header file (`libft.h`) is the **contract** your library publishes. It declares all functions so any `.c` file that includes it knows what functions exist and what types they take/return.

```c
// In libft.h:
size_t  ft_strlen(const char *s);  // declaration (prototype)

// In ft_strlen.c:
#include "libft.h"
size_t  ft_strlen(const char *s)   // definition
{
    size_t  len;
    len = 0;
    while (s[len])
        len++;
    return (len);
}

// In some_other.c:
#include "libft.h"
// Now we can call ft_strlen here because we declared it above
```

**Include guards** prevent the header from being included multiple times:

```c
#ifndef LIBFT_H       // "If LIBFT_H is not defined..."
# define LIBFT_H      // "Define it now"

// ... all your declarations ...

#endif                // "End the if"
```

---

### Chapter 2 Summary

| Concept | Key Point |
|---|---|
| Stack | Automatic, fast, local, no manual free |
| Heap | Manual, `malloc`/`free`, survives function scope |
| Pointers | Hold addresses; `*p` dereferences; `p++` moves |
| `size_t` | Unsigned, 64-bit on modern systems, for sizes |
| Null termination | Every C string ends in `'\0'` |
| `const` | Prevents modification, enables safe read-only access |
| Header guards | `#ifndef` / `#define` / `#endif` |

### Chapter 2 Exercises

1. Write a program that prints the address of each character in "Hello" using pointer arithmetic (no subscripts)
2. Allocate a string of 10 characters on the heap, write "test" into it, print it, then free it
3. Explain in your own words: why does `strlen` need the null terminator to work?

---

# CHAPTER 3: Makefile Mastery

---

Your Makefile is not optional. Without it, your submission is invalid. More importantly, a good Makefile is a professional habit — every serious C/C++ project uses one.

## 3.1 What Is a Makefile?

A Makefile is a build script that `make` reads. It describes how to compile your project. Instead of typing `gcc -Wall -Wextra -Werror -c ft_strlen.c -o ft_strlen.o` for 43 files, you type `make` once.

## 3.2 The Complete Libft Makefile

```makefile
# ============================================================
#  LIBFT MAKEFILE — Complete Annotated Version
# ============================================================

# ---- Variables ------------------------------------------------

NAME    = libft.a
# NAME is the output file. 'make' builds $(NAME).

CC      = cc
# CC is the compiler. Use 'cc' (not 'gcc' directly) for portability.

CFLAGS  = -Wall -Wextra -Werror
# CFLAGS are compiler flags passed to every compilation.
# -Wall   : enable all standard warnings
# -Wextra : enable extra warnings beyond -Wall
# -Werror : treat warnings as errors (zero tolerance)

AR      = ar rcs
# AR creates and updates static library archives.
# r = insert/replace files in archive
# c = create archive if it doesn't exist
# s = write index (symbol table) into archive

RM      = rm -f
# RM removes files. -f = force (no error if file doesn't exist)

# ---- Source Files ---------------------------------------------

SRCS    = ft_isalpha.c \
          ft_isdigit.c \
          ft_isalnum.c \
          ft_isascii.c \
          ft_isprint.c \
          ft_strlen.c \
          ft_memset.c \
          ft_bzero.c \
          ft_memcpy.c \
          ft_memmove.c \
          ft_strlcpy.c \
          ft_strlcat.c \
          ft_toupper.c \
          ft_tolower.c \
          ft_strchr.c \
          ft_strrchr.c \
          ft_strncmp.c \
          ft_memchr.c \
          ft_memcmp.c \
          ft_strnstr.c \
          ft_atoi.c \
          ft_calloc.c \
          ft_strdup.c \
          ft_substr.c \
          ft_strjoin.c \
          ft_strtrim.c \
          ft_split.c \
          ft_itoa.c \
          ft_strmapi.c \
          ft_striteri.c \
          ft_putchar_fd.c \
          ft_putstr_fd.c \
          ft_putendl_fd.c \
          ft_putnbr_fd.c

BONUS_SRCS = ft_lstnew.c \
             ft_lstadd_front.c \
             ft_lstsize.c \
             ft_lstlast.c \
             ft_lstadd_back.c \
             ft_lstdelone.c \
             ft_lstclear.c \
             ft_lstiter.c \
             ft_lstmap.c

# ---- Object Files (pattern substitution) ----------------------

OBJS        = $(SRCS:.c=.o)
# This substitutes .c with .o in every name in SRCS
# ft_strlen.c → ft_strlen.o

BONUS_OBJS  = $(BONUS_SRCS:.c=.o)

# ---- Rules ----------------------------------------------------

all: $(NAME)
# 'make' or 'make all' builds the library

$(NAME): $(OBJS)
    $(AR) $(NAME) $(OBJS)
# When all .o files exist, run: ar rcs libft.a ft_strlen.o ft_bzero.o ...
# This packs all object files into the static library

%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@
# Pattern rule: how to build ANY .o from its corresponding .c
# $<  = the first prerequisite (the .c file)
# $@  = the target (the .o file)
# So: cc -Wall -Wextra -Werror -c ft_strlen.c -o ft_strlen.o

bonus: $(OBJS) $(BONUS_OBJS)
    $(AR) $(NAME) $(OBJS) $(BONUS_OBJS)
# 'make bonus' includes the linked-list functions too

clean:
    $(RM) $(OBJS) $(BONUS_OBJS)
# 'make clean' deletes all object files

fclean: clean
    $(RM) $(NAME)
# 'make fclean' deletes object files AND the library itself

re: fclean all
# 'make re' is a full rebuild: delete everything, then rebuild

.PHONY: all clean fclean re bonus
# .PHONY tells make these are not real files — just command names
# Without .PHONY, if a file named 'clean' existed, 'make clean' would do nothing
```

> **Warning:** The indentation in a Makefile MUST be a real **TAB character**, not spaces. If you use spaces, `make` will error with `Missing separator`. In vim, set your editor to insert tabs.

## 3.3 How `ar` Works

`ar rcs libft.a ft_strlen.o ft_memset.o ...`

This creates an archive file (`.a` = archive). An archive is just a collection of `.o` files bundled together with an index. When you link a program with `-lft`, the linker looks into `libft.a` and pulls out only the `.o` files it actually needs.

```
libft.a
├── ft_strlen.o
├── ft_memset.o
├── ft_bzero.o
└── ... (all your .o files)
```

## 3.4 The Build Process Visualized

```
ft_strlen.c
    │
    │  cc -Wall -Wextra -Werror -c ft_strlen.c -o ft_strlen.o
    ▼
ft_strlen.o ─────┐
                 │
ft_memset.o ─────┤   ar rcs libft.a *.o
                 ├──────────────────────► libft.a
ft_bzero.o ──────┤
                 │
... (43 files) ──┘
```

## 3.5 Using Your Library

Once you have `libft.a`, link it in other projects:

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
# -L.  = look for libraries in the current directory
# -lft = link against libft.a (note: 'lib' prefix and '.a' suffix are implied)
```

---

### Chapter 3 Summary

| Variable | Purpose |
|---|---|
| `NAME` | Output library name (`libft.a`) |
| `CC` | Compiler (`cc`) |
| `CFLAGS` | Flags: `-Wall -Wextra -Werror` |
| `AR` | Archive creator: `ar rcs` |
| `RM` | Remove: `rm -f` |

| Rule | Action |
|---|---|
| `make` / `make all` | Build the library |
| `make clean` | Delete `.o` files |
| `make fclean` | Delete `.o` files and `libft.a` |
| `make re` | Full rebuild |
| `make bonus` | Include linked-list functions |

### Chapter 3 Exercises

1. Write a minimal Makefile that compiles a single-file `hello.c` program
2. Add `clean` and `fclean` rules to it
3. Verify that `make re` triggers a complete rebuild

---

# CHAPTER 4: Part 1 — The 23 Libc Functions

---

> **How to read these chapters:** Each function follows the same structure:
> 1. Prototype and plain-English purpose
> 2. The original man page behavior you are reproducing
> 3. Complete implementation with line-by-line comments
> 4. Edge cases and how to handle them
> 5. Test cases with expected output
> 6. Common mistakes

---

## 4.1 ft_isalpha

### Prototype and Purpose

```c
int ft_isalpha(int c);
```

Returns non-zero if `c` is an alphabetic letter (a–z or A–Z), zero otherwise.

**Man page:** `isalpha(3)` — checks for an alphabetic character.

### Why `int` and not `char`?

The original `isalpha` takes an `int` because `char` can be signed on some systems. To avoid passing a negative value for characters above 127, the standard uses `int`. You must match this signature exactly.

### Implementation

```c
#include "libft.h"

int ft_isalpha(int c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
```

**Line by line:**

`return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));`
- Character literals in C are just their ASCII values: `'a'` = 97, `'z'` = 122, `'A'` = 65, `'Z'` = 90.
- This checks if `c` falls in the lowercase range OR the uppercase range.
- We return the result of the boolean expression directly: 0 (false) or 1 (true).

> **Note:** The real `isalpha` is locale-sensitive and may return non-zero for accented characters like `é`. Your implementation only needs to handle standard ASCII.

### ASCII Reference

```
Dec  Char  |  Dec  Char
-----------|-----------
 65   A    |   97   a
 66   B    |   98   b
 ...       |  ...
 90   Z    |  122   z
```

### Test Cases

```c
ft_isalpha('a')   → 1 (non-zero, truthy)
ft_isalpha('Z')   → 1
ft_isalpha('0')   → 0
ft_isalpha(' ')   → 0
ft_isalpha('\0')  → 0
ft_isalpha(256)   → 0 (out of ASCII range)
ft_isalpha(-1)    → 0
```

### Common Mistakes

- Using `>= 'a' && <= 'z'` without the variable: write `c >= 'a' && c <= 'z'`
- Forgetting uppercase range
- Returning a `char` instead of `int`

---

## 4.2 ft_isdigit

### Prototype and Purpose

```c
int ft_isdigit(int c);
```

Returns non-zero if `c` is a decimal digit (0–9), zero otherwise.

### Implementation

```c
#include "libft.h"

int ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}
```

**Line by line:**

`return (c >= '0' && c <= '9');`
- `'0'` = 48, `'9'` = 57 in ASCII.
- Checks if `c` is within the digit range.

### Test Cases

```c
ft_isdigit('5')   → 1
ft_isdigit('0')   → 1
ft_isdigit('9')   → 1
ft_isdigit('a')   → 0
ft_isdigit(' ')   → 0
ft_isdigit(-1)    → 0
```

---

## 4.3 ft_isalnum

### Prototype and Purpose

```c
int ft_isalnum(int c);
```

Returns non-zero if `c` is alphanumeric (letter or digit), zero otherwise.

### Implementation

```c
#include "libft.h"

int ft_isalnum(int c)
{
    return (ft_isalpha(c) || ft_isdigit(c));
}
```

**Line by line:**

`return (ft_isalpha(c) || ft_isdigit(c));`
- Reuse the functions you already wrote. This is the spirit of building a library.
- If either check is true, the result is non-zero.

> **Why this matters:** This demonstrates composition — building complex behavior from simpler pieces. You will do this constantly in larger projects.

### Test Cases

```c
ft_isalnum('a')   → 1
ft_isalnum('5')   → 1
ft_isalnum('Z')   → 1
ft_isalnum('!')   → 0
ft_isalnum('\0')  → 0
```

---

## 4.4 ft_isascii

### Prototype and Purpose

```c
int ft_isascii(int c);
```

Returns non-zero if `c` is a 7-bit ASCII character (0–127), zero otherwise.

### Implementation

```c
#include "libft.h"

int ft_isascii(int c)
{
    return (c >= 0 && c <= 127);
}
```

**Line by line:**

`return (c >= 0 && c <= 127);`
- Standard ASCII is 7-bit: values 0 through 127.
- Characters above 127 are extended ASCII or Unicode — not standard ASCII.

### Test Cases

```c
ft_isascii(0)     → 1
ft_isascii(127)   → 1
ft_isascii(128)   → 0
ft_isascii(-1)    → 0
ft_isascii('A')   → 1
```

---

## 4.5 ft_isprint

### Prototype and Purpose

```c
int ft_isprint(int c);
```

Returns non-zero if `c` is a printable character (ASCII 32–126, inclusive), zero otherwise.

**Printable** means characters you can see on screen. The space character (32) counts. The DEL character (127) does not.

### Implementation

```c
#include "libft.h"

int ft_isprint(int c)
{
    return (c >= 32 && c <= 126);
}
```

**Line by line:**

`return (c >= 32 && c <= 126);`
- 32 = space, 126 = `~`
- Characters 0–31 are control characters (newline, tab, etc.) — not printable
- 127 = DEL — not printable

### ASCII Printable Range Reference

```
32  = ' ' (space)
33  = '!'
...
48  = '0' ... 57 = '9'
...
65  = 'A' ... 90 = 'Z'
...
97  = 'a' ... 122 = 'z'
...
126 = '~'
127 = DEL (not printable)
```

### Test Cases

```c
ft_isprint(' ')   → 1
ft_isprint('~')   → 1
ft_isprint('\n')  → 0  (10, newline)
ft_isprint('\t')  → 0  (9, tab)
ft_isprint(127)   → 0
ft_isprint(0)     → 0
```

---

## 4.6 ft_strlen

### Prototype and Purpose

```c
size_t ft_strlen(const char *s);
```

Returns the number of characters in the string `s`, NOT including the null terminator.

### Implementation

```c
#include "libft.h"

size_t  ft_strlen(const char *s)
{
    size_t  len;

    len = 0;
    while (s[len])
        len++;
    return (len);
}
```

**Line by line:**

`size_t len;`
- We use `size_t` because a string can theoretically be longer than `INT_MAX`.

`len = 0;`
- Start counting from 0.

`while (s[len])`
- `s[len]` reads the character at position `len`.
- If it's non-zero (not the null terminator), the condition is true.
- Once we hit `'\0'` (value 0), the loop stops.

`len++;`
- Count this character and move forward.

`return (len);`
- Return the count. Does NOT include the `'\0'` itself.

### Diagram

```
s = "Hello"

s[0]='H'  s[1]='e'  s[2]='l'  s[3]='l'  s[4]='o'  s[5]='\0'

Iteration:
len=0: s[0]='H' → non-zero → len++  → len=1
len=1: s[1]='e' → non-zero → len++  → len=2
len=2: s[2]='l' → non-zero → len++  → len=3
len=3: s[3]='l' → non-zero → len++  → len=4
len=4: s[4]='o' → non-zero → len++  → len=5
len=5: s[5]='\0' → zero   → STOP

return 5
```

### Edge Cases

```c
ft_strlen("")     → 0   // empty string — first char is '\0'
ft_strlen("a")    → 1
ft_strlen("\0")   → 0   // same as empty
```

> **Warning:** Never pass `NULL` to `ft_strlen`. The man page for `strlen` has undefined behavior for `NULL` input. You do not need to handle it unless your evaluator asks.

### Test Cases

```c
ft_strlen("Hello")       → 5
ft_strlen("")            → 0
ft_strlen("42 Warsaw")   → 9
ft_strlen("\n")          → 1  // newline is one character
```

---

## 4.7 ft_memset

### Prototype and Purpose

```c
void *ft_memset(void *b, int c, size_t len);
```

Fills the first `len` bytes of memory area `b` with the byte value `c`. Returns `b`.

**Why `void *`?** Because `memset` works on any type of memory — chars, ints, structs, anything. `void *` is a generic pointer that can point to anything.

### Implementation

```c
#include "libft.h"

void    *ft_memset(void *b, int c, size_t len)
{
    unsigned char   *ptr;

    ptr = (unsigned char *)b;
    while (len--)
        *ptr++ = (unsigned char)c;
    return (b);
}
```

**Line by line:**

`unsigned char *ptr;`
- We cast `void *` to `unsigned char *` because you cannot do arithmetic on `void *`.
- We use `unsigned char` (not `char`) to avoid sign issues when `c` > 127.

`ptr = (unsigned char *)b;`
- Cast the generic pointer to a typed pointer so we can work with it byte by byte.

`while (len--)`
- `len--` returns the current value of `len`, then decrements it.
- So if `len = 5`, the loop runs for values 5, 4, 3, 2, 1 (5 iterations).
- When `len` becomes 0, the expression evaluates to 0 (false) and the loop stops.

`*ptr++ = (unsigned char)c;`
- Write the byte `c` at the current position.
- Then advance `ptr` to the next byte.
- `(unsigned char)c` ensures we only use the low 8 bits of `c`.

`return (b);`
- Return the original pointer (not `ptr`, which has moved).

### Diagram

```
b → [ ?? ][ ?? ][ ?? ][ ?? ][ ?? ]
     ptr
       ↓
Fill with 'A' (65), len=5:

Step 1: *ptr = 65, ptr++  → [ 65 ][ ?? ][ ?? ][ ?? ][ ?? ]
Step 2: *ptr = 65, ptr++  → [ 65 ][ 65 ][ ?? ][ ?? ][ ?? ]
Step 3: *ptr = 65, ptr++  → [ 65 ][ 65 ][ 65 ][ ?? ][ ?? ]
Step 4: *ptr = 65, ptr++  → [ 65 ][ 65 ][ 65 ][ 65 ][ ?? ]
Step 5: *ptr = 65, ptr++  → [ 65 ][ 65 ][ 65 ][ 65 ][ 65 ]

return b (original pointer)
```

### Test Cases

```c
char buf[5];
ft_memset(buf, 0, 5);    // buf = {0, 0, 0, 0, 0}
ft_memset(buf, 'A', 5);  // buf = {'A','A','A','A','A'}
ft_memset(buf, 255, 3);  // buf = {255,255,255,'A','A'}
ft_memset(buf, 0, 0);    // buf unchanged (0 bytes to fill)
```

### Common Mistakes

- Casting to `char *` instead of `unsigned char *` (signed overflow issues)
- Not returning the original `b`
- Using `len > 0` instead of `len--` (works but is less idiomatic)

---

## 4.8 ft_bzero

### Prototype and Purpose

```c
void ft_bzero(void *s, size_t n);
```

Sets the first `n` bytes of `s` to zero. Does not return anything. This is essentially `ft_memset(s, 0, n)` with no return value.

**Why does this exist?** It is a BSD-derived function. POSIX deprecated it in favor of `memset`, but many codebases still use it.

### Implementation

```c
#include "libft.h"

void    ft_bzero(void *s, size_t n)
{
    ft_memset(s, 0, n);
}
```

Or, if you want to implement it without calling `ft_memset`:

```c
#include "libft.h"

void    ft_bzero(void *s, size_t n)
{
    unsigned char   *ptr;

    ptr = (unsigned char *)s;
    while (n--)
        *ptr++ = 0;
}
```

**Line by line** (standalone version):

`unsigned char *ptr;`
- Work byte-by-byte, need a typed pointer.

`ptr = (unsigned char *)s;`
- Cast `void *` to `unsigned char *`.

`while (n--)`
- Same countdown loop as `ft_memset`.

`*ptr++ = 0;`
- Write zero, advance pointer.

### Test Cases

```c
char buf[5] = {'A', 'B', 'C', 'D', 'E'};
ft_bzero(buf, 3);
// buf = {0, 0, 0, 'D', 'E'}

ft_bzero(buf, 0);
// buf unchanged

ft_bzero(buf, 5);
// buf = {0, 0, 0, 0, 0}
```

---

## 4.9 ft_memcpy

### Prototype and Purpose

```c
void *ft_memcpy(void *dst, const void *src, size_t n);
```

Copies `n` bytes from `src` to `dst`. Returns `dst`.

**Important restriction:** The behavior is **undefined** if `dst` and `src` overlap. For overlapping regions, use `ft_memmove`.

### Implementation

```c
#include "libft.h"

void    *ft_memcpy(void *dst, const void *src, size_t n)
{
    unsigned char       *d;
    const unsigned char *s;

    if (!dst && !src)
        return (dst);
    d = (unsigned char *)dst;
    s = (const unsigned char *)src;
    while (n--)
        *d++ = *s++;
    return (dst);
}
```

**Line by line:**

`if (!dst && !src)`
- If BOTH are NULL, return early. This guards against the specific edge case where both are NULL.
- Note: if only one is NULL, we proceed — the original memcpy has undefined behavior here anyway.

`d = (unsigned char *)dst;`
`s = (const unsigned char *)src;`
- Typed pointers for byte-by-byte access. `src` gets `const` because we don't modify it.

`while (n--)`
- Copy `n` bytes.

`*d++ = *s++;`
- Read one byte from `src`, write it to `dst`, advance both pointers.

`return (dst);`
- Return the original destination.

### Diagram

```
src: [ H ][ e ][ l ][ l ][ o ][ \0 ]
      ↓    ↓    ↓    ↓    ↓
dst: [ H ][ e ][ l ][ l ][ o ]       (n=5)
```

### Test Cases

```c
char src[] = "Hello";
char dst[10];

ft_memcpy(dst, src, 5);
// dst[0..4] = "Hello" (no null terminator)

ft_memcpy(dst, src, 6);
// dst[0..5] = "Hello\0" (with null terminator)

ft_memcpy(dst, src, 0);
// dst unchanged
```

### Common Mistakes

- Forgetting to add `+1` to include the null terminator when copying a full string
- Using this on overlapping memory (use `memmove` instead)
- Not returning `dst`

---

## 4.10 ft_memmove

### Prototype and Purpose

```c
void *ft_memmove(void *dst, const void *src, size_t len);
```

Copies `len` bytes from `src` to `dst`, handling overlapping memory correctly. Returns `dst`.

**Why does overlap matter?**

If `dst` and `src` overlap and `dst` starts after `src`, copying forward will overwrite source bytes before they are read.

```
Overlap scenario:
src:        [ A ][ B ][ C ][ D ][ E ]
            100  101  102  103  104

dst starts at 102:
            [ A ][ B ][ C ][ D ][ E ]
                        100  101  102  ... (dst = src + 2)

Copying forward: src[0]→dst[0], src[1]→dst[1]...
After copying src[0] to dst[0]:
            [ A ][ B ][ A ][ D ][ E ]  ← src[2] is now corrupted!
```

The fix: if `dst > src` (and they overlap), copy **backward** — from the end of the buffer toward the front.

### Implementation

```c
#include "libft.h"

void    *ft_memmove(void *dst, const void *src, size_t len)
{
    unsigned char       *d;
    const unsigned char *s;

    if (!dst && !src)
        return (dst);
    d = (unsigned char *)dst;
    s = (const unsigned char *)src;
    if (d > s)
    {
        d += len - 1;
        s += len - 1;
        while (len--)
            *d-- = *s--;
    }
    else
    {
        while (len--)
            *d++ = *s++;
    }
    return (dst);
}
```

**Line by line:**

`if (d > s)`
- If the destination starts after the source in memory, we must copy backward.

`d += len - 1;`
`s += len - 1;`
- Move both pointers to point at the LAST byte we need to copy.

`while (len--)`
`    *d-- = *s--;`
- Copy backward: read the last byte, write it, move both pointers backward.

`else { while (len--) *d++ = *s++; }`
- No overlap issue: copy forward as in `memcpy`.

### Overlap Diagram

```
src = "ABCDE" starting at address 100
dst starts at address 102 (overlaps with src)

Memory: [ A ][ B ][ C ][ D ][ E ]
         100  101  102  103  104

Copy backward (len=5):
Step 1: d=106, s=104 → *d=*s → E
Step 2: d=105, s=103 → *d=*s → D
Step 3: d=104, s=102 → *d=*s → C
Step 4: d=103, s=101 → *d=*s → B
Step 5: d=102, s=100 → *d=*s → A

Result: [ A ][ B ][ A ][ B ][ C ][ D ][ E ]
                   ^ dst filled correctly
```

### Test Cases

```c
// Non-overlapping (same as memcpy)
char src[] = "Hello";
char dst[10];
ft_memmove(dst, src, 6);
// dst = "Hello\0"

// Overlapping (dst is inside src)
char buf[] = "memmove can be tricky";
ft_memmove(buf + 2, buf, 10);
// First 10 chars of buf copied to buf+2
```

---

## 4.11 ft_strlcpy

### Prototype and Purpose

```c
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);
```

Copies up to `dstsize - 1` characters from `src` to `dst`, **always** null-terminating the result (if `dstsize > 0`). Returns the **total length of `src`** (not the number of bytes copied).

**Why return `strlen(src)` instead of what was copied?** So the caller can detect truncation: if the return value ≥ `dstsize`, the copy was truncated.

### Implementation

```c
#include "libft.h"

size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t  src_len;
    size_t  i;

    src_len = ft_strlen(src);
    if (dstsize == 0)
        return (src_len);
    i = 0;
    while (i < dstsize - 1 && src[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (src_len);
}
```

**Line by line:**

`src_len = ft_strlen(src);`
- Measure source length now — we return this regardless.

`if (dstsize == 0)`
`    return (src_len);`
- Special case: if `dstsize` is 0, we cannot write anything (not even a null terminator). Just return source length.

`while (i < dstsize - 1 && src[i])`
- Copy at most `dstsize - 1` characters (leaving room for `'\0'`).
- Stop at end of `src` or when the buffer is full.

`dst[i] = '\0';`
- ALWAYS null-terminate the destination (if `dstsize > 0`).

`return (src_len);`
- Return total length of `src`, not `i`.

### Why `dstsize - 1` Is Safe

You might worry: what if `dstsize` is 0 and we compute `dstsize - 1`? Since `dstsize` is `size_t` (unsigned), `0 - 1` would wrap around to a huge number. That is why we have the `if (dstsize == 0) return (src_len);` guard before using `dstsize - 1`.

### Test Cases

```c
char dst[10];
ft_strlcpy(dst, "Hello", 10);
// dst = "Hello", return = 5

ft_strlcpy(dst, "Hello", 3);
// dst = "He\0", return = 5 (truncation: 5 >= 3)

ft_strlcpy(dst, "Hi", 0);
// dst unchanged, return = 2

ft_strlcpy(dst, "", 10);
// dst = "\0", return = 0
```

---

## 4.12 ft_strlcat

### Prototype and Purpose

```c
size_t ft_strlcat(char *dst, const char *src, size_t dstsize);
```

Appends `src` to the end of `dst`, writing at most `dstsize - strlen(dst) - 1` bytes of `src`. Always null-terminates (if `dstsize > strlen(dst)`). Returns `strlen(dst) + strlen(src)` — the total length the concatenated string would be if the buffer were big enough.

This is the trickiest function in Part 1. Read slowly.

### Implementation

```c
#include "libft.h"

size_t  ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t  dst_len;
    size_t  src_len;
    size_t  i;

    dst_len = ft_strlen(dst);
    src_len = ft_strlen(src);
    if (dstsize <= dst_len)
        return (dstsize + src_len);
    i = 0;
    while (src[i] && (dst_len + i) < dstsize - 1)
    {
        dst[dst_len + i] = src[i];
        i++;
    }
    dst[dst_len + i] = '\0';
    return (dst_len + src_len);
}
```

**Line by line:**

`dst_len = ft_strlen(dst);`
`src_len = ft_strlen(src);`
- Measure both strings first.

`if (dstsize <= dst_len)`
`    return (dstsize + src_len);`
- If the buffer is already full (or `dstsize` is 0), we cannot append. Return `dstsize + src_len` as defined by the man page.
- Why `dstsize + src_len`? Because the buffer was already too full to work with — the return value signals this.

`while (src[i] && (dst_len + i) < dstsize - 1)`
- Append characters of `src` starting at position `dst_len` in `dst`.
- Stop when we've reached `dstsize - 1` (leaving room for null terminator).

`dst[dst_len + i] = '\0';`
- Null-terminate the result.

`return (dst_len + src_len);`
- Return the total intended length.

### Diagram

```
Before:
dst:  [ H ][ e ][ l ][ l ][ o ][ \0 ][ ? ][ ? ][ ? ][ ? ]
       0    1    2    3    4    5    6    7    8    9
dstsize = 10, dst_len = 5

src = " World" (src_len = 6)

Appending:
dst[5] = ' '
dst[6] = 'W'
dst[7] = 'o'
dst[8] = 'r'
dst[9] = '\0'  ← stop at dstsize - 1 = 9

After:
dst: "Hello Wor\0"
return: 5 + 6 = 11 (the full concat would be 11 chars)
11 >= 10 → truncation occurred
```

### Test Cases

```c
char dst[15] = "Hello";
ft_strlcat(dst, " World", 15);
// dst = "Hello World", return = 11

char dst2[8] = "Hello";
ft_strlcat(dst2, " World", 8);
// dst2 = "Hello W\0" (truncated), return = 11

char dst3[3] = "Hi";
ft_strlcat(dst3, "!!!!", 2);
// dstsize(2) <= dst_len(2), return = 2 + 4 = 6, dst unchanged
```

### Common Mistakes

- Getting the return value wrong when `dstsize <= dst_len`
- Off-by-one in the loop condition (forgetting the `-1`)
- Not understanding that the return is `dst_len + src_len`, not how many bytes were copied

---

## 4.13 ft_toupper

### Prototype and Purpose

```c
int ft_toupper(int c);
```

If `c` is a lowercase letter, converts it to uppercase. Otherwise returns `c` unchanged.

### Implementation

```c
#include "libft.h"

int ft_toupper(int c)
{
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}
```

**Line by line:**

`if (c >= 'a' && c <= 'z')`
- Check if it is lowercase.

`return (c - 32);`
- In ASCII, the difference between a lowercase letter and its uppercase version is exactly 32. `'a'` = 97, `'A'` = 65. `97 - 32 = 65`. This works for every letter a–z.

`return (c);`
- Not lowercase — return unchanged.

### ASCII Trick Explained

```
Lowercase:  a=97   b=98   c=99  ... z=122
Uppercase:  A=65   B=66   C=67  ... Z=90

Difference: 97-65 = 32 for every pair
```

### Test Cases

```c
ft_toupper('a')   → 'A' (65)
ft_toupper('z')   → 'Z' (90)
ft_toupper('A')   → 'A' (unchanged)
ft_toupper('5')   → '5' (unchanged)
ft_toupper(' ')   → ' ' (unchanged)
```

---

## 4.14 ft_tolower

### Prototype and Purpose

```c
int ft_tolower(int c);
```

If `c` is an uppercase letter, converts it to lowercase. Otherwise returns `c` unchanged.

### Implementation

```c
#include "libft.h"

int ft_tolower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return (c + 32);
    return (c);
}
```

**Line by line:**

`if (c >= 'A' && c <= 'Z')`
- Check uppercase range.

`return (c + 32);`
- Add 32 to convert uppercase → lowercase. Same trick as `toupper`, but adding instead of subtracting.

### Test Cases

```c
ft_tolower('A')   → 'a'
ft_tolower('Z')   → 'z'
ft_tolower('a')   → 'a' (unchanged)
ft_tolower('5')   → '5' (unchanged)
```

---

## 4.15 ft_strchr

### Prototype and Purpose

```c
char *ft_strchr(const char *s, int c);
```

Returns a pointer to the first occurrence of character `c` in string `s`. Returns `NULL` if `c` is not found. The null terminator is considered part of the string — searching for `'\0'` returns a pointer to the null terminator.

### Implementation

```c
#include "libft.h"

char    *ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    if ((char)c == '\0')
        return ((char *)s);
    return (NULL);
}
```

**Line by line:**

`while (*s)`
- Traverse the string until we hit the null terminator.

`if (*s == (char)c)`
- Compare current character to `c`. We cast `c` to `char` because it is passed as `int`.

`return ((char *)s);`
- Found it. Return a pointer to this position.
- We cast away `const` because the original `strchr` returns a non-const pointer. This is valid here.

`s++;`
- Move to next character.

`if ((char)c == '\0')`
`    return ((char *)s);`
- After the loop, `s` points to `'\0'`. If we were searching for `'\0'`, return this pointer.

`return (NULL);`
- Character not found in the string.

### Diagram

```
s = "Hello"  c = 'l'

s[0]='H' → 'H'!='l'  → continue
s[1]='e' → 'e'!='l'  → continue
s[2]='l' → 'l'=='l'  → return &s[2]

Result: pointer to 'l' in "Hello"
```

### Test Cases

```c
char *s = "Hello World";
ft_strchr(s, 'l')   → pointer to s[2] ("llo World")
ft_strchr(s, 'W')   → pointer to s[6] ("World")
ft_strchr(s, 'z')   → NULL
ft_strchr(s, '\0')  → pointer to s[11] (the null terminator)
ft_strchr(s, 'H')   → pointer to s[0] ("Hello World")
```

---

## 4.16 ft_strrchr

### Prototype and Purpose

```c
char *ft_strrchr(const char *s, int c);
```

Like `ft_strchr`, but returns a pointer to the **last** occurrence of `c` in `s`. Returns `NULL` if not found.

### Implementation

```c
#include "libft.h"

char    *ft_strrchr(const char *s, int c)
{
    const char  *last;

    last = NULL;
    while (*s)
    {
        if (*s == (char)c)
            last = s;
        s++;
    }
    if ((char)c == '\0')
        return ((char *)s);
    return ((char *)last);
}
```

**Line by line:**

`last = NULL;`
- Track the most recent occurrence of `c`. Start with NULL (not found yet).

`while (*s)`
- Traverse the full string (do not stop at first match).

`if (*s == (char)c)`
`    last = s;`
- Every time we see `c`, update `last`. At the end, `last` will point to the final occurrence.

`if ((char)c == '\0')`
`    return ((char *)s);`
- Same as `strchr` — handle the null terminator case.

`return ((char *)last);`
- Return the last recorded position (or NULL if never found).

### Diagram

```
s = "Hello"  c = 'l'

Pass 1: s[0]='H' → no match
Pass 2: s[1]='e' → no match
Pass 3: s[2]='l' → match! last = &s[2]
Pass 4: s[3]='l' → match! last = &s[3]  (overwrite)
Pass 5: s[4]='o' → no match
Loop ends.

return last = &s[3] → pointer to second 'l'
```

### Test Cases

```c
char *s = "Hello";
ft_strrchr(s, 'l')   → pointer to s[3]
ft_strrchr(s, 'H')   → pointer to s[0]  (only one 'H')
ft_strrchr(s, 'z')   → NULL
ft_strrchr(s, '\0')  → pointer to s[5]  (null terminator)
```

---

## 4.17 ft_strncmp

### Prototype and Purpose

```c
int ft_strncmp(const char *s1, const char *s2, size_t n);
```

Compares at most `n` characters of strings `s1` and `s2`. Returns:
- `< 0` if `s1` comes before `s2`
- `0` if equal (up to `n` characters)
- `> 0` if `s1` comes after `s2`

Comparison is done on **unsigned** character values.

### Implementation

```c
#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t  i;

    if (n == 0)
        return (0);
    i = 0;
    while (i < n - 1 && s1[i] && s1[i] == s2[i])
        i++;
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
```

**Line by line:**

`if (n == 0)`
`    return (0);`
- If we compare 0 characters, they are equal by definition.

`while (i < n - 1 && s1[i] && s2[i] == s1[i])`

Wait — let me think about this more carefully. The condition needs to:
1. Not go past `n` characters
2. Stop if either string ends
3. Stop if characters differ

`while (i < n - 1 && s1[i] && s1[i] == s2[i])`
- `i < n - 1`: stay within n-character limit (we check the last pair in the return)
- `s1[i]`: stop at null terminator of s1
- `s1[i] == s2[i]`: keep going only while they match
- Note: we don't check `s2[i]` in the while because the subtraction in return handles it

`return ((unsigned char)s1[i] - (unsigned char)s2[i]);`
- Cast to `unsigned char` before subtracting — this matches the C standard's requirement that comparison be on unsigned values.
- If characters are equal at position `i`, this returns 0.
- If `s1[i] > s2[i]`, positive; if `s1[i] < s2[i]`, negative.

### Test Cases

```c
ft_strncmp("Hello", "Hello", 5)   → 0
ft_strncmp("Hello", "Hello", 3)   → 0
ft_strncmp("Hello", "World", 5)   → negative ('H' < 'W')
ft_strncmp("Hello", "Hello!", 5)  → 0 (only 5 chars compared)
ft_strncmp("Hello", "Hello!", 6)  → negative ('\0' < '!')
ft_strncmp("abc", "abd", 3)       → negative ('c' < 'd')
ft_strncmp("", "", 5)             → 0
```

### Common Mistakes

- Not casting to `unsigned char` before subtracting (gives wrong results for chars > 127)
- Off-by-one in the loop (compare n chars, not n-1)
- Not handling `n == 0` (if `n` is `size_t` and you compute `n - 1`, you get wraparound)

---

## 4.18 ft_memchr

### Prototype and Purpose

```c
void *ft_memchr(const void *s, int c, size_t n);
```

Scans the first `n` bytes of memory area `s` for the byte value `c`. Returns a pointer to the first match, or `NULL` if not found. Unlike `strchr`, this does NOT stop at null bytes — it scans exactly `n` bytes.

### Implementation

```c
#include "libft.h"

void    *ft_memchr(const void *s, int c, size_t n)
{
    const unsigned char *ptr;

    ptr = (const unsigned char *)s;
    while (n--)
    {
        if (*ptr == (unsigned char)c)
            return ((void *)ptr);
        ptr++;
    }
    return (NULL);
}
```

**Line by line:**

`const unsigned char *ptr;`
- Work byte-by-byte with `unsigned char` to avoid sign issues.

`ptr = (const unsigned char *)s;`
- Cast the generic `void *` to a typed pointer.

`while (n--)`
- Scan exactly `n` bytes.

`if (*ptr == (unsigned char)c)`
- Cast `c` to `unsigned char` for correct comparison (the man page says the byte value of `c`).

`return ((void *)ptr);`
- Found — return the location.

`ptr++;`
`return (NULL);`
- Not found in `n` bytes.

### Test Cases

```c
char data[] = {0, 1, 2, 3, 4, 5};
ft_memchr(data, 3, 6)   → pointer to data[3]
ft_memchr(data, 0, 6)   → pointer to data[0]
ft_memchr(data, 9, 6)   → NULL (9 not in array)
ft_memchr(data, 3, 3)   → NULL (only scanning first 3 bytes)

// Unlike strchr, memchr continues past null bytes:
char s[] = {'\0', 'A', '\0'};
ft_memchr(s, 'A', 3)    → pointer to s[1]
```

---

## 4.19 ft_memcmp

### Prototype and Purpose

```c
int ft_memcmp(const void *s1, const void *s2, size_t n);
```

Compares the first `n` bytes of two memory areas. Returns the difference of the first differing pair of bytes, as `unsigned char`. Returns 0 if they are identical.

### Implementation

```c
#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *a;
    const unsigned char *b;

    a = (const unsigned char *)s1;
    b = (const unsigned char *)s2;
    while (n--)
    {
        if (*a != *b)
            return (*a - *b);
        a++;
        b++;
    }
    return (0);
}
```

**Line by line:**

`a = (const unsigned char *)s1;`
`b = (const unsigned char *)s2;`
- Cast both to `unsigned char *` for byte comparison.

`while (n--)`
- Compare exactly `n` bytes.

`if (*a != *b)`
`    return (*a - *b);`
- First difference found: return the difference. Since these are `unsigned char`, the subtraction is safe (values 0–255).

`a++; b++;`
- Advance both pointers.

`return (0);`
- All `n` bytes were identical.

> **Note:** Unlike `strncmp`, `memcmp` does NOT stop at null bytes. It compares exactly `n` bytes.

### Test Cases

```c
ft_memcmp("Hello", "Hello", 5)   → 0
ft_memcmp("Hello", "World", 5)   → negative
ft_memcmp("abcd", "abce", 3)     → 0 (only first 3 compared)
ft_memcmp("abcd", "abce", 4)     → negative ('d' < 'e')
ft_memcmp("a\0b", "a\0c", 3)     → negative (compares past null)
```

---

## 4.20 ft_strnstr

### Prototype and Purpose

```c
char *ft_strnstr(const char *haystack, const char *needle, size_t len);
```

Finds the first occurrence of `needle` within the first `len` characters of `haystack`. Returns a pointer to the start of the match, or `NULL` if not found. Returns `haystack` if `needle` is empty.

This is a BSD-specific function — it does not exist on all systems.

### Implementation

```c
#include "libft.h"

char    *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t  needle_len;
    size_t  i;

    needle_len = ft_strlen(needle);
    if (needle_len == 0)
        return ((char *)haystack);
    i = 0;
    while (haystack[i] && i + needle_len <= len)
    {
        if (ft_memcmp(haystack + i, needle, needle_len) == 0)
            return ((char *)(haystack + i));
        i++;
    }
    return (NULL);
}
```

**Line by line:**

`needle_len = ft_strlen(needle);`
- Measure needle once, outside the loop (efficiency).

`if (needle_len == 0)`
`    return ((char *)haystack);`
- Empty needle always matches at position 0. This is the defined behavior.

`while (haystack[i] && i + needle_len <= len)`
- Two conditions:
  1. `haystack[i]`: don't go past null terminator
  2. `i + needle_len <= len`: the needle must fully fit within `len` characters. If `needle_len` is 3 and `i` is 8, we need positions 8,9,10 — which is `i + needle_len = 11` positions total.

`if (ft_memcmp(haystack + i, needle, needle_len) == 0)`
- Compare `needle_len` bytes starting at position `i` in `haystack` against the needle.

`return ((char *)(haystack + i));`
- Match found — return pointer to start of match.

### Diagram

```
haystack = "hello world"
needle   = "world"
len      = 11

i=0: haystack+0 = "hello world", compare "hello" vs "world" → no
i=1: haystack+1 = "ello world",  compare "ello " vs "world" → no
...
i=6: haystack+6 = "world",       compare "world" vs "world" → YES!

return &haystack[6]
```

### Test Cases

```c
ft_strnstr("hello world", "world", 11) → pointer to "world"
ft_strnstr("hello world", "world", 5)  → NULL (world starts at index 6, needs 5 chars but len=5)
ft_strnstr("hello world", "", 11)      → pointer to "hello world"
ft_strnstr("hello", "hello world", 5)  → NULL (needle longer than haystack)
ft_strnstr("aabaa", "aa", 4)           → pointer to first "aa"
```

---

## 4.21 ft_atoi

### Prototype and Purpose

```c
int ft_atoi(const char *str);
```

Converts the initial portion of `str` to an `int`. Skips leading whitespace. Handles an optional `+` or `-` sign. Stops at the first non-digit character after the number.

**This function does NOT detect overflow.** The real `atoi` also doesn't — it has undefined behavior on overflow. You match this.

### Implementation

```c
#include "libft.h"

int ft_atoi(const char *str)
{
    int result;
    int sign;

    result = 0;
    sign = 1;
    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (ft_isdigit(*str))
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    return (result * sign);
}
```

**Line by line:**

`result = 0; sign = 1;`
- Initialize accumulator and sign.

`while (*str == ' ' || (*str >= 9 && *str <= 13))`
`    str++;`
- Skip whitespace. ASCII 9–13 covers `\t`, `\n`, `\v`, `\f`, `\r`.

`if (*str == '-' || *str == '+')`
- Check for optional sign character.

`if (*str == '-') sign = -1;`
`str++;`
- Set sign to negative if `-`, then advance past the sign character.

`while (ft_isdigit(*str))`
`    result = result * 10 + (*str - '0');`
`    str++;`
- Accumulate digits: for "123", this computes `0*10+1=1`, `1*10+2=12`, `12*10+3=123`.
- `*str - '0'` converts a digit character to its integer value: `'5' - '0' = 53 - 48 = 5`.

`return (result * sign);`
- Apply the sign.

### Digit-to-Number Trick

```
'0' = 48 (ASCII)
'1' = 49
'5' = 53
'9' = 57

'5' - '0' = 53 - 48 = 5  ✓
'9' - '0' = 57 - 48 = 9  ✓
```

### Test Cases

```c
ft_atoi("42")          → 42
ft_atoi("-42")         → -42
ft_atoi("   42")       → 42  (leading spaces)
ft_atoi("+42")         → 42
ft_atoi("42abc")       → 42  (stops at 'a')
ft_atoi("abc42")       → 0   (no leading digits)
ft_atoi("")            → 0
ft_atoi("   -   42")   → 0   (space after minus → not a sign)
```

### Common Mistakes

- Forgetting the full whitespace range (only checking `' '` misses `\t`, `\n`, etc.)
- Not handling `+` sign
- Applying sign before checking for sign character
- Double-advancing past sign AND first digit

---

## 4.22 ft_calloc

### Prototype and Purpose

```c
void *ft_calloc(size_t count, size_t size);
```

Allocates memory for `count` elements of `size` bytes each. Unlike `malloc`, **initializes all bytes to zero**. Returns a pointer to the allocated memory, or `NULL` on failure.

### Implementation

```c
#include "libft.h"

void    *ft_calloc(size_t count, size_t size)
{
    void    *ptr;

    ptr = malloc(count * size);
    if (!ptr)
        return (NULL);
    ft_bzero(ptr, count * size);
    return (ptr);
}
```

**Line by line:**

`ptr = malloc(count * size);`
- Allocate the total number of bytes needed.

`if (!ptr)`
`    return (NULL);`
- If malloc fails, propagate failure.

`ft_bzero(ptr, count * size);`
- Zero out all bytes. This is the key difference from `malloc`.

`return (ptr);`
- Return the zeroed memory block.

> **Why calloc instead of malloc?** When you allocate an array or struct, uninitialized memory contains garbage values. `calloc` guarantees zeros, preventing subtle bugs from reading uninitialized memory.

### Overflow Protection

A production-quality `ft_calloc` should also check for integer overflow in `count * size`:

```c
if (count && size > SIZE_MAX / count)
    return (NULL);
```

Your evaluator may or may not check for this. Adding it shows extra care.

### Test Cases

```c
int *arr = ft_calloc(5, sizeof(int));
// arr = {0, 0, 0, 0, 0}
// Each element initialized to 0

char *s = ft_calloc(10, sizeof(char));
// s = "\0\0\0\0\0\0\0\0\0\0"
// Already null-terminated if used as string

void *p = ft_calloc(0, sizeof(int));
// Behavior is implementation-defined; returning NULL or a valid pointer both acceptable
```

---

## 4.23 ft_strdup

### Prototype and Purpose

```c
char *ft_strdup(const char *s1);
```

Allocates memory and copies the string `s1` into it, including the null terminator. Returns a pointer to the new string, or `NULL` if allocation fails. The caller must `free` the returned pointer.

### Implementation

```c
#include "libft.h"

char    *ft_strdup(const char *s1)
{
    size_t  len;
    char    *copy;

    len = ft_strlen(s1);
    copy = malloc(len + 1);
    if (!copy)
        return (NULL);
    ft_memcpy(copy, s1, len + 1);
    return (copy);
}
```

**Line by line:**

`len = ft_strlen(s1);`
- Measure the string. We need this to know how many bytes to allocate.

`copy = malloc(len + 1);`
- Allocate `len + 1` bytes: `len` for the characters, `+1` for the null terminator.

`if (!copy)`
`    return (NULL);`
- On allocation failure, return NULL.

`ft_memcpy(copy, s1, len + 1);`
- Copy `len + 1` bytes — this includes the null terminator.

`return (copy);`
- Return the new string. The caller must `free(copy)` when done.

### Memory Layout

```
s1: [ H ][ e ][ l ][ l ][ o ][ \0 ]   (lives wherever it was)

malloc(6):
copy: [ ? ][ ? ][ ? ][ ? ][ ? ][ ? ]  (6 bytes on heap)

After ft_memcpy:
copy: [ H ][ e ][ l ][ l ][ o ][ \0 ]  (new copy on heap)

Caller must: free(copy);
```

### Test Cases

```c
char *s = ft_strdup("Hello");
// s = "Hello" (new allocation)
// ft_strlen(s) == 5
// s[5] == '\0'
free(s);

char *empty = ft_strdup("");
// empty = "\0"
free(empty);

char *dup = ft_strdup("42 Warsaw");
// dup = "42 Warsaw"
free(dup);
```

---

### Chapter 4 Summary

| Function | Category | Returns | Allocates? |
|---|---|---|---|
| `ft_isalpha` | character check | non-zero or 0 | no |
| `ft_isdigit` | character check | non-zero or 0 | no |
| `ft_isalnum` | character check | non-zero or 0 | no |
| `ft_isascii` | character check | non-zero or 0 | no |
| `ft_isprint` | character check | non-zero or 0 | no |
| `ft_strlen` | string | `size_t` length | no |
| `ft_memset` | memory | `void *` to dst | no |
| `ft_bzero` | memory | void | no |
| `ft_memcpy` | memory | `void *` to dst | no |
| `ft_memmove` | memory | `void *` to dst | no |
| `ft_strlcpy` | string | `size_t` src_len | no |
| `ft_strlcat` | string | `size_t` total_len | no |
| `ft_toupper` | character convert | int | no |
| `ft_tolower` | character convert | int | no |
| `ft_strchr` | string search | `char *` or NULL | no |
| `ft_strrchr` | string search | `char *` or NULL | no |
| `ft_strncmp` | string compare | int | no |
| `ft_memchr` | memory search | `void *` or NULL | no |
| `ft_memcmp` | memory compare | int | no |
| `ft_strnstr` | string search | `char *` or NULL | no |
| `ft_atoi` | conversion | int | no |
| `ft_calloc` | allocation | `void *` or NULL | **YES** |
| `ft_strdup` | string | `char *` or NULL | **YES** |

### Chapter 4 Exercises

1. Implement `ft_strlen` without using array subscript notation (use pointer arithmetic only)
2. Write a test program that verifies your `ft_strlcat` matches `strlcat` on 10 different inputs
3. Trace through `ft_memmove` by hand for overlapping memory where `dst < src`
4. Explain why `ft_memcmp` casts to `unsigned char` before subtracting

---

# CHAPTER 5: Part 2 — The 11 Additional Functions

---

Part 2 functions are not in the standard library — they are utility functions that 42 designed specifically for your use. All the ones that return strings allocate memory with `malloc`. **The caller is always responsible for freeing.**

---

## 5.1 ft_substr

### Prototype and Purpose

```c
char *ft_substr(char const *s, unsigned int start, size_t len);
```

Allocates and returns a substring of `s`, starting at index `start`, of maximum length `len`. Returns `NULL` on allocation failure. Returns an empty string if `start >= ft_strlen(s)`.

### Design Approach

1. Handle NULL input
2. If `start` is past the end of `s`, return an empty string
3. Calculate how many characters are actually available from `start`
4. Allocate `min(len, available) + 1` bytes
5. Copy and null-terminate

### Implementation

```c
#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *sub;
    size_t  s_len;
    size_t  sub_len;

    if (!s)
        return (NULL);
    s_len = ft_strlen(s);
    if (start >= s_len)
        return (ft_strdup(""));
    sub_len = s_len - start;
    if (sub_len > len)
        sub_len = len;
    sub = malloc(sub_len + 1);
    if (!sub)
        return (NULL);
    ft_strlcpy(sub, s + start, sub_len + 1);
    return (sub);
}
```

**Line by line:**

`if (!s) return (NULL);`
- Guard against NULL input.

`s_len = ft_strlen(s);`
- Get total length of source string.

`if (start >= s_len)`
`    return (ft_strdup(""));`
- If `start` is at or beyond the end, the substring is empty. Return an allocated empty string (not NULL — that would signal an error).

`sub_len = s_len - start;`
- Maximum characters available from `start` to end.

`if (sub_len > len)`
`    sub_len = len;`
- If we have more available than requested, cap to `len`.

`sub = malloc(sub_len + 1);`
- Allocate space for the substring plus null terminator.

`ft_strlcpy(sub, s + start, sub_len + 1);`
- Copy from position `start` in `s`, at most `sub_len + 1` bytes (so `sub_len` chars + null terminator).

### Diagram

```
s = "Hello World"
     01234567890
start = 6, len = 5

s_len = 11
start(6) < s_len(11) → proceed
sub_len = 11 - 6 = 5
5 <= len(5) → sub_len stays 5

malloc(6)
strlcpy(sub, "World", 6)

Result: "World"
```

### Test Cases

```c
ft_substr("Hello World", 6, 5)  → "World"
ft_substr("Hello World", 0, 5)  → "Hello"
ft_substr("Hello World", 0, 20) → "Hello World"
ft_substr("Hello World", 20, 5) → ""
ft_substr("Hello World", 6, 0)  → ""
ft_substr("Hi", 1, 1)           → "i"
```

---

## 5.2 ft_strjoin

### Prototype and Purpose

```c
char *ft_strjoin(char const *s1, char const *s2);
```

Allocates and returns a new string that is the concatenation of `s1` and `s2`. Returns NULL on failure. The caller must free the result.

### Implementation

```c
#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *result;
    size_t  len1;
    size_t  len2;

    if (!s1 || !s2)
        return (NULL);
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    result = malloc(len1 + len2 + 1);
    if (!result)
        return (NULL);
    ft_strlcpy(result, s1, len1 + 1);
    ft_strlcat(result, s2, len1 + len2 + 1);
    return (result);
}
```

**Line by line:**

`if (!s1 || !s2) return (NULL);`
- Null check. Without this, `ft_strlen(NULL)` would crash.

`len1 = ft_strlen(s1); len2 = ft_strlen(s2);`
- Measure both strings.

`result = malloc(len1 + len2 + 1);`
- Allocate space for both strings plus the null terminator.

`ft_strlcpy(result, s1, len1 + 1);`
- Copy s1 into result. We pass `len1 + 1` so it copies all `len1` chars plus a null terminator.

`ft_strlcat(result, s2, len1 + len2 + 1);`
- Append s2. The total buffer size is `len1 + len2 + 1`.

### Alternative Implementation

```c
// Using memcpy directly — slightly more efficient:
ft_memcpy(result, s1, len1);
ft_memcpy(result + len1, s2, len2 + 1);  // +1 for null terminator of s2
```

### Test Cases

```c
ft_strjoin("Hello", " World")  → "Hello World"
ft_strjoin("", "abc")          → "abc"
ft_strjoin("abc", "")          → "abc"
ft_strjoin("", "")             → ""
ft_strjoin("42", " Warsaw")    → "42 Warsaw"
```

---

## 5.3 ft_strtrim

### Prototype and Purpose

```c
char *ft_strtrim(char const *s1, char const *set);
```

Allocates and returns a copy of `s1` with all characters from `set` removed from the beginning and end of the string. Returns NULL on failure.

**Note:** `set` is a set of characters to remove, not a substring. If `set = "abc"`, then any leading/trailing 'a', 'b', or 'c' are removed.

### Implementation

```c
#include "libft.h"

static int  in_set(char c, char const *set)
{
    while (*set)
    {
        if (c == *set)
            return (1);
        set++;
    }
    return (0);
}

char    *ft_strtrim(char const *s1, char const *set)
{
    size_t  start;
    size_t  end;

    if (!s1 || !set)
        return (NULL);
    start = 0;
    while (s1[start] && in_set(s1[start], set))
        start++;
    end = ft_strlen(s1);
    while (end > start && in_set(s1[end - 1], set))
        end--;
    return (ft_substr(s1, start, end - start));
}
```

**Line by line:**

`static int in_set(char c, char const *set)`
- Helper function: returns 1 if `c` is in `set`, 0 otherwise.
- `static` means it is only visible within this file (not exposed in the header).

`start = 0;`
`while (s1[start] && in_set(s1[start], set))`
`    start++;`
- Move `start` forward past any leading characters that are in `set`.

`end = ft_strlen(s1);`
`while (end > start && in_set(s1[end - 1], set))`
`    end--;`
- Move `end` backward past any trailing characters in `set`.
- We check `s1[end - 1]` because `end` is one past the last character.
- Guard `end > start` prevents underflow when the entire string is in `set`.

`return (ft_substr(s1, start, end - start));`
- Extract the middle part (what is left after trimming).

### Diagram

```
s1  = "   Hello World   "
set = " "

start: skip spaces at front
  s1[0]=' ' → in_set → start=1
  s1[1]=' ' → in_set → start=2
  s1[2]=' ' → in_set → start=3
  s1[3]='H' → NOT in_set → stop. start=3

end = 17 (ft_strlen)
  s1[16]=' ' → in_set → end=16
  s1[15]=' ' → in_set → end=15
  s1[14]=' ' → in_set → end=14
  s1[13]='d' → NOT in_set → stop. end=14

ft_substr(s1, 3, 14-3=11) → "Hello World"
```

### Test Cases

```c
ft_strtrim("  Hello  ", " ")       → "Hello"
ft_strtrim("xxHelloxx", "x")       → "Hello"
ft_strtrim("abcHelloabc", "abc")   → "Hello"  (removes any 'a','b','c')
ft_strtrim("  ", " ")              → ""
ft_strtrim("Hello", "")            → "Hello"  (empty set, nothing removed)
ft_strtrim("Hello", "xyz")         → "Hello"  (chars not present)
```

---

## 5.4 ft_split

### Prototype and Purpose

```c
char **ft_split(char const *s, char c);
```

Splits string `s` by delimiter character `c`. Returns a NULL-terminated array of strings (each substring). Returns NULL on failure.

This is the most complex function in Part 2. It requires careful memory management.

### Design Approach

1. Count how many words exist (to allocate the array)
2. Allocate the array of `char *` pointers
3. For each word, find its start and end, allocate a copy with `ft_substr`, store it

### Implementation

```c
#include "libft.h"

static size_t   count_words(char const *s, char c)
{
    size_t  count;
    int     in_word;

    count = 0;
    in_word = 0;
    while (*s)
    {
        if (*s != c && !in_word)
        {
            in_word = 1;
            count++;
        }
        else if (*s == c)
            in_word = 0;
        s++;
    }
    return (count);
}

static void free_all(char **arr, size_t i)
{
    while (i--)
        free(arr[i]);
    free(arr);
}

char    **ft_split(char const *s, char c)
{
    char    **result;
    size_t  word_count;
    size_t  i;
    size_t  start;

    if (!s)
        return (NULL);
    word_count = count_words(s, c);
    result = malloc((word_count + 1) * sizeof(char *));
    if (!result)
        return (NULL);
    i = 0;
    start = 0;
    while (i < word_count)
    {
        while (s[start] == c)
            start++;
        size_t  end = start;
        while (s[end] && s[end] != c)
            end++;
        result[i] = ft_substr(s, start, end - start);
        if (!result[i])
        {
            free_all(result, i);
            return (NULL);
        }
        start = end;
        i++;
    }
    result[i] = NULL;
    return (result);
}
```

**Step by step:**

**`count_words`:**
- Walk through the string tracking whether we are inside a word or not.
- When we transition from "not in word" to "in word", increment count.

**Main function:**

`word_count = count_words(s, c);`
- How many substrings will we produce?

`result = malloc((word_count + 1) * sizeof(char *));`
- Allocate an array of pointers. `+1` for the NULL terminator at the end.

`while (i < word_count)`
- For each word we need to extract:

`while (s[start] == c) start++;`
- Skip past delimiter characters to find the start of the word.

`end = start; while (s[end] && s[end] != c) end++;`
- Find the end of the word.

`result[i] = ft_substr(s, start, end - start);`
- Allocate a copy of this word.

`if (!result[i]) { free_all(result, i); return (NULL); }`
- If allocation fails mid-way, free everything allocated so far. No memory leaks.

`result[i] = NULL;`
- Null-terminate the array.

### Diagram

```
s = "Hello, World, 42"  c = ','

count_words: 3 words

result = malloc(4 * sizeof(char *))  [word0, word1, word2, NULL]

i=0: start=0 (skip no delimiters), end=5 (',' found)
     result[0] = ft_substr("Hello, World, 42", 0, 5) → "Hello"

i=1: start=5, skip ',' → start=6, skip ' '? → no (space is not delimiter)
     actually: start=6, s[6]=' ', s[6] != ',' → it's part of word 2
     end=12 (',' found)
     result[1] = ft_substr(..., 6, 6) → " World"

     (Note: space is kept because the delimiter is only ',')

i=2: start=12, skip ',' → start=13
     end=16 (end of string)
     result[2] = " 42"

result[3] = NULL
```

### Test Cases

```c
ft_split("Hello World 42", ' ')
// ["Hello", "World", "42", NULL]

ft_split("  Hello  World  ", ' ')
// ["Hello", "World", NULL]  (multiple delimiters collapsed)

ft_split("Hello", ',')
// ["Hello", NULL]  (no delimiter found)

ft_split("", ',')
// [NULL]  (0 words)

ft_split(",,,,", ',')
// [NULL]  (only delimiters, 0 words)

ft_split("a,b,c", ',')
// ["a", "b", "c", NULL]
```

### Common Mistakes

- Not NULL-terminating the result array
- Not freeing all substrings if one `ft_substr` fails
- Off-by-one in `count_words` (counting consecutive delimiters as words)
- Forgetting that `sizeof(char *)` ≠ `sizeof(char)` when allocating the array

---

## 5.5 ft_itoa

### Prototype and Purpose

```c
char *ft_itoa(int n);
```

Converts integer `n` to its decimal string representation. Handles negative numbers. Returns the string, or NULL on failure. The caller must free it.

**Hard case:** `INT_MIN` = −2,147,483,648. Its absolute value cannot be represented as a positive `int` (overflow). Handle this specially.

### Implementation

```c
#include "libft.h"

static int  count_digits(int n)
{
    int count;

    count = 0;
    if (n <= 0)
        count = 1;
    while (n)
    {
        n /= 10;
        count++;
    }
    return (count);
}

char    *ft_itoa(int n)
{
    int     len;
    char    *str;
    long    nb;

    nb = (long)n;
    len = count_digits(n);
    if (nb < 0)
        len++;
    str = malloc(len + 1);
    if (!str)
        return (NULL);
    str[len] = '\0';
    if (nb < 0)
    {
        str[0] = '-';
        nb = -nb;
    }
    if (nb == 0)
        str[0] = '0';
    while (nb > 0)
    {
        str[--len] = '0' + (nb % 10);
        nb /= 10;
    }
    return (str);
}
```

**Line by line:**

`nb = (long)n;`
- Cast to `long` IMMEDIATELY. If `n = INT_MIN`, doing `-n` on an `int` overflows. `long` can hold `INT_MIN * -1`.

`len = count_digits(n);`
- Count digits in the number (including the sign character space).

`if (nb < 0) len++;`
- Add one for the minus sign.

`str = malloc(len + 1);`
- Allocate space (digits + sign + null terminator).

`str[len] = '\0';`
- Null-terminate first (we fill from the right).

`if (nb < 0) { str[0] = '-'; nb = -nb; }`
- Write the minus sign, then make `nb` positive.

`while (nb > 0) { str[--len] = '0' + (nb % 10); nb /= 10; }`
- Fill from right to left using modulo:
  - `1234 % 10 = 4` → write '4' at position `--len`
  - `1234 / 10 = 123 % 10 = 3` → write '3'
  - `123 / 10 = 12 % 10 = 2` → write '2'
  - `12 / 10 = 1 % 10 = 1` → write '1'

### Diagram

```
n = -1234
nb = -1234 (long)
len = count_digits(-1234) = 4
len++ for '-' → len = 5
malloc(6): [?, ?, ?, ?, ?, \0]

nb < 0: str[0] = '-', nb = 1234

Loop:
  1234 % 10 = 4 → str[4] = '4', len=4, nb=123
  123  % 10 = 3 → str[3] = '3', len=3, nb=12
  12   % 10 = 2 → str[2] = '2', len=2, nb=1
  1    % 10 = 1 → str[1] = '1', len=1, nb=0

Result: ['-', '1', '2', '3', '4', '\0'] = "-1234"
```

### Test Cases

```c
ft_itoa(0)            → "0"
ft_itoa(42)           → "42"
ft_itoa(-42)          → "-42"
ft_itoa(2147483647)   → "2147483647"   (INT_MAX)
ft_itoa(-2147483648)  → "-2147483648"  (INT_MIN)
ft_itoa(1000)         → "1000"
```

---

## 5.6 ft_strmapi

### Prototype and Purpose

```c
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
```

Applies function `f` to each character of `s`, passing the index and character. Returns a new string of the results. Returns NULL on failure.

**What is `char (*f)(unsigned int, char)`?**
This is a function pointer. `f` is a pointer to a function that takes an `unsigned int` and a `char`, and returns a `char`. The caller passes this function; `ft_strmapi` calls it for each character.

### Implementation

```c
#include "libft.h"

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char            *result;
    unsigned int    i;

    if (!s || !f)
        return (NULL);
    result = malloc(ft_strlen(s) + 1);
    if (!result)
        return (NULL);
    i = 0;
    while (s[i])
    {
        result[i] = f(i, s[i]);
        i++;
    }
    result[i] = '\0';
    return (result);
}
```

**Line by line:**

`if (!s || !f) return (NULL);`
- Guard both inputs.

`result = malloc(ft_strlen(s) + 1);`
- New string has same length as `s`.

`result[i] = f(i, s[i]);`
- Call `f` with the index `i` and the character at that position. Store result.

`result[i] = '\0';`
- Null-terminate.

### Example Usage

```c
// Function to convert char to uppercase
char    to_upper_index(unsigned int i, char c)
{
    (void)i;  // We don't use the index here
    return (ft_toupper(c));
}

char *upper = ft_strmapi("hello", to_upper_index);
// upper = "HELLO"
free(upper);

// Function to alternate upper/lower by index
char    alternate_case(unsigned int i, char c)
{
    if (i % 2 == 0)
        return (ft_toupper(c));
    return (ft_tolower(c));
}

char *alt = ft_strmapi("hello", alternate_case);
// alt = "HeLlO"
free(alt);
```

### Test Cases

```c
ft_strmapi("hello", to_upper_index)   → "HELLO"
ft_strmapi("", to_upper_index)        → ""
ft_strmapi("abc", alternate_case)     → "AbC"
```

---

## 5.7 ft_striteri

### Prototype and Purpose

```c
void ft_striteri(char *s, void (*f)(unsigned int, char*));
```

Applies function `f` to each character of `s`, passing the index and a **pointer to the character** (so `f` can modify it in place). Unlike `ft_strmapi`, this modifies the string in-place and returns nothing.

**Why a pointer to char instead of char?** Because `f` receives `char *`, it can modify the character at that position directly. This allows in-place transformation without allocating a new string.

### Implementation

```c
#include "libft.h"

void    ft_striteri(char *s, void (*f)(unsigned int, char*))
{
    unsigned int    i;

    if (!s || !f)
        return ;
    i = 0;
    while (s[i])
    {
        f(i, &s[i]);
        i++;
    }
}
```

**Line by line:**

`if (!s || !f) return ;`
- Guard both inputs. No return value, so just return.

`f(i, &s[i]);`
- Pass index `i` and the ADDRESS of `s[i]` to `f`. `f` can do `*ptr = something` to change the character.

### Example Usage

```c
void    uppercase_in_place(unsigned int i, char *c)
{
    (void)i;
    *c = ft_toupper(*c);  // Dereference to change the actual character
}

char s[] = "hello";  // Must be mutable (not a string literal)
ft_striteri(s, uppercase_in_place);
// s = "HELLO"
```

---

## 5.8 ft_putchar_fd

### Prototype and Purpose

```c
void ft_putchar_fd(char c, int fd);
```

Writes character `c` to file descriptor `fd`.

**File descriptors:** In Unix, everything is a file. Standard streams have fixed file descriptor numbers:
- `0` = stdin (reading from keyboard)
- `1` = stdout (normal output)
- `2` = stderr (error output)

### Implementation

```c
#include "libft.h"

void    ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}
```

**Line by line:**

`write(fd, &c, 1);`
- `write(int fd, const void *buf, size_t count)` is a syscall.
- Write 1 byte (the address of `c`) to file descriptor `fd`.
- We pass `&c` (address of `c`) because `write` takes a buffer pointer.

### Test Cases

```c
ft_putchar_fd('H', 1);   // prints 'H' to stdout
ft_putchar_fd('E', 2);   // prints 'E' to stderr
ft_putchar_fd('\n', 1);  // prints newline to stdout
```

---

## 5.9 ft_putstr_fd

### Prototype and Purpose

```c
void ft_putstr_fd(char *s, int fd);
```

Writes string `s` to file descriptor `fd`.

### Implementation

```c
#include "libft.h"

void    ft_putstr_fd(char *s, int fd)
{
    if (!s)
        return ;
    write(fd, s, ft_strlen(s));
}
```

**Line by line:**

`if (!s) return ;`
- Guard against NULL. Writing NULL to fd would crash.

`write(fd, s, ft_strlen(s));`
- Write all characters of `s` (not including the null terminator) to `fd`.

---

## 5.10 ft_putendl_fd

### Prototype and Purpose

```c
void ft_putendl_fd(char *s, int fd);
```

Writes string `s` to file descriptor `fd`, followed by a newline character.

### Implementation

```c
#include "libft.h"

void    ft_putendl_fd(char *s, int fd)
{
    if (!s)
        return ;
    ft_putstr_fd(s, fd);
    ft_putchar_fd('\n', fd);
}
```

Simple: write the string, then write `'\n'`.

---

## 5.11 ft_putnbr_fd

### Prototype and Purpose

```c
void ft_putnbr_fd(int n, int fd);
```

Writes integer `n` (in decimal) to file descriptor `fd`. Handles `INT_MIN`.

### Implementation

```c
#include "libft.h"

void    ft_putnbr_fd(int n, int fd)
{
    long    nb;

    nb = (long)n;
    if (nb < 0)
    {
        ft_putchar_fd('-', fd);
        nb = -nb;
    }
    if (nb >= 10)
        ft_putnbr_fd((int)(nb / 10), fd);
    ft_putchar_fd('0' + (nb % 10), fd);
}
```

**Line by line:**

`nb = (long)n;`
- Cast to long immediately to safely handle `INT_MIN`.

`if (nb < 0) { ft_putchar_fd('-', fd); nb = -nb; }`
- Print minus sign and make positive.

`if (nb >= 10) ft_putnbr_fd((int)(nb / 10), fd);`
- Recursion: print all digits except the last one first.
- This naturally prints digits left-to-right.

`ft_putchar_fd('0' + (nb % 10), fd);`
- Print the last (rightmost) digit.

### Recursion Trace

```
ft_putnbr_fd(1234, 1):
  nb = 1234, positive
  1234 >= 10 → recurse with 123:
    ft_putnbr_fd(123, 1):
      123 >= 10 → recurse with 12:
        ft_putnbr_fd(12, 1):
          12 >= 10 → recurse with 1:
            ft_putnbr_fd(1, 1):
              1 < 10 → no recursion
              putchar('0' + 1) → '1'
          putchar('0' + 2) → '2'
      putchar('0' + 3) → '3'
  putchar('0' + 4) → '4'

Output: "1234"
```

---

### Chapter 5 Summary

| Function | Purpose | Allocates? |
|---|---|---|
| `ft_substr` | Extract substring | YES |
| `ft_strjoin` | Concatenate two strings | YES |
| `ft_strtrim` | Remove leading/trailing chars | YES |
| `ft_split` | Split by delimiter | YES (array + each string) |
| `ft_itoa` | Int to string | YES |
| `ft_strmapi` | Map function over string | YES |
| `ft_striteri` | In-place map over string | NO |
| `ft_putchar_fd` | Write char to fd | NO |
| `ft_putstr_fd` | Write string to fd | NO |
| `ft_putendl_fd` | Write string + newline to fd | NO |
| `ft_putnbr_fd` | Write integer to fd | NO |

### Chapter 5 Exercises

1. Use `ft_split` to split the string `"one:two:three:four"` on `':'`, then print each word
2. Use `ft_itoa` to convert `INT_MIN` to a string and verify the result
3. Write a function compatible with `ft_strmapi` that ROT13-encodes a string
4. Trace through `ft_putnbr_fd` for `n = -2147483648` (INT_MIN)

---

# CHAPTER 6: Part 3 — The 9 Bonus Linked-List Functions

---

## 6.1 Understanding the t_list Structure

Before any function, you need to deeply understand the structure:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

A **linked list** is a chain of nodes. Each node holds:
- `content`: a `void *` pointer to whatever data this node holds (string, int, struct, anything)
- `next`: a pointer to the next node in the chain, or NULL if this is the last

```
┌──────────────┐    ┌──────────────┐    ┌──────────────┐
│  content: *──┼─►  │  content: *──┼─►  │  content: *──┼─► "Charlie"
│  next:    *──┼─►  │  next:    *──┼─►  │  next:    ──►│ NULL
└──────────────┘    └──────────────┘    └──────────────┘
   "Alice"              "Bob"              "Charlie"
```

The list is accessed through a pointer to its first node (the **head**).

**Why `void *` for content?** A linked list is a general-purpose data structure. By using `void *`, a single list can hold strings, ints, structs — whatever you need. The caller manages what is stored.

---

## 6.2 ft_lstnew

### Prototype and Purpose

```c
t_list *ft_lstnew(void *content);
```

Allocates and returns a new node. Sets `content` to the given value. Sets `next` to NULL. Returns NULL on allocation failure.

### Implementation

```c
#include "libft.h"

t_list  *ft_lstnew(void *content)
{
    t_list  *node;

    node = malloc(sizeof(t_list));
    if (!node)
        return (NULL);
    node->content = content;
    node->next = NULL;
    return (node);
}
```

**Line by line:**

`node = malloc(sizeof(t_list));`
- Allocate memory for one node. `sizeof(t_list)` = size of the struct (typically 16 bytes on 64-bit systems: 8 bytes for `void *` + 8 bytes for the `next` pointer).

`node->content = content;`
- Store the content pointer. Note: we do NOT copy what `content` points to — we just store the pointer.

`node->next = NULL;`
- New nodes have no successor.

`return (node);`
- Return the allocated node.

### Test Cases

```c
t_list *node = ft_lstnew("Hello");
// node->content = "Hello"
// node->next = NULL

t_list *node2 = ft_lstnew(NULL);
// node2->content = NULL
// node2->next = NULL

int n = 42;
t_list *node3 = ft_lstnew(&n);
// node3->content = &n (pointer to n)
```

---

## 6.3 ft_lstadd_front

### Prototype and Purpose

```c
void ft_lstadd_front(t_list **lst, t_list *new);
```

Adds node `new` to the **beginning** of the list. The `lst` parameter is a pointer to the head pointer — this is how we modify the head itself.

### Why `t_list **lst`?

If we passed `t_list *lst`, we would receive a copy of the head pointer. Modifying it would not affect the caller's variable. By passing `t_list **lst` (pointer to the pointer), we can change what the caller's head pointer points to.

```
Before: head → [B] → [C] → NULL
After:  head → [A] → [B] → [C] → NULL
               ^ new node
```

### Implementation

```c
#include "libft.h"

void    ft_lstadd_front(t_list **lst, t_list *new)
{
    if (!lst || !new)
        return ;
    new->next = *lst;
    *lst = new;
}
```

**Line by line:**

`if (!lst || !new) return ;`
- Guard against NULL inputs.

`new->next = *lst;`
- The new node's `next` points to the current head. `*lst` is the current head.

`*lst = new;`
- The head is now the new node. `*lst` dereferences to update the caller's head pointer.

### Diagram

```
Before:
  lst = &head
  *lst (head) → [B] → [C] → NULL
  new → [A] → ???

Step 1: new->next = *lst
  new → [A] → [B] → [C] → NULL

Step 2: *lst = new
  *lst (head) → [A] → [B] → [C] → NULL

After:
  head → [A] → [B] → [C] → NULL
```

---

## 6.4 ft_lstsize

### Prototype and Purpose

```c
int ft_lstsize(t_list *lst);
```

Returns the number of nodes in the list. Returns 0 for NULL or empty list.

### Implementation

```c
#include "libft.h"

int ft_lstsize(t_list *lst)
{
    int count;

    count = 0;
    while (lst)
    {
        count++;
        lst = lst->next;
    }
    return (count);
}
```

**Line by line:**

`while (lst)`
- Keep going while the current node is not NULL.

`count++;`
- Count this node.

`lst = lst->next;`
- Move to the next node.

`return (count);`
- Total number of nodes.

### Traversal Pattern

This `while (lst) { do_something; lst = lst->next; }` pattern is the fundamental way to walk a linked list. You will use it in almost every linked-list function.

---

## 6.5 ft_lstlast

### Prototype and Purpose

```c
t_list *ft_lstlast(t_list *lst);
```

Returns a pointer to the last node of the list. Returns NULL if the list is empty.

### Implementation

```c
#include "libft.h"

t_list  *ft_lstlast(t_list *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next)
        lst = lst->next;
    return (lst);
}
```

**Line by line:**

`if (!lst) return (NULL);`
- Empty list → no last node.

`while (lst->next)`
`    lst = lst->next;`
- Keep going while the current node has a successor. Stop when `lst->next` is NULL.

`return (lst);`
- This is the last node.

### Diagram

```
List: [A] → [B] → [C] → NULL

Start: lst = [A]
  [A]->next = [B] (not NULL) → move: lst = [B]
  [B]->next = [C] (not NULL) → move: lst = [C]
  [C]->next = NULL            → stop

return [C]
```

---

## 6.6 ft_lstadd_back

### Prototype and Purpose

```c
void ft_lstadd_back(t_list **lst, t_list *new);
```

Adds node `new` to the **end** of the list. If the list is empty, the new node becomes the head.

### Implementation

```c
#include "libft.h"

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *last;

    if (!lst || !new)
        return ;
    if (!*lst)
    {
        *lst = new;
        return ;
    }
    last = ft_lstlast(*lst);
    last->next = new;
}
```

**Line by line:**

`if (!*lst) { *lst = new; return ; }`
- If the list is empty, the new node IS the list. Set the head directly.

`last = ft_lstlast(*lst);`
- Find the current last node.

`last->next = new;`
- Link the current last node to the new node. `new->next` is already NULL (from `ft_lstnew`).

---

## 6.7 ft_lstdelone

### Prototype and Purpose

```c
void ft_lstdelone(t_list *lst, void (*del)(void *));
```

Frees the node `lst` and calls `del` on its `content`. Does NOT free or modify other nodes in the list. `del` is a function pointer that knows how to free the content.

### Why a `del` function?

The list stores `void *` content — generic data. The list does not know whether the content is a `char *` (that needs `free`), an `int` (that does not need `free`), a struct, etc. The `del` function is supplied by the caller to handle content-specific cleanup.

### Implementation

```c
#include "libft.h"

void    ft_lstdelone(t_list *lst, void (*del)(void *))
{
    if (!lst || !del)
        return ;
    del(lst->content);
    free(lst);
}
```

**Line by line:**

`del(lst->content);`
- Call the provided deletion function on the content. If content is a `char *` that was `malloc`'d, `del` would be `free`.

`free(lst);`
- Free the node itself.

> **Warning:** Do NOT access `lst` after `free(lst)`. The memory is returned to the OS.

### Example Usage

```c
// If content is a malloc'd string:
void    del_string(void *content)
{
    free(content);
}

t_list *node = ft_lstnew(ft_strdup("Hello"));
ft_lstdelone(node, del_string);
// Both the string "Hello" and the node itself are freed.

// If content is a simple int (no free needed):
void    del_nothing(void *content)
{
    (void)content;  // Nothing to free
}
```

---

## 6.8 ft_lstclear

### Prototype and Purpose

```c
void ft_lstclear(t_list **lst, void (*del)(void *));
```

Deletes and frees **every node** of the list using `del` on each content. Sets `*lst` to NULL when done.

### Implementation

```c
#include "libft.h"

void    ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list  *current;
    t_list  *next;

    if (!lst || !del)
        return ;
    current = *lst;
    while (current)
    {
        next = current->next;
        ft_lstdelone(current, del);
        current = next;
    }
    *lst = NULL;
}
```

**Line by line:**

`current = *lst;`
- Start from the head.

`while (current)`
- While there is a node to process:

`next = current->next;`
- Save the next pointer BEFORE freeing the current node. After `ft_lstdelone`, we cannot read `current->next` — the memory is freed.

`ft_lstdelone(current, del);`
- Free this node and its content.

`current = next;`
- Move to the saved next node.

`*lst = NULL;`
- Set the head pointer to NULL — the list no longer exists.

### Diagram

```
List: [A] → [B] → [C] → NULL

Iteration 1:
  current = [A], next = [B]
  lstdelone([A]) → free
  current = [B]

Iteration 2:
  current = [B], next = [C]
  lstdelone([B]) → free
  current = [C]

Iteration 3:
  current = [C], next = NULL
  lstdelone([C]) → free
  current = NULL

Loop ends. *lst = NULL.
```

---

## 6.9 ft_lstiter

### Prototype and Purpose

```c
void ft_lstiter(t_list *lst, void (*f)(void *));
```

Applies function `f` to each node's `content`. Does not return anything. Does not modify the list structure.

### Implementation

```c
#include "libft.h"

void    ft_lstiter(t_list *lst, void (*f)(void *))
{
    if (!f)
        return ;
    while (lst)
    {
        f(lst->content);
        lst = lst->next;
    }
}
```

**Line by line:**

`while (lst)`
`    f(lst->content);`
`    lst = lst->next;`
- Walk the list, calling `f` on each node's content.

### Example Usage

```c
void    print_content(void *content)
{
    ft_putstr_fd((char *)content, 1);
    ft_putchar_fd('\n', 1);
}

// List: ["Alice"] → ["Bob"] → ["Charlie"]
ft_lstiter(head, print_content);
// Prints:
// Alice
// Bob
// Charlie
```

---

## 6.10 ft_lstmap

### Prototype and Purpose

```c
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
```

Creates a **new list** where each node's content is the result of applying `f` to the original content. If any allocation fails, clears the new list with `del` and returns NULL.

This is the most complex bonus function.

### Implementation

```c
#include "libft.h"

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *new_list;
    t_list  *new_node;
    void    *new_content;

    if (!lst || !f || !del)
        return (NULL);
    new_list = NULL;
    while (lst)
    {
        new_content = f(lst->content);
        new_node = ft_lstnew(new_content);
        if (!new_node)
        {
            del(new_content);
            ft_lstclear(&new_list, del);
            return (NULL);
        }
        ft_lstadd_back(&new_list, new_node);
        lst = lst->next;
    }
    return (new_list);
}
```

**Line by line:**

`new_list = NULL;`
- Start with an empty result list.

`while (lst)`
- Process each node in the original list.

`new_content = f(lst->content);`
- Apply the transformation function. The result might be a newly allocated string, for example.

`new_node = ft_lstnew(new_content);`
- Create a node for the transformed content.

`if (!new_node)`
- Allocation failure:

`del(new_content);`
- Free the content that `f` produced (since we cannot store it now).

`ft_lstclear(&new_list, del);`
- Free all nodes we already added to the new list.

`return (NULL);`
- Signal failure.

`ft_lstadd_back(&new_list, new_node);`
- Append the new node to the result list.

`lst = lst->next;`
- Move to the next node in the original list.

### Example Usage

```c
// Double every integer in the list
void    *double_int(void *content)
{
    int *n = malloc(sizeof(int));
    if (!n) return (NULL);
    *n = (*(int *)content) * 2;
    return (n);
}

void    del_int(void *content)
{
    free(content);
}

// Original list: [1] → [2] → [3]
// After lstmap with double_int: [2] → [4] → [6]
t_list *doubled = ft_lstmap(original, double_int, del_int);
```

### Diagram

```
Original: [*"hello"] → [*"world"] → NULL

f = uppercase function (returns new string)

Step 1: f("hello") → "HELLO", lstnew("HELLO")
        new_list: ["HELLO"] → NULL

Step 2: f("world") → "WORLD", lstnew("WORLD")
        new_list: ["HELLO"] → ["WORLD"] → NULL

Return new_list
(Original list is UNCHANGED)
```

---

### Chapter 6 Summary

| Function | Purpose | Modifies List? | Allocates? |
|---|---|---|---|
| `ft_lstnew` | Create a node | new node | YES |
| `ft_lstadd_front` | Insert at head | YES | no |
| `ft_lstsize` | Count nodes | no | no |
| `ft_lstlast` | Get last node | no | no |
| `ft_lstadd_back` | Insert at tail | YES | no |
| `ft_lstdelone` | Free one node | YES (removes it) | no |
| `ft_lstclear` | Free all nodes | YES (empties it) | no |
| `ft_lstiter` | Apply f to all content | no | no |
| `ft_lstmap` | Map f to create new list | no (creates new) | YES |

### Chapter 6 Exercises

1. Build a list of 5 integers using `ft_lstnew` and `ft_lstadd_back`, then print them with `ft_lstiter`
2. Create a `del` function for a list of `char *` content (strings), test with `ft_lstclear`
3. Use `ft_lstmap` to duplicate a list of strings, making each one uppercase

---

# CHAPTER 7: Testing Your Library

---

## 7.1 Your Test File Structure

Create a `test/` directory or a single `main.c`:

```c
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// ========== Test helpers ==========

static int  g_tests = 0;
static int  g_passed = 0;

void    assert_int(const char *test_name, int got, int expected)
{
    g_tests++;
    if (got == expected)
    {
        printf("[PASS] %s\n", test_name);
        g_passed++;
    }
    else
        printf("[FAIL] %s: got %d, expected %d\n", test_name, got, expected);
}

void    assert_str(const char *test_name, const char *got, const char *expected)
{
    g_tests++;
    if (got && expected && strcmp(got, expected) == 0)
    {
        printf("[PASS] %s\n", test_name);
        g_passed++;
    }
    else
        printf("[FAIL] %s: got \"%s\", expected \"%s\"\n",
               test_name, got ? got : "(null)", expected ? expected : "(null)");
}

void    assert_ptr(const char *test_name, void *got, void *expected)
{
    g_tests++;
    if (got == expected)
    {
        printf("[PASS] %s\n", test_name);
        g_passed++;
    }
    else
        printf("[FAIL] %s: pointers differ\n", test_name);
}

// ========== Individual test sections ==========

void    test_ft_strlen(void)
{
    printf("\n--- ft_strlen ---\n");
    assert_int("strlen empty",   ft_strlen(""),      strlen(""));
    assert_int("strlen hello",   ft_strlen("Hello"), strlen("Hello"));
    assert_int("strlen single",  ft_strlen("a"),     strlen("a"));
    assert_int("strlen spaces",  ft_strlen("  "),    strlen("  "));
}

void    test_ft_atoi(void)
{
    printf("\n--- ft_atoi ---\n");
    assert_int("atoi 0",        ft_atoi("0"),           atoi("0"));
    assert_int("atoi 42",       ft_atoi("42"),          atoi("42"));
    assert_int("atoi -42",      ft_atoi("-42"),         atoi("-42"));
    assert_int("atoi spaces",   ft_atoi("   42"),       atoi("   42"));
    assert_int("atoi +42",      ft_atoi("+42"),         atoi("+42"));
    assert_int("atoi suffix",   ft_atoi("42abc"),       atoi("42abc"));
}

int     main(void)
{
    test_ft_strlen();
    test_ft_atoi();
    // ... add all other tests

    printf("\n========================================\n");
    printf("Results: %d/%d tests passed\n", g_passed, g_tests);
    printf("========================================\n");
    return (g_passed != g_tests);
}
```

Compile:
```bash
cc -Wall -Wextra -Werror main.c libft.a -o test_libft
./test_libft
```

## 7.2 Testing Against the Real Functions

For Part 1 functions that are reimplementations, compare your output to the original:

```c
// Compare ft_memcpy vs memcpy:
void    test_ft_memcpy(void)
{
    char    dst1[20];
    char    dst2[20];

    printf("\n--- ft_memcpy ---\n");

    // Test 1: basic copy
    ft_memcpy(dst1, "Hello", 5);
    memcpy(dst2, "Hello", 5);
    dst1[5] = '\0';
    dst2[5] = '\0';
    assert_str("memcpy basic", dst1, dst2);

    // Test 2: zero bytes
    ft_memcpy(dst1, "Hello", 0);
    memcpy(dst2, "Hello", 0);
    // dst unchanged

    // Test 3: single byte
    ft_memcpy(dst1, "X", 1);
    memcpy(dst2, "X", 1);
    assert_int("memcpy single byte", dst1[0], dst2[0]);
}
```

## 7.3 Memory Leak Testing with Valgrind

After implementing all functions that allocate memory (`ft_strdup`, `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_lstnew`, `ft_lstmap`), run Valgrind:

```bash
# Install (Debian/Ubuntu)
sudo apt install valgrind

# Run
valgrind --leak-check=full --show-leak-kinds=all ./test_libft
```

**Expected clean output:**
```
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 42 allocs, 42 frees, 1,024 bytes allocated
==12345== All heap blocks were freed -- no leaks are possible
```

**If you see leaks:**
```
==12345== LEAK SUMMARY:
==12345==    definitely lost: 24 bytes in 1 blocks
```
- Check your test code — are you `free`-ing everything you allocated?
- Check your function — does it always free on failure paths?

## 7.4 Edge Cases to Always Test

```
┌────────────────────────────────────────────────────────┐
│                 UNIVERSAL EDGE CASES                   │
├────────────────────┬───────────────────────────────────┤
│ Empty string ""    │ Every string function              │
│ Single character   │ Every string function              │
│ n = 0              │ Every "n" function (memcpy, etc.)  │
│ INT_MAX / INT_MIN  │ ft_atoi, ft_itoa, ft_putnbr_fd    │
│ NULL content       │ ft_lstnew, ft_lstmap               │
│ All same delimiter │ ft_split(",,,,", ',')              │
│ Overlapping memory │ ft_memmove                         │
└────────────────────┴───────────────────────────────────┘
```

## 7.5 Recommended External Testers

The 42 community has built open-source test suites:

- **libft-unit-test** — classic, comprehensive
- **42TESTERS-LIBFT** — popular at many campuses
- **francinette** — all-in-one tester with Valgrind integration

```bash
# Install francinette
bash -c "$(curl -fsSL https://raw.githubusercontent.com/xicodomingues/francinette/master/bin/install.sh)"

# Run in your libft directory
francinette
```

---

# CHAPTER 8: Submission and Evaluation

---

## 8.1 Norminette Checks

Before submitting, run Norminette on every file:

```bash
norminette *.c libft.h Makefile
```

Common Norm errors to watch for:

| Error Code | Meaning | Fix |
|---|---|---|
| `DECL_ASSIGN_LINE` | Declaration and assignment on same line | Separate into two lines |
| `TOO_MANY_LINES` | Function > 25 lines | Refactor with helper function |
| `LINE_TOO_LONG` | Line > 80 chars | Break the line |
| `TOO_MANY_PARAMS` | > 5 parameters | Refactor |
| `FORBIDDEN_FUNC` | Calling a forbidden function | Use your own implementation |

## 8.2 What Evaluators Check

During peer evaluation, your evaluator will typically:

1. **Read your code** — they may ask you to explain any function
2. **Run their own tests** — or use a standard tester
3. **Check edge cases** — empty strings, NULL, INT_MIN
4. **Verify the Makefile** — `make`, `make clean`, `make fclean`, `make re`, `make bonus`
5. **Check for leaks** — possibly with Valgrind

**Common evaluation questions:**

- "What is the difference between `memcpy` and `memmove`?"
- "Why does `strlcat` return `strlen(dst) + strlen(src)` even when truncated?"
- "What is `size_t` and why do we use it?"
- "Why does `ft_atoi` handle `\t` and `\n` as whitespace?"
- "What is `void *` and why do `memset`, `memcpy`, and `calloc` use it?"
- "How does `ft_split` handle multiple consecutive delimiters?"
- "Why do the linked-list functions take `t_list **` instead of `t_list *`?"
- "What does the `del` function in `ft_lstclear` do and why is it needed?"

## 8.3 Submission Checklist

```
□ All 23 Part 1 functions implemented and compiling
□ All 11 Part 2 functions implemented and compiling
□ Makefile has all required rules (all, clean, fclean, re)
□ Norminette passes on all .c files and libft.h
□ No forbidden functions used (no strcmp, sprintf, printf, etc.)
□ All allocating functions handle malloc failure (return NULL)
□ For bonus: all 9 functions implemented, bonus rule in Makefile
□ git add, git commit, git push before the deadline
```

---

# CHAPTER 9: Beyond Libft

---

## 9.1 How Libft Connects to Future Projects

Libft is not an isolated exercise — it is the foundation of your 42 journey. Here is how it connects forward:

```
Libft
  │
  ├─► get_next_line    (uses ft_strlen, dynamic allocation pattern)
  │
  ├─► ft_printf        (uses ft_putchar_fd, ft_putnbr_fd, ft_itoa concepts)
  │
  ├─► Born2BeRoot      (no Libft, but deepens your Unix understanding)
  │
  ├─► push_swap        (uses linked lists, ft_atoi, ft_split)
  │
  ├─► pipex            (file descriptors, ft_split for parsing)
  │
  ├─► minishell        (uses almost everything)
  │
  └─► beyond...
```

## 9.2 get_next_line

**Core challenge:** Read a file one line at a time, across multiple calls, without losing characters.

**Libft concepts it uses:**
- `ft_strlen`, `ft_substr`, `ft_strjoin` (directly)
- Dynamic allocation and freeing pattern
- Buffer management

**Key insight from Libft:** Your `ft_strjoin` pattern — allocating a new string that combines two others — is exactly what `get_next_line` does repeatedly as it accumulates line content.

## 9.3 ft_printf

**Core challenge:** Implement `printf` with format strings (`%d`, `%s`, `%x`, etc.).

**Libft concepts it uses:**
- `ft_putchar_fd`, `ft_putstr_fd` for output
- `ft_itoa` logic for integer conversion
- `ft_strlen` for padding calculations
- Variadic arguments (`va_list`, `va_arg`, `va_end`) — new concept

## 9.4 Minishell

**Core challenge:** Build a working Unix shell that can execute commands, handle pipes, redirections, and environment variables.

**Libft concepts it uses:**
- `ft_split` for tokenizing input
- `ft_strjoin`, `ft_substr` for string manipulation
- Linked lists for command chains
- `ft_atoi` for signal numbers
- All the `put*_fd` functions for output to stderr

After minishell, you will understand why every function in Libft exists.

---

## Final Note

You now have everything you need to build a complete, correct, norm-compliant Libft. The functions build on each other — `ft_isalnum` uses `ft_isalpha` and `ft_isdigit`; `ft_strtrim` uses `ft_substr`; `ft_lstclear` uses `ft_lstdelone`. Build them in order, test each one before moving to the next.

The standard is not just correctness — it is clarity. Code that works but nobody can read is unfinished code. Every line in your Libft should be something you can explain out loud to your evaluator without hesitation.

Write it. Understand it. Own it.

---

## Appendix A: Complete Function Quick Reference

### Part 1: Libc Functions

| Function | Prototype | Returns | Free? |
|---|---|---|---|
| ft_isalpha | `int (int c)` | bool | — |
| ft_isdigit | `int (int c)` | bool | — |
| ft_isalnum | `int (int c)` | bool | — |
| ft_isascii | `int (int c)` | bool | — |
| ft_isprint | `int (int c)` | bool | — |
| ft_strlen | `size_t (const char *s)` | length | — |
| ft_memset | `void *(void *b, int c, size_t len)` | b | — |
| ft_bzero | `void (void *s, size_t n)` | void | — |
| ft_memcpy | `void *(void *dst, const void *src, size_t n)` | dst | — |
| ft_memmove | `void *(void *dst, const void *src, size_t len)` | dst | — |
| ft_strlcpy | `size_t (char *dst, const char *src, size_t dstsize)` | src len | — |
| ft_strlcat | `size_t (char *dst, const char *src, size_t dstsize)` | total len | — |
| ft_toupper | `int (int c)` | converted | — |
| ft_tolower | `int (int c)` | converted | — |
| ft_strchr | `char *(const char *s, int c)` | ptr or NULL | — |
| ft_strrchr | `char *(const char *s, int c)` | ptr or NULL | — |
| ft_strncmp | `int (const char *s1, const char *s2, size_t n)` | diff | — |
| ft_memchr | `void *(const void *s, int c, size_t n)` | ptr or NULL | — |
| ft_memcmp | `int (const void *s1, const void *s2, size_t n)` | diff | — |
| ft_strnstr | `char *(const char *h, const char *n, size_t len)` | ptr or NULL | — |
| ft_atoi | `int (const char *str)` | int | — |
| ft_calloc | `void *(size_t count, size_t size)` | ptr or NULL | YES |
| ft_strdup | `char *(const char *s1)` | ptr or NULL | YES |

### Part 2: Additional Functions

| Function | Prototype | Returns | Free? |
|---|---|---|---|
| ft_substr | `char *(char const *s, unsigned int start, size_t len)` | ptr or NULL | YES |
| ft_strjoin | `char *(char const *s1, char const *s2)` | ptr or NULL | YES |
| ft_strtrim | `char *(char const *s1, char const *set)` | ptr or NULL | YES |
| ft_split | `char **(char const *s, char c)` | array or NULL | YES |
| ft_itoa | `char *(int n)` | ptr or NULL | YES |
| ft_strmapi | `char *(char const *s, char (*f)(unsigned int, char))` | ptr or NULL | YES |
| ft_striteri | `void (char *s, void (*f)(unsigned int, char*))` | void | — |
| ft_putchar_fd | `void (char c, int fd)` | void | — |
| ft_putstr_fd | `void (char *s, int fd)` | void | — |
| ft_putendl_fd | `void (char *s, int fd)` | void | — |
| ft_putnbr_fd | `void (int n, int fd)` | void | — |

### Part 3: Bonus Linked-List Functions

| Function | Prototype | Returns | Free? |
|---|---|---|---|
| ft_lstnew | `t_list *(void *content)` | node or NULL | YES (node) |
| ft_lstadd_front | `void (t_list **lst, t_list *new)` | void | — |
| ft_lstsize | `int (t_list *lst)` | count | — |
| ft_lstlast | `t_list *(t_list *lst)` | node or NULL | — |
| ft_lstadd_back | `void (t_list **lst, t_list *new)` | void | — |
| ft_lstdelone | `void (t_list *lst, void (*del)(void*))` | void | frees node |
| ft_lstclear | `void (t_list **lst, void (*del)(void*))` | void | frees all |
| ft_lstiter | `void (t_list *lst, void (*f)(void*))` | void | — |
| ft_lstmap | `t_list *(t_list *lst, void *(*f)(void*), void (*del)(void*))` | list or NULL | YES (new list) |

---

## Appendix B: ASCII Table (Printable Range)

```
Dec  Chr  | Dec  Chr  | Dec  Chr  | Dec  Chr
----------------------------------------------
 32   SPC |  56   8   |  80   P   | 104   h
 33   !   |  57   9   |  81   Q   | 105   i
 34   "   |  58   :   |  82   R   | 106   j
 35   #   |  59   ;   |  83   S   | 107   k
 36   $   |  60   <   |  84   T   | 108   l
 37   %   |  61   =   |  85   U   | 109   m
 38   &   |  62   >   |  86   V   | 110   n
 39   '   |  63   ?   |  87   W   | 111   o
 40   (   |  64   @   |  88   X   | 112   p
 41   )   |  65   A   |  89   Y   | 113   q
 42   *   |  66   B   |  90   Z   | 114   r
 43   +   |  67   C   |  91   [   | 115   s
 44   ,   |  68   D   |  92   \   | 116   t
 45   -   |  69   E   |  93   ]   | 117   u
 46   .   |  70   F   |  94   ^   | 118   v
 47   /   |  71   G   |  95   _   | 119   w
 48   0   |  72   H   |  96   `   | 120   x
 49   1   |  73   I   |  97   a   | 121   y
 50   2   |  74   J   |  98   b   | 122   z
 51   3   |  75   K   |  99   c   | 123   {
 52   4   |  76   L   | 100   d   | 124   |
 53   5   |  77   M   | 101   e   | 125   }
 54   6   |  78   N   | 102   f   | 126   ~
 55   7   |  79   O   | 103   g   | 127  DEL
```

---

*End of "How to Make Libft: All Functions — Prerequisites and Practice"*

*Build methodically. Test everything. Understand every line.*
