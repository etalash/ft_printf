# ft_printf – 42 School Project

This repository contains my **ft_printf** project from 42 School. The goal of this project is to recreate a simplified version of the standard C `printf` function **without bonus features**.

---

## 📌 Overview

`ft_printf` is an introduction to **variadic functions**, formatted output, and low-level string manipulation in C. The project requires reproducing the behavior of `printf` while respecting strict constraints and handling multiple format specifiers correctly.

This project focuses on **precision, correctness, and understanding how formatted output works internally**.

---

## ⚙️ Supported Conversions (Mandatory Part)

The implementation supports the following format specifiers:

* `%c` – character
* `%s` – string
* `%p` – pointer address
* `%d` / `%i` – signed decimal integer
* `%u` – unsigned decimal integer
* `%x` – hexadecimal (lowercase)
* `%X` – hexadecimal (uppercase)
* `%%` – percent sign

No bonus flags, widths, or precision are implemented.

---

## 🧠 Key Concepts

* Variadic arguments using `stdarg.h`
* Parsing format strings
* Base conversion (decimal / hexadecimal)
* Writing to file descriptors
* Manual memory and output management

---

## 🚀 Usage

```c
ft_printf("Hello %s, value = %d\n", "world", 42);
```

The function behaves like `printf` for the supported specifiers and returns the number of characters printed.

---

## 🛠️ Build

```bash
git clone <repo-url>
cd ft_printf
make
```

To use it in another project:

```c
#include "ft_printf.h"
```

Compile with:

```bash
gcc main.c libftprintf.a
```

---

## 📌 Notes

* Fully compliant with the **mandatory part only** (no bonus)
* No memory leaks
* Handles NULL strings safely
* Matches the behavior of the standard `printf` for supported conversions

This project builds a strong foundation for later projects like **libft**, **pipex**, and **minishell**.

---

## 🧪 Language

* C — 96.1%
* Makefile — 3.9
