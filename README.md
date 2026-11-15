*This project has been created as part of the 42 curriculum by jeanbarr.*

<h1 align="center">🖨️ ft_printf</h1>

## 📖 Description
<table> <tr> <td valign="middle" width="50%">
ft_printf recodes the <code>printf()</code> function from the C standard library and packages it into a static library <code>(libftprintf.a)</code>. The goal of the project is to learn how <strong>variadic functions</strong> work in C: a function that receives a format string and a variable number of arguments, and decides how to read each one from what the format string says.

</td> <td align="center" valign="middle" width="50%"> <img src="https://media0.giphy.com/media/v1.Y2lkPTc5MGI3NjExOWdwY3NnYXNsaHFuMnV2OGJ0YXdsaGF4ZDZ5dzAzZHdtMjduZTVlcyZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/qQnANZvBn9HiM/giphy.gif" alt="Printf animation" width="100%"> </td> </tr> </table>

The function follows the original prototype:

```c
int	ft_printf(const char *format, ...);
```

It writes the formatted text to the standard output and returns the **number of characters written**, like the original `printf`. As the subject requires, it does not implement the buffer management of the original.

| Conversion | Prints | Argument read |
|---|---|---|
| `%c` | A single character | `int` |
| `%s` | A string | `char *` |
| `%p` | A pointer, in hexadecimal | `void *` |
| `%d` | A signed decimal number | `int` |
| `%i` | A signed integer in base 10 | `int` |
| `%u` | An unsigned decimal number | `unsigned int` |
| `%x` | A number in hexadecimal, lowercase | `unsigned int` |
| `%X` | A number in hexadecimal, uppercase | `unsigned int` |
| `%%` | A percent sign | none |

---

## ⚙️ Instructions

**Requirements:** `cc`, `make` and `ar`.

| Command | Description |
|---|---|
| `make` | Builds `libftprintf.a` |
| `make clean` | Removes the object files |
| `make fclean` | Removes the object files and `libftprintf.a` |
| `make re` | Rebuilds everything from scratch |

Everything is compiled with `-Wall -Wextra -Werror`. The library is created with `ar`, at the root of the repository.

To use it, include `ft_printf.h` in your code and link your program with `libftprintf.a`. The library goes after your source file in the command:

```sh
make
cc -Wall -Wextra -Werror main.c libftprintf.a -o test
./test
```

A minimal `main.c`:

```c
#include "ft_printf.h"

int	main(void)
{
	int	len;

	len = ft_printf("Hello %s, number %d, hex %x\n", "world", 42, 255);
	ft_printf("The line above has %d characters\n", len);
	return (0);
}
```

---

## 🔧 Library description

ft_printf is a **static library** created with `ar` from the compiled object files. It does not depend on libft: the few helpers it needs are inside the project. The only system functions used are `write` and the `stdarg.h` macros (`va_start`, `va_arg`, `va_end`). It does not allocate memory.

### Files

| File | Role |
|---|---|
| `ft_printf.h` | Prototype of `ft_printf` and of the helper functions |
| `ft_printf.c` | The main loop over the format string and the conversion dispatcher |
| `printf_char.c` | Writes one character and returns the count (`%c`, `%%`, and normal text) |
| `printf_str.c` | Writes a string; prints `(null)` for a NULL pointer (`%s`) |
| `printf_int.c` | Writes a signed decimal number (`%d`, `%i`) |
| `printf_dec.c` | Writes an unsigned decimal number (`%u`) |
| `printf_hex.c` | Writes a number using a given string of digits (`%x`, `%X`, and the number in `%p`) |
| `printf_ptr.c` | Writes `0x` followed by the address in hexadecimal; prints `(nil)` for a NULL pointer (`%p`) |

### Algorithm and data structure

**The main loop.** `ft_printf` starts the argument list once with `va_start`, then walks the format string from left to right. A normal character is written directly. When it finds a `%` followed by a conversion character, it passes that character to the dispatcher, then continues after the conversion. At the end, it calls `va_end` once and returns the total.

**The dispatcher.** A small `static` function, `handler`, receives the conversion character and the argument list. It compares the character with each supported conversion in an `if` / `else if` chain. Each branch reads the correct type with `va_arg` and calls the helper that prints it, and the helper's return value is the number of characters written. There is no data structure besides the `va_list`.

*Why this choice:*
- The code is short and easy to read, and every conversion is in one visible place.
- **It is easy to extend.** To add a new conversion (for example, one that inserts a predefined string), you write one helper if needed and add one branch in `handler`. No other file has to change.
- The Norm limits a function to 25 lines, and the dispatcher has room for several more branches. If it grows past that limit, it can be split into two functions (for example, numbers and text), or replaced by a table that maps each conversion character to a function.

**The argument list.** It is passed to the dispatcher as a pointer (`va_list *`). That way, every `va_arg` call advances the same position in the argument list, which is the portable way to share it between functions.

**Printing numbers.** The digit helpers are recursive: each call first prints the leading digits and then its own, so the digits come out in the right order without a buffer or any memory allocation. `printf_int` works with a `long`, so the smallest `int` can be negated without overflow. `printf_hex` receives the string of digits as a parameter, so `%x` and `%X` share one function, and `%p` reuses it.

**Counting.** Every printing function returns how many characters it wrote, and the caller adds them up. There is no global variable.

**Special cases.** A NULL string prints `(null)`, and a NULL pointer with `%p` prints `(nil)`, which is the behavior of the original `printf` with glibc on Linux.

### Limitations

The bonus part is not implemented: flags (`-`, `0`, `.`, `#`, space, `+`) and field width are not supported.

### Testing

The project is meant to be compared against the original `printf`, comparing both the printed output and the return value. The cases worth testing are: `0`, the smallest `int`, an empty string, a NULL string, a NULL pointer, several conversions in the same call, and text before and after each conversion. Also run `norminette` on all files, and `valgrind` on the test program.

---

## 📚 Resources

- Manual pages: `man 3 printf`, `man 3 stdarg` and `man 2 write`.
- [GNU Make manual](https://www.gnu.org/software/make/manual/)
- [Valgrind documentation](https://valgrind.org/docs/manual/)
- ft_printf subject provided by the school

### How AI was used

AI was used as a learning and review tool during this project, for these tasks:

- **Understanding variadic functions:** explaining how `va_list`, `va_start`, `va_arg` and `va_end` work, and the common pitfalls (type promotion of `char`, and passing the argument list to other functions).
- **Design guidance:** discussing how to structure the project (main loop, dispatcher, helper functions) so that new conversions are easy to add, and how to organize the files.
- **Code review:** reviewing my `ft_printf` and its helper functions for edge cases, error handling, the Norm and `const`, and pointing out what to improve.
- **A small refactor:** AI provided an example of replacing the duplicated character-writing helpers in `printf_dec.c`, `printf_hex.c` and `printf_int.c` with calls to `printf_char`.
- **README:** drafting this file.

The structure of the project and the first version of the code were written by me.